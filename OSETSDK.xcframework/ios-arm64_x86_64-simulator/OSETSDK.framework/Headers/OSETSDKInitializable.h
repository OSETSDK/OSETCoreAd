// OSETSDKInitializable.h
#import <Foundation/Foundation.h>
#import "OSETInitConfig.h"
#import "OSETAdError.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - SDK 初始化协议
/**
 SDK 初始化协议
 定义了第三方 SDK 的初始化方法
 */
@protocol OSETSDKInitializable <NSObject>

#pragma mark - 必需方法
/**
 初始化 SDK
 
 @param config 初始化配置
 @param completion 完成回调
 */
- (void)initializeWithConfig:(OSETInitConfig *)config
                  completion:(void(^)(BOOL success, OSETAdError * _Nullable error))completion;

/**
 检查 SDK 是否已初始化
 
 @return 是否已初始化
 */
- (BOOL)isInitialized;
/// Core 在初始化回调、客户端 setter 调用线程或主线程配置通知中调用；线程不固定。
/// 下发期间不持有 Core 的管理器锁，单次调用的 Objective-C 异常由 Core 隔离。
-(void)setDisableShake:(BOOL)disableShake;
- (NSString *)sdkVersion;
- (NSString *)adapterVersion;

@optional
/// 尽力应用支持的项目；允许不实现或空实现，不影响初始化/加载。
/// Core 在主线程、锁外调用。初始化前的设置由 initializeWithConfig: 消费 privacyConfig。
/// 不得修改摇一摇设置；该项继续走现有 setDisableShake:。
- (void)updatePrivacyConfig:(OSETPrivacyConfig *)privacyConfig;

@end

/// 仅隔离可选隐私设置的 Objective-C 异常，不包装渠道初始化/加载逻辑。
NS_INLINE void OSETPerformOptionalPrivacyUpdate(void (^update)(void)) {
    @try {
        if (update) update();
    } @catch (__unused NSException *exception) {
#if DEBUG
        NSLog(@"[OSETPrivacy] 可选隐私设置异常，已跳过");
#endif
    }
}

NS_INLINE void OSETUpdateAdapterPrivacyIfSupported(id<OSETSDKInitializable> _Nullable adapter,
                                                  OSETPrivacyConfig * _Nullable privacy) {
    if (!privacy) return;
    OSETPerformOptionalPrivacyUpdate(^{
        if ([adapter respondsToSelector:@selector(updatePrivacyConfig:)]) {
            [adapter updatePrivacyConfig:privacy];
        }
    });
}

NS_ASSUME_NONNULL_END
