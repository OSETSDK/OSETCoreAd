//
//  OSETAdConfig.h
//  YhsADSProject
//
//  Created by Shens on 5/1/2026.
//

// OSETAdConfig.h
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

/// 广告类型
typedef NS_ENUM(NSInteger, OSETAdType) {
    OSETAdTypeUnknown       = 0,    ///< 未知类型
    OSETAdTypeSplash        = 1,    ///< 开屏广告
    OSETAdTypeInterstitial  = 2,    ///< 插屏广告
    OSETAdTypeRewardedVideo = 3,    ///< 激励视频
    OSETAdTypeBanner        = 4,    ///< Banner广告
    OSETAdTypeNative        = 5,    ///< 原生广告
    OSETAdTypeNativeData        = 6,    ///< 原生广告
    OSETAdTypeFullScreenVideo = 7,  ///< 全屏视频
    OSETAdTypeDrawFeed      = 8,    ///< Draw流广告
};
#pragma mark - 竞价失败原因枚举
/**
 竞价失败原因
 */
typedef NS_ENUM(NSInteger, OSETBiddingFailureReason) {
    OSETBiddingFailureReasonUnknown = 0,           // 未知原因
    OSETBiddingFailureReasonNoFill = 1,            // 无广告填充
    OSETBiddingFailureReasonLowBid = 2,            // 出价过低
    OSETBiddingFailureReasonTimeout = 3,            // 竞价超时
    OSETBiddingFailureReasonNetworkError = 4,       // 网络错误
    OSETBiddingFailureReasonServerError = 5,        // 服务器错误
    OSETBiddingFailureReasonInvalidBid = 6,        // 无效出价
    OSETBiddingFailureReasonAdTypeMismatch = 7,     // 广告类型不匹配
    OSETBiddingFailureReasonNoBid = 8,             // 没有出价
    OSETBiddingFailureReasonWinPriceTooHigh = 9,    // 胜出价过高
    OSETBiddingFailureReasonCreativeRejected = 10,  // 创意被拒绝
    OSETBiddingFailureReasonOther = 100             // 其他原因
};
extern NSString *const OSETMediaAdLoadingExtECPM;
/// 广告请求配置
@interface OSETAdConfig : NSObject

/// 平台标识
@property (nonatomic, copy) NSString *platform;
@property (nonatomic, weak) UIViewController * rootViewController;

/// 广告位ID
@property (nonatomic, copy) NSString *slotId;
/// 用户 ID
@property (nonatomic, copy) NSString *userId;
/// 广告请求ID（必须唯一）
@property (nonatomic, copy) NSString *requestId;
@property (nonatomic, copy) NSString *biddingToken;

/// 
@property (nonatomic, assign) CGSize adSize;

/// 广告类型
@property (nonatomic, assign) OSETAdType adType;

/// 超时时间（秒），默认30秒
@property (nonatomic, assign) NSTimeInterval timeout;

/// 扩展参数
@property (nonatomic, copy, nullable) NSDictionary<NSString *, id> *extParams;

#pragma mark - 快速创建
/// 创建配置（自动生成requestId）
+ (instancetype)configWithPlatform:(NSString *)platform
                            slotId:(NSString *)slotId
                           adType:(OSETAdType)adType;

/// 创建配置（指定requestId）
+ (instancetype)configWithPlatform:(NSString *)platform
                            slotId:(NSString *)slotId
                           adType:(OSETAdType)adType
                         requestId:(nullable NSString *)requestId;

#pragma mark - 验证
- (BOOL)isValid;
- (nullable NSError *)validationError;

#pragma mark - 工具方法
/// 广告类型字符串
- (NSString *)adTypeString;

/// 广告类型描述
- (NSString *)adTypeDescription;

/// 生成请求ID
+ (NSString *)generateRequestId;
@end

NS_ASSUME_NONNULL_END
