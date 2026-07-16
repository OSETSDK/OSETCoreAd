//
//  OSETBaseAd.h
//  YhsADSProject
//
//  Created by Shens on 11/11/2024.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 竞价上报字段：requestId（
FOUNDATION_EXPORT NSString * const OSETBiddingInfoRequestIdKey;
/// 竞价上报字段：广告位 ID
FOUNDATION_EXPORT NSString * const OSETBiddingInfoAdSpotIdKey;
/// 竞价上报字段：竞胜渠道
FOUNDATION_EXPORT NSString * const OSETBiddingInfoBiddingNetworkKey;
/// 竞价上报字段：竞胜价格
FOUNDATION_EXPORT NSString * const OSETBiddingInfoBiddingPriceKey;
/// 竞价上报字段：竞败原因（对应 OSETBiddingFailureReason）
FOUNDATION_EXPORT NSString * const OSETBiddingInfoLossReasonKey;
/// 竞价上报字段：预留扩展字段，支持 NSString / NSNumber / NSDictionary / NSArray
FOUNDATION_EXPORT NSString * const OSETBiddingInfoExtraKey;

@interface OSETBaseAd : NSObject
@property (nonatomic, copy) NSString *biddingToken;

-(NSString *)getS2SInfo;
-(void)loadAdWithToken:(NSString *)token;
-(void)cacheAd;

/// 手动上报竞价成功。优先使用当前广告对象绑定的 Sort 补全字段；取不到 Sort 时仅上报传入字段。
- (void)reportBiddingWinWithInfo:(nullable NSDictionary *)info;

/// 手动上报竞价失败。优先使用当前广告对象绑定的 Sort 补全字段；取不到 Sort 时仅上报传入字段。
- (void)reportBiddingLossWithInfo:(nullable NSDictionary *)info;

/// 缓存路由的统一 slotId 契约:所有缓存读写(check/get)一律以此为 slot 键,禁止裸传 self.slotId/advert.advertId。默认取 slotId 属性,回退 advert.advertId。
- (NSString *)oset_slotId;
@end

NS_ASSUME_NONNULL_END
