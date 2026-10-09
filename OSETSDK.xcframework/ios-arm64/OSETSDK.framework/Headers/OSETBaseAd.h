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
/// 服务端竞价的加载入口：把宿主竞得的 token 交给该广告对象，结果通过 delegate 回调给出。
///
/// ⚠️ **本方法立即返回**，成功/失败回调恰好一次、**恒在主线程**送达，别依赖返回时广告已就绪。
/// 2026-09 起 token 的解密与 JSON 解析已移到后台并发池 —— 素材直投的回传 token 是 KB 级，
/// 1024 位密钥分块 RSA 解密在宿主调用线程（通常主线程）上要几百毫秒，是线上卡顿报告的实锤来源。
/// ⚠️ 因此**同一对象上的重复加载不再被主线程天然串行化**：本方法内部不挡重复调用，
/// 需要「一次只允许一个在飞」的语义请在调用侧自己做互斥。
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
