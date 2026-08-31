//
//  OSETBannerTemplateView.h
//  OSETSDK
//
//  Banner 自渲染统一模板。视觉基线对齐 API 奇点当前实际生效的纯图/全幅媒体形态。
//

#import <UIKit/UIKit.h>
#import "OSETBannerRenderData.h"
#import "OSETBannerRenderContext.h"

NS_ASSUME_NONNULL_BEGIN

@class OSETBannerTemplateView;

@protocol OSETBannerTemplateViewDelegate <NSObject>

@optional
/// 模板挂上 window 且拿到非零 bounds 时 active=YES；移出 window 时 active=NO。
/// 渠道的曝光注册必须等到 active=YES，在这之前注册多半不会生效。
- (void)bannerTemplateView:(OSETBannerTemplateView *)templateView didChangeActive:(BOOL)active;

/// 关闭键被点击，且当时没有任何渠道 Adapter 接管这个事件（兜底路径）。
/// 正常情况下关闭键由 Adapter 在 bind 阶段绑定，走渠道自己的关闭上报后再回调聚合。
- (void)bannerTemplateViewDidTapCloseWithoutHandler:(OSETBannerTemplateView *)templateView;

@end

/// 统一 Banner 模板。
///
/// 布局算法对齐 OSETAPIBannerView.layoutSubviews，两种形态都支持：
///
/// - 纯图/全幅媒体（无标题无描述）：
///   根 View 圆角 12 → 主图拉伸铺底 → 浅色毛玻璃 → 前景图 AspectFit 占满 → 广告标识 → 关闭键
/// - 图文（有标题或描述）：
///   左侧素材缩略图(190:132) + 右侧标题/描述 + CTA 胶囊按钮
///
/// 走哪种形态由 RenderData 里有没有 title/desc 决定，与素材是图片还是视频无关。
/// 摇一摇素材不改变形态：提示是个不带文案的圆形摇动图标，直径按素材区尺寸自适应。
///
/// 注：API 奇点在算完 hasMain/hasSub 后强制置为 NO，导致它自己实际只能显示纯图形态。
/// 本模板不做那个强制，图文分支真实启用。
///
/// 不复刻的部分：CTC、诱导关闭假按钮(fci_ps)、API 点击路由 —— 那些是 API 奇点
/// 特有的业务行为，不属于视觉基线。
///
/// 摇一摇只复刻「提示 UI」这一层：模板画提示，摇动检测和点击触发全在渠道 SDK 内部，
/// 核心不起传感器、不做阈值判断、也收不到触发回调。跟 API 奇点那条
/// yyy/nyn + OSETAPIMotionManager 的自建链完全无关。
@interface OSETBannerTemplateView : UIView

@property (nonatomic, weak) id<OSETBannerTemplateViewDelegate> delegate;

/// 渠道视频 View 挂这里。图片素材时隐藏。
@property (nonatomic, strong, readonly) UIView *mediaContainerView;

/// 渠道强制广告标识 View 挂这里。渠道只给了标识图时由模板自己画。
@property (nonatomic, strong, readonly) UIView *adMarkContainerView;

/// 摇一摇提示容器（不带文案的圆形图标）。RenderData.shakeEnabled 为 YES 且尺寸放得下时才可见。
/// 渠道有自己的摇一摇 View（如快手 rotateView）就在 bind 阶段挂进来，
/// 模板自绘的提示会自动让位；渠道只给标志位（如 QDA）时由模板自己画。
/// 不接受交互，也不会进可点击视图数组。
@property (nonatomic, strong, readonly) UIView *shakeContainerView;

/// 关闭键。归核心所有，永远不进可点击视图数组。
@property (nonatomic, strong, readonly) UIControl *closeControl;

/// CTA 按钮（"立即下载"等）。RenderData 有 callToAction 时才显示。
/// 它是 UIControl 会拦截触摸，必须由渠道注册为可点击视图，否则点了没反应。
@property (nonatomic, strong, readonly) UIControl *ctaControl;

/// 把素材装进模板。主线程调用。
- (void)applyRenderData:(OSETBannerRenderData *)data;

/// 生成给渠道 Adapter 的容器槽位契约。
- (OSETBannerRenderContext *)makeRenderContextWithRootViewController:(nullable UIViewController *)rootViewController
                                                      presentationId:(NSString *)presentationId;

/// 当前是否已经上屏（有 window 且 bounds 非零）。
- (BOOL)isRenderActive;

@end

NS_ASSUME_NONNULL_END
