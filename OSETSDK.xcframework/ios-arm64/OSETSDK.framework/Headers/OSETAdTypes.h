//
//  OSETAdTypes.h
//  OSETSDK
//
//  适配器可见的公共枚举。
//
//  从 OSETHeader.h 拆出来的原因：OSETAdManager.h 只需要 YhsLoadADType 一个枚举，
//  但 OSETHeader.h 是 460 行的内部头（OSETLog 宏、SDK 版本号、各渠道错误码宏……），
//  为了导出 OSETAdManager.h 而把整个内部头设成 Public 不可接受。
//
//  ⚠️ 这个头是**对外契约**，独立发布的渠道适配器直接依赖它。
//     加东西前想清楚是不是真的该让适配器看见；改已有符号等于破坏兼容。

#ifndef OSETAdTypes_h
#define OSETAdTypes_h

#import <Foundation/Foundation.h>

/// 广告类型。3、6 为已下线广告类型预留，其他值与已编译适配器保持一致。
typedef NS_ENUM(NSInteger, YhsLoadADType) {
    kYhsLoadADTypeSplash = 0,                 //开屏
    kYhsLoadADTypeBanner = 1,                 //banner
    kYhsLoadADTypeInterstitial = 2,           //插屏
    kYhsLoadADTypeRewardedVideo = 4,          //激励视频
    kYhsLoadADTypeNative = 5,                 //信息流
    kYhsLoadADTypeSuspend = 7,                //悬浮
    kYhsLoadADTypeInterstitialLandscape = 8,  //插横屏
    kYhsLoadADTypeNativeData = 9,             //自渲染
    kYhsLoadADTypeContentVideo = 10            //快手内容
};

#endif /* OSETAdTypes_h */
