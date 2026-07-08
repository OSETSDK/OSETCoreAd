//
//  OSETNativeAdRenderer.h
//  YhsADSProject
//
//  Created by Shens on 2025/6/10.
//

#import <UIKit/UIKit.h>
#import "OSETNativeDataAdObject.h"


NS_ASSUME_NONNULL_BEGIN

@class OSETNativeAdRenderer;

@protocol OSETNativeAdRendererDelegate <NSObject>

@optional
/**
 广告曝光回调
 */
- (void)OSETNativeAdRendererWillExpose:(OSETNativeAdRenderer *)renderer;

/**
 广告点击回调
 */
- (void)OSETNativeAdRendererDidClick:(OSETNativeAdRenderer *)renderer;

/**
 广告关闭回调
 */
- (void)OSETNativeAdRendererDidClose:(OSETNativeAdRenderer *)renderer;

/**
 广告详情页关闭回调
 */
- (void)OSETNativeAdRendererDetailViewClosed:(OSETNativeAdRenderer *)renderer;

@end

@interface OSETNativeAdRenderer : NSObject

/**
 绑定的数据对象
 */
@property (nonatomic, strong) OSETNativeDataAdObject *dataObject;

/**
 视频广告的媒体View，绑定数据对象后自动生成，可自定义布局
 */
@property (nonatomic, strong) UIView *mediaView;

@property (nonatomic, strong) UIView *shakeView;

/**
 广告渲染器回调对象
 */
@property (nonatomic, weak) id<OSETNativeAdRendererDelegate> delegate;

/**
 *  viewControllerForPresentingModalView
 *  详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *viewController;

/**
 检查广告可见性
 */
- (BOOL)checkVisibility;

#pragma mark - 容器视图注册
/**
 注册广告容器视图和广告数据对象
 这是第一步，必须先调用此方法设置容器和广告数据
 
 @param containerView 广告容器视图，广告内容将展示在此视图内
 @param dataObject 广告数据对象，必传字段
 @warning 调用此方法前请确保dataObject.isAdValid为YES
 */
- (void)registerContainerView:(UIView *)containerView
              withDataObject:(OSETNativeDataAdObject *)dataObject;

#pragma mark - 可点击视图注册
/**
 注册可点击的视图数组
 这是第二步，设置哪些视图可以响应广告点击事件
 
 @param clickableViews 可点击的视图数组，此数组内的广告元素才可以响应广告对应的点击事件
 @warning 需要在registerContainerView:withDataObject:之后调用
 */
- (void)registerClickableViews:(NSArray<UIView *> *)clickableViews;


#pragma mark - 关闭按钮注册
/**
 注册关闭按钮
 这是第三步，可选步骤，设置关闭按钮用于关闭广告
 
 @param closeView 关闭按钮视图，点击后会触发关闭回调并注销广告
 @warning 需要在registerContainerView:withDataObject:之后调用
 */
- (void)registerCloseView:(UIView *)closeView;

#pragma mark - 媒体视图绑定


#pragma mark - 注销方法
/**
 注销数据对象，释放所有资源
 当广告不再需要展示时调用，会清理所有注册的事件和视图
 */
- (void)unregisterDataObject;

@end

NS_ASSUME_NONNULL_END
