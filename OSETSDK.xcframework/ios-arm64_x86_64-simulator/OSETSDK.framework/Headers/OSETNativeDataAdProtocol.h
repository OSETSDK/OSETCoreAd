//
//  OSETNativeDataAdProtocol.h
//  YhsADSProject
//
//  Created by Shens on 13/1/2026.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OSETBaseAdProtocol.h"
NS_ASSUME_NONNULL_BEGIN

@protocol OSETNativeDataAdProtocol <OSETBaseAdProtocol>


@required
/// 广告标题
@property (nonatomic, copy) NSString * _Nullable title;
/// 广告详情描述
@property (nonatomic, copy) NSString * _Nullable desc;
/// app类型广告的广告商app图标，
@property (nonatomic, copy) NSString * _Nullable iconUrl;
/// logo 图标地址，缺省时由上层使用默认logo。
@property (nonatomic, copy) NSString * _Nullable logoUrl;
/// app 名称。
@property (nonatomic, copy) NSString * _Nullable appName;
/// 按钮文案，例如’下载/安装’
@property (nonatomic, copy) NSString * _Nullable callToAction;
/// 视频视图
@property (nonatomic, strong) UIView * _Nullable  mediaView;

/// 摇一摇/扭一扭提示视图，
@property (nonatomic, strong) UIView * _Nullable shakeView;

/// 图片/视频模式
@property (nonatomic,assign) BOOL isVideoAd;
/// 是否具备摇一摇/扭一扭交互能力。
@property (nonatomic,assign) BOOL isShake;

/// 原生自渲染视频URL，仅支持ks
@property (nonatomic, copy) NSString * _Nullable videoUrl;
/// 图片URL列表 【Optional，可能位nil】
///  @{@"url":@"素材图⽚url",@"width":@"素材图⽚宽度",@"height":@"素材图⽚⾼度"}
@property (nonatomic, copy) NSArray * _Nullable imageUrlList;

/// 绑定数据
- (void)refreshData;
/// 设置根视图 （不设置可能造成点击无反应）
- (void)setRootViewController:(UIViewController * _Nullable)viewController;
/// 在原生广告视图中注册可点击视图。
- (void)registerContainer:(UIView * _Nonnull)containerView withClickableViews:(NSArray<UIView *> * _Nonnull)clickableViews;

- (void)registerCloseView:(UIView *)closeView;

/// 销毁数据
- (void)unregisterDataObject;
//- (void)showInView:(OSETBaseView *)view ViewController:(UIViewController *)viewController;
//-(UIView *)getBgView;
@end

#pragma mark - native广告代理协议
/**
 native广告代理协议
 继承自 OSETBaseAdDelegate，增加了激励视频广告特有的事件回调
 */
@protocol OSETNativeDataAdAdapterDelegate <OSETBaseAdDelegate>

- (void)OSETAdapterAdRenderSuccess:(id<OSETNativeDataAdProtocol>)ad;

@optional

@end

NS_ASSUME_NONNULL_END
