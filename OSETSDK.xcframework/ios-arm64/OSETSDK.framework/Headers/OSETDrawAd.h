//
//  OSETDrawAd.h
//  YhsADSProject
//
//  Created by Shens on 24/10/2023.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol OSETDrawAdDelegate <NSObject>
@optional

/// 信息流加载成功
/// @param drawAdViews 信息流广告View数组
- (void)drawAdLoadSuccess:(NSArray *)drawAdViews;

/// 渲染成功
/// @param drawAdView view
- (void)drawAdRenderSuccess:(id)drawAdView;

/// 加载失败
/// @param drawAd 信息流实例
/// @param error 错误信息
- (void)drawAdFailedToLoad:(id)drawAd error:(NSError *)error;

/// 信息流渲染失败
/// @param drawAdView view
- (void)drawAdFailedToRender:(id)drawAdView;

/// 信息流点击事件
/// @param drawAdView view
- (void)drawAdDidClick:(id)drawAdView;

/// 信息流关闭事件
/// @param drawAdView view
- (void)drawAdDidClose:(id)drawAdView;

///视频完成播放
- (void)drawAdViewPlayerDidPlayFinish:(id)drawAd;
///视频开始播放
- (void)drawAdVideoDidStart:(id)drawAd;
///视频暂停播放`
- (void)drawAdVideoDidPause:(id)drawAd;

@end
NS_ASSUME_NONNULL_BEGIN

@interface OSETDrawAd : NSObject
@property (nonatomic,weak) id <OSETDrawAdDelegate> delegate;

/// 信息流初始化
/// @param slotId 广告位ID
/// @param size 广告尺寸
/// @param rootViewController  
- (instancetype)initWithSlotId:(NSString *)slotId size:(CGSize)size rootViewController:(UIViewController *)rootViewController;

/// 加载信息流
/// @param count 一次请求数量
- (void)loadAdData:(NSInteger)count;

@end

NS_ASSUME_NONNULL_END
