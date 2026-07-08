//
//  OSETBannerAdProtocol.h
//  YhsADSProject
//
//  Created by Shens on 7/1/2026.
//

#import <Foundation/Foundation.h>
#import "OSETBaseAdProtocol.h"
#import <UIKit/UIKit.h>
#import "OSETBaseView.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark -banner广告协议
/**
 banner广告协议
 定义了激励视频广告的特有方法
 */
@protocol OSETBannerAdProtocol <OSETBaseAdProtocol>

@required
- (void)showInView:(OSETBaseView *)view ViewController:(UIViewController *)viewController;
-(UIView *)getBgView;
@end

#pragma mark - 激励视频广告代理协议
/**
 banner广告代理协议
 继承自 OSETBaseAdDelegate，增加了激励视频广告特有的事件回调
 */
@protocol OSETBannerAdAdapterDelegate <OSETBaseAdDelegate>

@optional

@end

NS_ASSUME_NONNULL_END
