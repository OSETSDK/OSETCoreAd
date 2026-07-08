//
//  OSETNaiveAd.h
//  YhsADSProject
//
//  Created by 熊俊 on 2020/4/28.
//  Copyright © 2020 熊俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OSETBaseAd.h"
NS_ASSUME_NONNULL_BEGIN

@protocol OSETNativeAdDelegate <NSObject>
@optional

/// 信息流加载成功
/// @param nativeExpressViews 信息流广告View数组
- (void)nativeExpressAdLoadSuccessWithNative:(id)native nativeExpressViews:(NSArray *)nativeExpressViews;

/// 渲染成功
/// @param nativeExpressView view
- (void)nativeExpressAdRenderSuccess:(id)nativeExpressView;

/// 加载失败
/// @param nativeExpressAd 信息流实例
/// @param error 错误信息
- (void)nativeExpressAdFailedToLoad:(id)nativeExpressAd error:(NSError *)error;

/// 信息流渲染失败
/// @param nativeExpressView view
- (void)nativeExpressAdFailedToRender:(id)nativeExpressView;

/// 信息流点击事件
/// @param nativeExpressView view
- (void)nativeExpressAdDidClick:(id)nativeExpressView;

/// 信息流关闭事件
/// @param nativeExpressView view
- (void)nativeExpressAdDidClose:(id)nativeExpressView;


- (void)nativeExpressAdDidExposured:(id)nativeExpressView;

@end

@interface OSETNativeAd : OSETBaseAd

@property (nonatomic,weak) id <OSETNativeAdDelegate> delegate;
/**
 *  自动播放时，是否静音。默认 YES。
 */
@property (nonatomic, assign) BOOL videoMuted;
@property (nonatomic,strong) NSMutableArray *currentArray;
@property (nonatomic, weak)   UIViewController * viewController;

/// 信息流初始化
/// @param slotId 广告位ID
/// @param size 广告尺寸
- (instancetype)initWithSlotId:(NSString *)slotId size:(CGSize)size rootViewController:(UIViewController *)rootViewController;

/// 加载信息流
/// @param count 一次请求数量
- (void)loadAdData;


@end

NS_ASSUME_NONNULL_END
