//
//  OSETBannerRenderContext.h
//  OSETSDK
//
//  Banner 自渲染的容器槽位契约：告诉渠道 Adapter「把行为绑到哪里」。
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 模板暴露给渠道 Adapter 的语义槽位。
///
/// 它只回答"渠道的东西挂在哪"，不回答"展示什么"（那是 OSETBannerRenderData 的事）。
/// 这样模板内部换布局时，三个渠道 Adapter 一行都不用改。
///
/// 设计约束：
/// 1. 所有 View 槽位一律 weak。视图树的所有权归模板，Context 只是引用。
/// 2. 不提供 `@property (copy) NSArray<UIView *> *clickableViews`。
///    copy 一个 UIView 数组仍然是强持有，会把整棵模板子树拖住不释放，
///    配合渠道 SDK 内部对 container 的强引用，很容易出现 VC 退出后 View 不析构。
///    需要可点击视图时调用 -currentClickableViews 当场生成，用完即弃。
/// 3. 由模板创建，Adapter 不要自行构造。
@interface OSETBannerRenderContext : NSObject

/// 广告容器，即模板本身。渠道 registerContainer 时传它。
@property (nonatomic, weak, readonly, nullable) UIView *containerView;

/// 视频素材时，渠道把自己的播放 View 挂进来。核心不自建播放器。
@property (nonatomic, weak, readonly, nullable) UIView *mediaContainerView;

/// 渠道强制要求用自家标识 View 时（如快手的 relatedView.adLabel）挂进来。
@property (nonatomic, weak, readonly, nullable) UIView *adMarkContainerView;

/// 摇一摇提示容器。只在 RenderData.shakeEnabled 为 YES 时可见。
///
/// 两种用法：
/// - 渠道自带摇一摇 View（如快手 relatedView.rotateView）：bind 时挂进来，模板自绘的提示自动让位；
/// - 渠道只给标志位不给 View（如 QDA）：Adapter 什么都不用做，模板自己画提示。
///
/// ⚠️ 它永远不在 -currentClickableViews 里，也不接受交互（userInteractionEnabled = NO），
/// 摇动的检测与点击触发都在渠道 SDK 内部，核心只负责把提示画出来。
@property (nonatomic, weak, readonly, nullable) UIView *shakeContainerView;

/// 核心提供的关闭键。Adapter 给它绑事件，点击后回调 OSETAdapterAdDidClose:。
/// 注意它永远不在 -currentClickableViews 里，避免点关闭被渠道算成广告点击。
@property (nonatomic, weak, readonly, nullable) UIControl *closeControl;

/// 核心提供的 CTA 按钮（"立即下载"等）。图文形态下才可见。
/// 它是 UIControl，会拦截触摸不往容器冒泡，所以必须显式出现在 -currentClickableViews 里，
/// 否则用户点 CTA 不会触发渠道的点击上报。
@property (nonatomic, weak, readonly, nullable) UIControl *ctaControl;

/// 落地页弹出用。不设置会导致点击无反应。
@property (nonatomic, weak, readonly, nullable) UIViewController *rootViewController;

/// 模板最终采用的尺寸，非零。
@property (nonatomic, assign, readonly) CGSize resolvedSize;

/// 本次展示的唯一标识，用于日志定位和晚到回调比对。
@property (nonatomic, copy, readonly) NSString *presentationId;

/// 当前可注册为"可点击"的视图，调用当下由 weak 槽位推导，不要持有返回值。
/// 内容为容器本身，加上可见的媒体容器和 CTA 按钮；永远不含关闭键。
- (NSArray<UIView *> *)currentClickableViews;

#pragma mark - 仅模板内部使用

/// 由 OSETBannerTemplateView 调用，Adapter 不要自行构造。
- (instancetype)initWithContainerView:(UIView *)containerView
                   mediaContainerView:(nullable UIView *)mediaContainerView
                  adMarkContainerView:(nullable UIView *)adMarkContainerView
                   shakeContainerView:(nullable UIView *)shakeContainerView
                         closeControl:(nullable UIControl *)closeControl
                           ctaControl:(nullable UIControl *)ctaControl
                   rootViewController:(nullable UIViewController *)rootViewController
                         resolvedSize:(CGSize)resolvedSize
                       presentationId:(NSString *)presentationId;

@end

NS_ASSUME_NONNULL_END
