//
//  OSETSplashAd.h
//  YhsADSProject
//
//  Created by 熊俊 on 2020/4/27.
//  Copyright © 2020 熊俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OSETBaseAd.h"
NS_ASSUME_NONNULL_BEGIN

@protocol OSETSplashAdDelegate <NSObject>
@optional

/// 开屏加载成功
/// @param splashAd 开屏实例
/// @param slotId 广告位ID
- (void)splashDidReceiveSuccess:(id)splashAd slotId:(NSString *)slotId;

/// 开屏加载失败
- (void)splashLoadToFailed:(id)splashAd error:(NSError *)error;

- (void)splashAdExposured:(id)splashAd;
- (void)splashAdExposuredToFailed:(id)splashAd error:(NSError *)error;

/// 开屏点击
- (void)splashDidClick:(id)splashAd;

/// 开屏关闭
- (void)splashDidClose:(id)splashAd;
/// 开屏将要关闭
- (void)splashWillClose:(id)splashAd;
//关闭广告详情页（落地页）
- (void)splashCloseTarget:(id)splashAd;

@end

@interface OSETSplashAd : OSETBaseAd

@property (nonatomic,weak) id <OSETSplashAdDelegate> delegate;
@property(nonatomic,readonly,assign)NSInteger eCPM;
@property (nonatomic, strong)   UIView * bottomView;

@property (nonatomic, strong)   UIWindow * window;


/**
 *  开屏广告的背景图片   (仅部分渠道生效)
 *  可以设置背景图片作为开屏加载时的默认背景
 */
@property (nonatomic, strong) UIImage *backgroundImage;

/**
 *  开屏广告的背景色 (仅部分渠道生效)
 *  可以设置开屏图片来作为开屏加载时的默认图片
 */
@property (nonatomic, copy) UIColor *backgroundColor;

/// 开屏初始化
/// @param slotId 开屏广告位ID
/// @param window keyWindow
/// @param bottomView 底部logoView
- (instancetype)initWithSlotId:(NSString *)slotId
                        window:(UIWindow *)window
                    bottomView:(UIView *)bottomView;


/// 只加载
- (void)loadSplashAd;
//显示
///// 显示  - - 必须load成功 以后再调用show   否则无效
-(void)showSplashAd;

/**
 * 返回广告是否可展示
 */
- (BOOL)isAdValid;

@end

NS_ASSUME_NONNULL_END
