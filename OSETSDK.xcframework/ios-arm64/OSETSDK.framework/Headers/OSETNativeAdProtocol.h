//
//  OSETNativeAdProtocol.h
//  YhsADSProject
//
//  Created by Shens on 8/1/2026.
//

#import <Foundation/Foundation.h>
#import "OSETBaseAdProtocol.h"
#import <UIKit/UIKit.h>
#import "OSETBaseView.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark -native广告协议
/**
 native广告协议
 定义了激励视频广告的特有方法
 */
@protocol OSETNativeAdProtocol <OSETBaseAdProtocol>
- (void)showInView:(OSETBaseView *)view ViewController:(UIViewController *)viewController;
-(UIView *)getBgView;

@required
//- (void)showInView:(OSETBaseView *)view ViewController:(UIViewController *)viewController;
//-(UIView *)getBgView;
@end

#pragma mark - native广告代理协议
/**
 native广告代理协议
 继承自 OSETBaseAdDelegate，增加了激励视频广告特有的事件回调
 */
@protocol OSETNativeAdAdapterDelegate <OSETBaseAdDelegate>

- (void)OSETAdapterAdRenderSuccess:(id<OSETNativeAdProtocol>)ad;

@optional

@end

NS_ASSUME_NONNULL_END
