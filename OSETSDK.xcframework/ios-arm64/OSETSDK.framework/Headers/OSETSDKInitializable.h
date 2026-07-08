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
-(void)setDisableShake:(BOOL)disableShake;
- (NSString *)sdkVersion;
- (NSString *)adapterVersion;

@end

NS_ASSUME_NONNULL_END
