// OSETSplashAdProtocol.h
#import "OSETBaseAdProtocol.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 开屏广告协议
/**
 开屏广告协议
 定义了开屏广告的特有方法
 */
@protocol OSETSplashAdProtocol <OSETBaseAdProtocol>

@required
/**
 展示开屏广告
 
 @param window 展示广告的窗口
 @discussion 必须在广告加载成功后调用
 */
- (void)showInWindow:(UIWindow *)window;

@optional
/**
 设置底部 Logo 视图
 
 @param logoView 底部 Logo 视图
 */
- (void)setBottomLogoView:(nullable UIView *)logoView;

/**
 设置跳过倒计时
 
 @param countdown 跳过倒计时（秒）
 */
- (void)setSkipCountdown:(NSTimeInterval)countdown;

@end

#pragma mark - 开屏广告代理协议
/**
 开屏广告代理协议
 继承自 OSETBaseAdDelegate，增加了开屏广告特有的事件回调
 */
@protocol OSETSplashAdAdapterDelegate <OSETBaseAdDelegate>

@optional
/**
 开屏广告跳过回调
 
 @param splashAd 开屏广告对象
 */
- (void)splashAdDidSkip:(id<OSETSplashAdProtocol>)splashAd;

/**
 开屏广告倒计时结束回调
 
 @param splashAd 开屏广告对象
 */
- (void)splashAdTimeOver:(id<OSETSplashAdProtocol>)splashAd;

@end

NS_ASSUME_NONNULL_END
