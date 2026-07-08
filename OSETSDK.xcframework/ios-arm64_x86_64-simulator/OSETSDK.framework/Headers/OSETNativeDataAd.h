//
//  OSETNativeDataAd.h
//  YhsADSProject
//
//  Created by Shens on 22/5/2025.
//

#import "OSETBaseAd.h"
#import "OSETNativeDataAdObject.h"
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@protocol OSETNativeDataAdDelegate <NSObject>
@optional

/// 信息流加载成功
/// @param nativeDataObjects 信息流广告data数组
- (void)nativeDataAdLoadSuccessWithNative:(id)nativeDataAd nativeDataObjects:(NSArray<OSETNativeDataAdObject *> * _Nullable)nativeDataObjects;

/// 加载失败
/// @param nativeDataAd 信息流实例
/// @param error 错误信息
- (void)nativeDataAdFailedToLoad:(id)nativeDataAd error:(NSError *)error;



@end


@interface OSETNativeDataAd : OSETBaseAd

@property (nonatomic,weak) id <OSETNativeDataAdDelegate> delegate;
/**
 *  自动播放时，是否静音。默认 YES。
 */
@property (nonatomic, assign) BOOL videoMuted;
@property (nonatomic, weak)   UIViewController * viewController;

/// 信息流初始化
/// @param slotId 广告位ID
- (instancetype)initWithSlotId:(NSString *)slotId size:(CGSize)size rootViewController:(UIViewController *)rootViewController;
/// 加载信息流
- (void)loadAdData;


@end

NS_ASSUME_NONNULL_END
