// OSETInterstitialAdProtocol.h
#import "OSETBaseAdProtocol.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 插屏广告协议
/**
 插屏广告协议
 定义了插屏广告的特有方法
 */
@protocol OSETInterstitialAdProtocol <OSETBaseAdProtocol>

@required
/**
 展示插屏广告
 
 @param viewController 展示广告的视图控制器
 @discussion 必须在广告加载成功后调用
 */
- (void)showInViewController:(UIViewController *)viewController;

@end

#pragma mark - 插屏广告代理协议
/**
 插屏广告代理协议
 继承自 OSETBaseAdDelegate，增加了插屏广告特有的事件回调
 */
@protocol OSETInterstitialAdAdapterDelegate <OSETBaseAdDelegate>

@optional
/**
 插屏广告展示失败回调
 
 @param interstitialAd 插屏广告对象
 @param error 错误信息
 */
- (void)interstitialAd:(id<OSETInterstitialAdProtocol>)interstitialAd
  didShowFailedWithError:(OSETAdError *)error;

@end

NS_ASSUME_NONNULL_END
