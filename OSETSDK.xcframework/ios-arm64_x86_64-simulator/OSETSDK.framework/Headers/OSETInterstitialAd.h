//
//  OSETInterstitialAd.h
//  YhsADSProject
//
//  Created by 熊俊 on 2020/4/27.
//  Copyright © 2020 熊俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OSETBaseAd.h"
NS_ASSUME_NONNULL_BEGIN

@protocol OSETInterstitialAdDelegate <NSObject>
@optional

/// 插屏加载成功
/// @param interstitialAd 插屏实例
/// @param slotId 广告位ID
- (void)interstitialDidReceiveSuccess:(id)interstitialAd slotId:(NSString *)slotId;

/// 插屏加载失败
- (void)interstitialLoadToFailed:(id)interstitialAd error:(NSError *)error;

/// 插屏点击
- (void)interstitialDidClick:(id)interstitialAd;

/// 插屏关闭
- (void)interstitialDidClose:(id)interstitialAd;
/// 插屏关闭落地页
- (void)interstitialCloseTarget:(id)interstitialAd;
- (void)interstitialExposured:(id)interstitialAd;
@end

@interface OSETInterstitialAd : OSETBaseAd

@property (nonatomic,weak) id <OSETInterstitialAdDelegate> delegate;
@property(nonatomic,readonly,assign)NSInteger eCPM;
/**
 * 返回广告是否可展示 建议在展示广告之前判断
 */
- (BOOL)isAdValid;
/// 插屏初始化
/// @param slotId 广告位ID
- (instancetype)initWithSlotId:(NSString *)slotId;

/// 加载
- (void)loadInterstitialAdData;

/// 显示
/// @param rootViewController 当前控制器
- (void)showInterstitialFromRootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
