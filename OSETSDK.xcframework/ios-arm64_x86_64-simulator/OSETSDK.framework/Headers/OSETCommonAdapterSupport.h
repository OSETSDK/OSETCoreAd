//
//  OSETCommonAdapterSupport.h
//  OSETSDK
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OSETSDKInitializable.h"
#import "OSETAdError.h"
#import "OSETBaseAdProtocol.h"
#import "OSETRewardedVideoAdProtocol.h"
NS_ASSUME_NONNULL_BEGIN

NS_INLINE OSETAdError *OSETCommonAdapterError(NSInteger code, NSString *message) {
    return [OSETAdError errorWithCode:code message:message];
}

NS_INLINE OSETAdError *OSETCommonAdapterLoadError(NSError * _Nullable error) {
    NSError *resolvedError = error;
    if (!resolvedError) {
        resolvedError = [NSError errorWithDomain:@"OSETAdErrorDomain"
                                            code:-1
                                        userInfo:@{NSLocalizedDescriptionKey: @"未知错误"}];
    }
    NSString *errorMessage = resolvedError.localizedDescription ?: @"未知错误";
    return [OSETAdError errorWithCode:resolvedError.code
                              message:[NSString stringWithFormat:@"广告加载失败: %@", errorMessage]];
}

NS_INLINE NSInteger OSETCommonBidPrice(NSInteger price) {
    return MAX(price, 0);
}

NS_INLINE void OSETCommonNotifyLoadFailed(id<OSETBaseAdDelegate> _Nullable delegate,
                                          id<OSETBaseAdProtocol> ad,
                                          OSETAdError *error) {
    if ([delegate respondsToSelector:@selector(OSETAdapterAd:didLoadFailedWithError:)]) {
        [delegate OSETAdapterAd:ad didLoadFailedWithError:error];
    }
}

NS_INLINE void OSETCommonNotifyLoaded(id<OSETBaseAdDelegate> _Nullable delegate,
                                      id<OSETBaseAdProtocol> ad,
                                      NSInteger ecpm) {
    if ([delegate respondsToSelector:@selector(OSETAdapterAdDidLoad:withExt:)]) {
        NSDictionary *ext = ecpm > 0 ? @{OSETMediaAdLoadingExtECPM: @(ecpm)} : @{};
        [delegate OSETAdapterAdDidLoad:ad withExt:ext];
    }
}

NS_INLINE void OSETCommonNotifyShown(id<OSETBaseAdDelegate> _Nullable delegate,
                                     id<OSETBaseAdProtocol> ad) {
    if ([delegate respondsToSelector:@selector(OSETAdapterAdDidShow:)]) {
        [delegate OSETAdapterAdDidShow:ad];
    }
}

NS_INLINE void OSETCommonNotifyClicked(id<OSETBaseAdDelegate> _Nullable delegate,
                                       id<OSETBaseAdProtocol> ad) {
    if ([delegate respondsToSelector:@selector(OSETAdapterAdDidClick:)]) {
        [delegate OSETAdapterAdDidClick:ad];
    }
}

NS_INLINE void OSETCommonNotifyClosed(id<OSETBaseAdDelegate> _Nullable delegate,
                                      id<OSETBaseAdProtocol> ad) {
    if ([delegate respondsToSelector:@selector(OSETAdapterAdDidClose:)]) {
        [delegate OSETAdapterAdDidClose:ad];
    }
}

NS_INLINE void OSETCommonNotifyReward(id delegate, id ad) {
    if ([delegate respondsToSelector:@selector(OSETAdapterRewardedVideoAdRewared:)]) {
        [delegate OSETAdapterRewardedVideoAdRewared:ad];
    }
}

NS_INLINE void OSETCommonNotifyPlayStart(id delegate, id ad) {
    if ([delegate respondsToSelector:@selector(OSETAdapterRewardedVideoAdDidPlayStart:)]) {
        [delegate OSETAdapterRewardedVideoAdDidPlayStart:ad];
    }
}

NS_INLINE void OSETCommonNotifyPlayFinished(id delegate, id ad) {
    if ([delegate respondsToSelector:@selector(OSETAdapterRewardedVideoAdDidPlayFinished:)]) {
        [delegate OSETAdapterRewardedVideoAdDidPlayFinished:ad];
    }
}

NS_ASSUME_NONNULL_END
