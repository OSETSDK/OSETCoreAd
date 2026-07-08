//
//  ADSManager.h
//  YhsADSProject
//
//  Created by 熊俊 on 2019/10/29.
//  Copyright © 2019 熊俊. All rights reserved.
/*
 
 OSETSDK_Version  2.2.0

 iOS 9.0以上
 
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

//广告类型
typedef NS_ENUM(NSInteger, OSETLoadADType) {
    OSETLoadADTypeSplash,                 //开屏
    OSETLoadADTypeBanner,                 //banner
    OSETLoadADTypeInterstitial,           //插屏
    OSETLoadADTypeInterstitialLandscape,  //插横屏
    OSETLoadADTypeRewardedVideo,          //激励视频
    OSETLoadADTypeFullScreenVideo,        //全屏视频
    OSETLoadADTypeNative,                 //信息流
    OSETLoadADTypeDrawNative,             //Draw 信息流
    OSETLoadADTypeSuspend,                //悬浮
    OSETLoadADTypeContentVideo            //快手内容
};


@interface OSETManager : NSObject
@property (nonatomic, assign) BOOL disableShake;

@property (nonatomic, assign) BOOL isEnablePersonalAds;

+ (instancetype)shareInstance;

/**
SDK初始化
 
 @param publicId 初始化Id（appKey）
 */
+ (void)configure:(NSString *)publicId;

/// 获取聚合SDK版本号
+ (NSString *)version;

/// 打开日志模式
+ (void)openDebugLog;

//检查SDK是否初始化成功
+ (BOOL)checkConfigure;

/**
 SDK配置日志 用户唯一标识符 推荐设置
 
 @param uid  用户唯一标识符 。userid,手机号,加密字符串等。 此ID仅用于log日志追踪 
 */
+ (void)configureLogsWithUid:(NSString *)uid;

+(void)startCacheAdWihtType:(OSETLoadADType)type WithSlotId:(NSString *)slotId withUserId:(NSString *)userId;
+ (void)hideAlert;
@end

NS_ASSUME_NONNULL_END
