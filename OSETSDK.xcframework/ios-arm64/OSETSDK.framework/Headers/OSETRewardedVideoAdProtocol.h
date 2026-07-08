// OSETRewardedVideoAdProtocol.h
#import "OSETBaseAdProtocol.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 激励视频广告协议
/**
 激励视频广告协议
 定义了激励视频广告的特有方法
 */
@protocol OSETRewardedVideoAdProtocol <OSETBaseAdProtocol>

@required
/**
 展示激励视频广告
 
 @param viewController 展示广告的视图控制器
 @discussion 必须在广告加载成功后调用
 */
- (void)showInViewController:(UIViewController *)viewController;


@end

#pragma mark - 激励视频广告代理协议
/**
 激励视频广告代理协议
 继承自 OSETBaseAdDelegate，增加了激励视频广告特有的事件回调
 */
@protocol OSETRewardedVideoAdAdapterDelegate <OSETBaseAdDelegate>

@optional
/**
 激励视频广告奖励授予回调
 
 @param rewardedVideoAd 激励视频广告对象

 */
- (void)OSETAdapterRewardedVideoAdRewared:(id<OSETRewardedVideoAdProtocol>)rewardedVideoAd;

/**
 激励视频广告跳过回调
 
 @param rewardedVideoAd 激励视频广告对象
 */
- (void)OSETAdapterRewardedVideoAdDidSkip:(id<OSETRewardedVideoAdProtocol>)rewardedVideoAd;

/**
 激励视频广告播放完成回调
 
 @param rewardedVideoAd 激励视频广告对象
 */
- (void)OSETAdapterRewardedVideoAdDidPlayFinished:(id<OSETRewardedVideoAdProtocol>)rewardedVideoAd;


/**
 激励视频广告播放完成回调
 
 @param rewardedVideoAd 激励视频广告对象
 */
- (void)OSETAdapterRewardedVideoAdDidPlayStart:(id<OSETRewardedVideoAdProtocol>)rewardedVideoAd;


@end

NS_ASSUME_NONNULL_END
