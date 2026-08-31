//
//  OSETBannerAssetPrefetcher.h
//  OSETSDK
//
//  Banner 自渲染的图片预取。三个渠道 Adapter 共用。
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 自渲染 Banner 的图片预取工具。
///
/// 为什么需要它：自渲染的成功回调必须等到图片就绪才发出，否则展示时会先白一下。
/// 但底层 OSETImageLoader 是 API 奇点在用的共享组件，它没有调用级超时、没有取消句柄，
/// 而且走 SDWebImage 分支时不保证回调线程。直接用会让渠道 load 无限等下去。
///
/// 这里在它外面包一层：超时上限、单次回调保证、主线程回调。
/// 不修改 OSETImageLoader 本体 —— 那会波及 API 奇点的图片链路。
@interface OSETBannerAssetPrefetcher : NSObject

/// 预取并解码图片。
///
/// completion 一定会被调用且只调用一次，一定在主线程。
/// 超时后即使底层下载最终成功，也不再回调（那张图会留在缓存里，下次直接命中）。
///
/// @param url        图片地址
/// @param timeout    超时上限，<= 0 时用默认值 1.5s
/// @param completion 结果回调，image 为 nil 时 error 非空
+ (void)prefetchImageWithURL:(nullable NSURL *)url
                     timeout:(NSTimeInterval)timeout
                  completion:(void (^)(UIImage * _Nullable image, NSError * _Nullable error))completion;

/// 默认超时（秒）。
///
/// 这个值是填充率和首屏体验的平衡点：每个自渲染渠道的 load 都会多等这一轮网络，
/// 设太长会拉高渠道超时率、挤掉后面的瀑布流机会，设太短则图片经常取不到。
+ (NSTimeInterval)defaultTimeout;

@end

NS_ASSUME_NONNULL_END
