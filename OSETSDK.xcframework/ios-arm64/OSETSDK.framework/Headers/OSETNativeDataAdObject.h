//
//  OSETNativeDataAdObject.h
//  YhsADSProject
//
//  Created by Shens on 22/5/2025.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface OSETNativeDataAdObject : NSObject
/**
 *  广告是否有效，以下情况会返回NO，建议在展示广告之前判断，否则会影响计费或展示失败
 *  a.广告过期
 */
@property (nonatomic, readonly, getter=isAdValid) BOOL adValid;
/**
 广告标题
 */
@property (nonatomic, copy) NSString *title;

/**
 广告描述
 */
@property (nonatomic, copy) NSString *desc;

/**
 广告图Url,
 @{@"url":@"素材图⽚url",@"width":@"素材图⽚宽度",@"height":@"素材图⽚⾼度"}
 */
@property (nonatomic, copy) NSArray *imageList;
/**
 广告对应的按钮展示文案
 此字段可能为空 callToAction
 */
@property (nonatomic, copy) NSString *buttonText;

/**
 应用类广告App 图标Url
 */
@property (nonatomic, copy) NSString *appIconUrl;
/**
 应用类广告App 名称
 */
@property (nonatomic, copy) NSString *appName;

@property (nonatomic, assign) BOOL isVideoAd;
@property (nonatomic, assign) BOOL isShake;

/**
 广告 图标Url
 */
@property (nonatomic, copy) NSString * adIconUrl;
/**
 视频封面信息
 */
@property (nonatomic, copy) NSString *coverUrl;
@property (nonatomic, copy) NSString *coverWidth;
@property (nonatomic, copy) NSString *coverHeight;

@property (nonatomic, copy) NSString *appFeature;
@property (nonatomic, copy) NSString *appInfoUrl;
@property (nonatomic, copy) NSString *appVersion;
@property (nonatomic, copy) NSString *devName;
@property (nonatomic, copy) NSString *packageName;
@property (nonatomic, assign) NSInteger packageSize;
@property (nonatomic, copy) NSString *permissionInfo;
@property (nonatomic, copy) NSString *permissionsUrl;
@property (nonatomic, copy) NSString *privacyUrl;
@property (nonatomic, copy) NSString *updateTime;
@property(nonatomic,readonly,assign)NSInteger eCPM;


@property (nonatomic, assign) BOOL isSS;

@end

NS_ASSUME_NONNULL_END
