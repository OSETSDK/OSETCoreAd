//
//  OSETInitConfig.h
//  YhsADSProject
//
//  Created by Shens on 6/1/2026.
//

// OSETInitConfig.h
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Core 解析优先级后的不可变隐私快照。YES 表示允许；不包含旧 setDisableShake: 链路。
@interface OSETPrivacyConfig : NSObject <NSCopying>
@property (nonatomic, readonly) BOOL personalAdsEnabled;
@property (nonatomic, readonly) BOOL locationEnabled;
@property (nonatomic, readonly) BOOL ssidEnabled;
- (instancetype)initWithPersonalAdsEnabled:(BOOL)personalAdsEnabled
                          locationEnabled:(BOOL)locationEnabled
                              ssidEnabled:(BOOL)ssidEnabled NS_DESIGNATED_INITIALIZER;
/// 默认三项允许。
- (instancetype)init;
@end

/// SDK初始化配置
@interface OSETInitConfig : NSObject

/// 平台标识
@property (nonatomic, copy) NSString *platform;

/// 应用ID
@property (nonatomic, copy) NSString *appId;

/// 应用Token（某些平台需要）
@property (nonatomic, copy, nullable) NSString *token;

/// 是否调试模式
@property (nonatomic, assign) BOOL debugMode;

/// 超时时间（秒），默认30秒
@property (nonatomic, assign) NSTimeInterval timeout;

/// 扩展参数
@property (nonatomic, copy, nullable) NSDictionary<NSString *, id> *extParams;

/// 可选隐私快照；Core 在交给初始化适配器前填充。nil 表示未提供，保持渠道原行为。
@property (nonatomic, copy, nullable) OSETPrivacyConfig *privacyConfig;

#pragma mark - 快速创建
+ (instancetype)configWithPlatform:(NSString *)platform
                             appId:(NSString *)appId;

+ (instancetype)configWithPlatform:(NSString *)platform
                             appId:(NSString *)appId
                             token:(nullable NSString *)token;

#pragma mark - 验证
- (BOOL)isValid;
- (nullable NSError *)validationError;

@end

/// 新适配器兼容旧 Core：旧配置没有 privacyConfig getter 时返回 nil。
/// 使用内联函数，适配器不依赖旧 Core 不存在的新函数/类符号。
NS_INLINE OSETPrivacyConfig * _Nullable OSETPrivacyConfigFromInitConfig(OSETInitConfig * _Nullable config) {
    @try {
        if (![config respondsToSelector:@selector(privacyConfig)]) return nil;
        OSETPrivacyConfig *privacy = config.privacyConfig;
        if (![privacy respondsToSelector:@selector(personalAdsEnabled)] ||
            ![privacy respondsToSelector:@selector(locationEnabled)] ||
            ![privacy respondsToSelector:@selector(ssidEnabled)]) return nil;
        return privacy;
    } @catch (__unused NSException *exception) {
        return nil;
    }
}

NS_ASSUME_NONNULL_END
