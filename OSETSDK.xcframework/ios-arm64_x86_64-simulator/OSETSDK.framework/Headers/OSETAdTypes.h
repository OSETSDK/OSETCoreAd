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

/// 广告类型
typedef NS_ENUM(NSInteger, YhsLoadADType) {
    kYhsLoadADTypeSplash,                 //开屏
    kYhsLoadADTypeBanner,                 //banner
    kYhsLoadADTypeInterstitial,           //插屏
    kYhsLoadADTypeFullScreenVideo,        //全屏视频
    kYhsLoadADTypeRewardedVideo,          //激励视频
    kYhsLoadADTypeNative,                 //信息流
    kYhsLoadADTypeDrawNative,             //Draw 信息流
    kYhsLoadADTypeSuspend,                //悬浮
    kYhsLoadADTypeInterstitialLandscape,  //插横屏
    kYhsLoadADTypeNativeData,             //自渲染
    kYhsLoadADTypeContentVideo            //快手内容
};

#endif /* OSETAdTypes_h */
