//
//  OSETSDK.h
//  OSETSDK
//
//  Created by wuqihan on 2026/5/19.
//

#import <Foundation/Foundation.h>

//! Project version number for OSETSDK.
FOUNDATION_EXPORT double OSETSDKVersionNumber;

//! Project version string for OSETSDK.
FOUNDATION_EXPORT const unsigned char OSETSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <OSETSDK/PublicHeader.h>

#import <OSETSDK/OSETManager.h>
#import <OSETSDK/OSETBannerAd.h>
#import <OSETSDK/OSETSplashAd.h>
#import <OSETSDK/OSETInterstitialAd.h>
#import <OSETSDK/OSETInterstitialLandscapeAd.h>
#import <OSETSDK/OSETRewardVideoAd.h>
#import <OSETSDK/OSETFullscreenVideoAd.h>
#import <OSETSDK/OSETNativeAd.h>
#import <OSETSDK/OSETNativeDataAd.h>
#import <OSETSDK/OSETNativeDataAdObject.h>
#import <OSETSDK/OSETNativeAdRenderer.h>
#import <OSETSDK/OSETMediaView.h>
#import <OSETSDK/OSETShakeView.h>
#import <OSETSDK/OSETBaseView.h>
#import <OSETSDK/OSETDrawAd.h>

// Banner 自渲染统一模板
#import <OSETSDK/OSETBannerRenderData.h>
#import <OSETSDK/OSETBannerRenderContext.h>
#import <OSETSDK/OSETBannerTemplateView.h>
#import <OSETSDK/OSETBannerAssetPrefetcher.h>


#import <OSETSDK/OSETSDKInitializable.h>
#import <OSETSDK/OSETSplashAdProtocol.h>
#import <OSETSDK/OSETBannerAdProtocol.h>
#import <OSETSDK/OSETBannerCustomRenderAdProtocol.h>
#import <OSETSDK/OSETInterstitialAdProtocol.h>
#import <OSETSDK/OSETNativeAdProtocol.h>
#import <OSETSDK/OSETNativeDataAdProtocol.h>
#import <OSETSDK/OSETRewardedVideoAdProtocol.h>

#import <OSETSDK/OSETAdConfig.h>
#import <OSETSDK/OSETInitConfig.h>
#import <OSETSDK/OSETAdError.h>
#import <OSETSDK/OSETCommonAdapterSupport.h>

// 适配器 SPI —— 独立发布的渠道适配器（AdSetQDxAdapter 等）依赖这两个头。
// 改动前请确认不会破坏已发布适配器的兼容性。
#import <OSETSDK/OSETAdTypes.h>
#import <OSETSDK/OSETAdManager.h>
