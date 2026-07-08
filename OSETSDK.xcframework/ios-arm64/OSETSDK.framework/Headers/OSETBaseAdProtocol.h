// OSETBaseAdProtocol.h
#import <Foundation/Foundation.h>
#import "OSETAdConfig.h"
#import "OSETAdError.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 广告基类协议
/**
 广告基类协议
 所有广告类型的基类协议，定义了广告的通用方法
 */
@protocol OSETBaseAdProtocol <NSObject>

#pragma mark - 必需方法
/**
 加载广告
 
 @param config 广告配置
 */
- (void)loadAdWithConfig:(OSETAdConfig *)config;

/**
 检查广告是否有效
 
 @return 是否已加载
 */
- (BOOL)isAdReady;

/**
 获取广告配置
 
 @return 广告配置
 */
- (OSETAdConfig *)adConfig;

/// 设置代理（用方法代替属性）
- (void)setAdapterDelegate:(id)delegate;



#pragma mark - 可选方法
@optional
///获取唯一ID
-(NSString *)getParentAdId;
/**
 销毁广告资源
 */
- (void)destroy;

/**
 设置调试模式
 
 @param debugMode 是否开启调试模式
 */
- (void)setDebugMode:(BOOL)debugMode;

/**
 设置超时时间
 
 @param timeout 超时时间（秒）
 */
- (void)setTimeout:(NSTimeInterval)timeout;

-(NSDictionary *)getBiddingTokenWithSlotId:(NSString *)slotId;

#pragma mark - 竞价上报
/**
 创建竞价成功结果
 
 @param winPrice 胜出价格（出价价格）
 @param secondPrice 二价（实际扣费价格）
 */
- (void)successResultWithWinPrice:(NSInteger)winPrice
                              secondPrice:(NSInteger)secondPrice;

/**
 创建竞价失败结果
 
 @param reason 失败原因
 @param winnerAdNetwork 胜出方标识
 @param winnerPrice 胜出方价格
 */
- (void)failureResultWithReason:(OSETBiddingFailureReason)reason
                       winnerAdNetwork:(nullable NSString *)winnerAdNetwork
                          winnerPrice:(NSInteger)winnerPrice;

@end

#pragma mark - 广告代理基类协议
/**
 广告代理基类协议
 所有广告代理的基类协议，定义了广告的通用事件回调
 */
@protocol OSETBaseAdDelegate <NSObject>

@optional
#pragma mark - 广告生命周期
/**
 广告加载成功回调
 
 @param ad 广告适配器
 */
- (void)OSETAdapterAdDidLoad:(id<OSETBaseAdProtocol>)ad withExt:(NSDictionary *)ext;

/**
 广告加载失败回调
 
 @param ad 广告适配器
 @param error 错误信息
 */
- (void)OSETAdapterAd:(id<OSETBaseAdProtocol>)ad didLoadFailedWithError:(OSETAdError *)error;

/**
 广告即将展示回调
 
 @param ad 广告适配器
 */
- (void)OSETAdapterAdWillShow:(id<OSETBaseAdProtocol>)ad;

/**
 广告已展示回调
 
 @param ad 广告适配器
 */
- (void)OSETAdapterAdDidShow:(id<OSETBaseAdProtocol>)ad;

/**
 广告被点击回调
 
 @param ad 广告适配器
 */
- (void)OSETAdapterAdDidClick:(id<OSETBaseAdProtocol>)ad;

/**
 广告即将关闭回调
 
 @param ad 广告适配器
 */
- (void)OSETAdapterAdWillClose:(id<OSETBaseAdProtocol>)ad;

/**
 广告已关闭回调
 
 @param ad 广告适配器
 */
- (void)OSETAdapterAdDidClose:(id<OSETBaseAdProtocol>)ad;

@end

NS_ASSUME_NONNULL_END
