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
//#import "OSETHeader.h"
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

/// 构造脱敏的展示失败错误。只提取整数错误码，不透传原始 NSError 的 domain/message/userInfo。
NS_INLINE OSETAdError *OSETCommonAdapterShowError(NSError * _Nullable error,
                                                  NSInteger fallbackCode,
                                                  NSString * _Nullable message) {
    NSInteger code = fallbackCode;
    if ([error isKindOfClass:[NSError class]] && error.code != 0) {
        code = error.code;
    }
    return [OSETAdError errorWithCode:code message:(message ?: @"广告展示失败")];
}

/// 通知接收方（Load 层）展示失败。只做 selector 检查，接收方不支持则静默丢弃。
NS_INLINE void OSETCommonNotifyShowFailed(id<OSETBaseAdDelegate> _Nullable delegate,
                                          id<OSETBaseAdProtocol> ad,
                                          OSETAdError *error) {
    if ([delegate respondsToSelector:@selector(OSETAdapterAd:didShowFailedWithError:)]) {
        [delegate OSETAdapterAd:ad didShowFailedWithError:error];
    }
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
