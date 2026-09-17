// OSETAdManager.h
#import <Foundation/Foundation.h>
#import "OSETInitConfig.h"
#import "OSETAdConfig.h"
#import "OSETSplashAdProtocol.h"
#import "OSETInterstitialAdProtocol.h"
#import "OSETRewardedVideoAdProtocol.h"
#import "OSETBannerAdProtocol.h"
#import "OSETSDKInitializable.h"
#import "OSETNativeAdProtocol.h"
#import "OSETNativeDataAdProtocol.h"

// 只需要 YhsLoadADType；不要把内部 OSETHeader.h 作为公共依赖导出。
#import "OSETAdTypes.h"


NS_ASSUME_NONNULL_BEGIN

@class OSETAdError;
extern NSString *const OSETSDKIntKeyString;
extern NSString *const OSETAdTypeSplashKeyString;
extern NSString *const OSETAdTypeInterstitialKeyString;
extern NSString *const OSETAdTypeRewardedVideoKeyString;
extern NSString *const OSETAdTypeBannerKeyString;
extern NSString *const OSETAdTypeDrawNativeKeyString;
extern NSString *const OSETAdTypeNativeKeyString;
extern NSString *const OSETAdTypeNativeDataKeyString;
extern NSString *const OSETAdTypeFullScreenVideoKeyString;
extern NSString *const OSETAdTypeContentVideoKeyString;
/**
 广告管理器
 统一管理广告 SDK 的初始化和广告实例创建
 */
@interface OSETAdManager : NSObject

#pragma mark - 单例
/// 广告管理器单例
+ (instancetype)sharedManager;

#pragma mark - SDK 初始化
/**
 初始化广告 SDK
 
 @param config 初始化配置
 @param completion 完成回调
 */
- (void)initializeWithConfig:(OSETInitConfig *)config
                  completion:(void(^)(BOOL success, OSETAdError * _Nullable error))completion;

/**
 记录平台最近一次可用的初始化配置

 @param config 初始化配置
 */
- (void)cacheLatestInitConfig:(OSETInitConfig *)config;

/**
 获取平台最近一次可用的初始化配置

 @param platform 平台标识符
 @return 初始化配置
 */
- (nullable OSETInitConfig *)latestInitConfigForPlatform:(NSString *)platform;

#pragma mark - 广告实例创建
/**
 创建开屏广告适配器实例
 
 @param config 广告配置
 @return 开屏广告适配器实例，失败返回 nil
 */
- (nullable id<OSETSplashAdProtocol>)createSplashAdWithConfig:(OSETAdConfig *)config;

/**
 创建插屏广告适配器实例
 
 @param config 广告配置
 @return 插屏广告适配器实例，失败返回 nil
 */
- (nullable id<OSETInterstitialAdProtocol>)createInterstitialAdWithConfig:(OSETAdConfig *)config;

/**
 创建激励视频广告适配器实例
 
 @param config 广告配置
 @return 激励视频广告适配器实例，失败返回 nil
 */
- (nullable id<OSETRewardedVideoAdProtocol>)createRewardedVideoAdWithConfig:(OSETAdConfig *)config;


/**
 创建banner广告适配器实例
 
 @param config 广告配置
 @return banner广告适配器实例，失败返回 nil
 */
- (nullable id<OSETBannerAdProtocol>)createBannerAdWithConfig:(OSETAdConfig *)config;


/**
 创建NativeAd广告适配器实例
 
 @param config 广告配置
 @return banner广告适配器实例，失败返回 nil
 */
- (nullable id<OSETNativeAdProtocol>)createNativeAdWithConfig:(OSETAdConfig *)config;


/**
 创建NativeData广告适配器实例
 
 @param config 广告配置
 @return banner广告适配器实例，失败返回 nil
 */
- (nullable id<OSETNativeDataAdProtocol>)createNativeDataAdWithConfig:(OSETAdConfig *)config;

#pragma mark - 查询
/**
 获取所有可用的平台
 
 @return 平台标识符数组
 */
- (NSArray<NSString *> *)availablePlatforms;



/**
 检查平台是否已初始化
 
 @param platform 平台标识符
 @return YES:已初始化, NO:未初始化
 */
- (BOOL)isPlatformInitialized:(NSString *)platform;
/**
 检查平台是否已初始化 且支持广告类型
 
 @param platform 平台标识符
 @return YES:已初始化, 且支持广告类型
 */
- (BOOL)isPlatformInitialized:(NSString *)platform withAdType:(YhsLoadADType)adType;


/**
 根据标识符获取适配器
 
 @param platform 平台标识符
 @return 初始化适配器对象
 */
- (id<OSETSDKInitializable>)platformInitialized:(NSString *)platform;


#pragma mark - 配置
/**
 配置平台到适配器的映射
 
 @param mappings 映射字典
 @discussion 格式: @{@"平台标识": @{@"广告类型": @"适配器类名"}}
 示例: @{@"adsetqd": @{@"splash": @"AdSetQDASplashAdapter"}}
 */
+ (void)configureAdapterMappings:(NSDictionary<NSString *, NSDictionary<NSString *, NSString *> *> *)mappings;

@end

NS_ASSUME_NONNULL_END
