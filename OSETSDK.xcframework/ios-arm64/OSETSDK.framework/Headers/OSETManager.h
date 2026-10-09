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
/// 客户端配置，默认 NO（允许摇一摇/扭一扭）。建议 configure: 前设置。
@property (nonatomic, assign) BOOL disableShake;

/// 客户端个性化广告配置，默认 YES；API 奇点用于控制 IDFA 采集和输出。
@property (nonatomic, assign) BOOL isEnablePersonalAds;

/// API 奇点经纬度采集/输出控制，默认 YES。建议 configure: 前设置。
/// 关闭后后续取值返回 0，重新开启异步获取。SDK 不主动申请系统定位权限。
@property (nonatomic, assign) BOOL isEnableLocation;
/// API 奇点 SSID 采集/输出控制，默认 YES。建议 configure: 前设置。
/// 关闭后后续取值返回空串，重新开启异步获取。已生成或发出的请求不追溯修改。
@property (nonatomic, assign) BOOL isEnableSSID;

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


@end

NS_ASSUME_NONNULL_END
