//
//  OSETAdError.h
//  YhsADSProject
//
//  Created by Shens on 5/1/2026.
//
// OSETAdError.h
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 广告错误码
typedef NS_ENUM(NSInteger, OSETAdErrorCode) {
    // 通用错误
    OSETAdErrorUnknown           = 0,
    OSETAdErrorNetwork           = 1001,
    OSETAdErrorNoAd              = 1002,
    OSETAdErrorTimeout           = 1003,
    OSETAdErrorInvalidParameter  = 1004,
    OSETAdErrorConfigInvalid     = 1005,
};

/// 广告错误类
@interface OSETAdError : NSError

/// 快速创建
+ (instancetype)errorWithCode:(NSInteger)code
                      message:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
