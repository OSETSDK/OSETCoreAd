//
//  OSETInitConfig.h
//  YhsADSProject
//
//  Created by Shens on 6/1/2026.
//

// OSETInitConfig.h
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// SDK初始化配置
@interface OSETInitConfig : NSObject

/// 平台标识
@property (nonatomic, copy) NSString *platform;

/// 应用ID
@property (nonatomic, copy) NSString *appId;

/// 应用Token（某些平台需要）
@property (nonatomic, copy, nullable) NSString *token;

/// 是否调试模式
@property (nonatomic, assign) BOOL debugMode;

/// 超时时间（秒），默认30秒
@property (nonatomic, assign) NSTimeInterval timeout;

/// 扩展参数
@property (nonatomic, copy, nullable) NSDictionary<NSString *, id> *extParams;

#pragma mark - 快速创建
+ (instancetype)configWithPlatform:(NSString *)platform
                             appId:(NSString *)appId;

+ (instancetype)configWithPlatform:(NSString *)platform
                             appId:(NSString *)appId
                             token:(nullable NSString *)token;

#pragma mark - 验证
- (BOOL)isValid;
- (nullable NSError *)validationError;

@end

NS_ASSUME_NONNULL_END
