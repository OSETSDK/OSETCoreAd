//
//  OSETRewardFullscreenAd.h
//  YhsADSProject
//
//  Created by 熊俊 on 2020/4/27.
//  Copyright © 2020 熊俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OSETBaseAd.h"
NS_ASSUME_NONNULL_BEGIN

@protocol OSETFullscreenVideoAdDelegate <NSObject>
@optional

/// 全屏视频加载成功
/// @param fullscreenVideoAd 全屏视频实例
/// @param slotId 广告位ID
- (void)fullscreenVideoDidReceiveSuccess:(id)fullscreenVideoAd slotId:(NSString *)slotId;

/// 全屏视频加载失败
- (void)fullscreenVideoLoadToFailed:(id)fullscreenVideoAd error:(NSError *)error;

/// 全屏视频点击
- (void)fullscreenVideoDidClick:(id)fullscreenVideoAd;

/// 全屏视频关闭
- (void)fullscreenVideoDidClose:(id)fullscreenVideoAd;
- (void)fulllscreenVideoPlayEnd:(id)fullscreenVideoAd;
- (void)fulllscreenVideoPlayStart:(id)fullscreenVideoAd;
@end

@interface OSETFullscreenVideoAd : OSETBaseAd

@property (nonatomic,weak) id <OSETFullscreenVideoAdDelegate> delegate;
@property(nonatomic,readonly,assign)NSInteger eCPM;
/**
 * 返回广告是否可展示 建议在展示广告之前判断
 */
- (BOOL)isAdValid;
/// 全屏视频初始化
/// @param slotId 广告位ID
- (instancetype)initWithSlotId:(NSString *)slotId;

/// 加载
- (void)loadAdData;

/// 显示
/// @param rootViewController 当前控制器
- (void)showFromRootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
