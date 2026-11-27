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

/// 广告类型。5、7 为已下线广告类型预留。
typedef NS_ENUM(NSInteger, OSETLoadADType) {
    OSETLoadADTypeSplash = 0,                 //开屏
    OSETLoadADTypeBanner = 1,                 //banner
    OSETLoadADTypeInterstitial = 2,           //插屏
    OSETLoadADTypeInterstitialLandscape = 3,  //插横屏
    OSETLoadADTypeRewardedVideo = 4,          //激励视频
    OSETLoadADTypeNative = 6,                 //信息流
    OSETLoadADTypeSuspend = 8,                //悬浮
    OSETLoadADTypeContentVideo = 9            //快手内容
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

#if DEBUG
/// 仅 Debug 可选测试环境；默认正式。须在任何 SDK 配置/缓存使用前设置，冻结后改变取值返回 NO。
/// 测试环境仅影响初始化、排序和奇点 ADX 请求；Demo 选择在下次冷启动时下发。
+ (BOOL)setUseTestEnvironment:(BOOL)enabled;

/// 返回本次进程实际使用的环境，不读取或修改 Demo 的下次启动偏好。
+ (BOOL)isUsingTestEnvironment;
#endif

/// 获取聚合SDK版本号
+ (NSString *)version;

/// 打开日志模式
+ (void)openDebugLog;

/// 返回当前进程按 logstore 汇总的阿里云日志投递状态。该调用不启动 Producer 或网络请求。
/// queueDropped 统计队列满时丢弃的事件，addLogResults 按 Producer 返回码计数。
/// sendResults 按批次回调的返回码计数，可包含重试，并提供最近一次 SLS 请求 ID。
+ (NSDictionary<NSString *, NSDictionary *> *)logDeliveryStatistics;

//检查SDK是否初始化成功
+ (BOOL)checkConfigure;

/**
 SDK配置日志 用户唯一标识符 推荐设置
 
 @param uid  用户唯一标识符 。userid,手机号,加密字符串等。 此ID仅用于log日志追踪 
 */
+ (void)configureLogsWithUid:(NSString *)uid;


@end

NS_ASSUME_NONNULL_END
