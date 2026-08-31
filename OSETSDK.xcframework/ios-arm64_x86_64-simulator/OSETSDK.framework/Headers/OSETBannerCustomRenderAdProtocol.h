//
//  OSETBannerCustomRenderAdProtocol.h
//  OSETSDK
//
//  Banner 自渲染协议：渠道出素材和行为，核心出 UI。
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OSETBannerAdProtocol.h"
#import "OSETBannerRenderData.h"
#import "OSETBannerRenderContext.h"

NS_ASSUME_NONNULL_BEGIN

/// 实现本协议的 Banner Adapter 走核心统一模板，不再展示渠道自己的模板 View。
///
/// 分工：
/// - 核心：模板布局、图片显示、关闭键、attach 时机判定；不认识任何渠道类型。
/// - Adapter：渠道原始对象、素材映射、媒体/标识 View、注册注销、竞价；不碰模板内部控件。
///
/// 继承 OSETBannerAdProtocol 是为了兼容现有工厂链路
/// （OSETLoadBanner 创建 Banner 时返回类型就是 id<OSETBannerAdProtocol>），
/// 继承来的 -showInView:ViewController: 在自渲染 Adapter 里留空实现即可，不会被调用。
///
/// ⚠️ 判定顺序：核心分支必须先判本协议再判 OSETBannerAdProtocol。
///    conformsToProtocol: 对被继承的协议同样返回 YES，判反了会永远走进旧模板分支。
@protocol OSETBannerCustomRenderAdProtocol <OSETBannerAdProtocol>

@required

/// 素材快照。Adapter 回调 OSETAdapterAdDidLoad: 时它就必须已经完整可用
/// （图片已下载解码、视频已拿到媒体 View），展示阶段不允许再做异步准备。
- (nullable OSETBannerRenderData *)bannerRenderData;

/// 主线程调用。把渠道的媒体 View / 广告标识 View 挂到 Context 给的容器里，
/// 记录 rootViewController，给 Context 的关闭键绑事件。
///
/// 这里只做确定性的本地挂载，不要调用渠道 register、不要发网络请求 ——
/// 调用时机在 showBanner: 内部，模板还没有 superview 和 window，
/// 此刻注册曝光监测多半不会生效。注册统一放到 -activateBannerRender: 里。
///
/// @return NO 表示绑定失败，核心会按展示失败处理。
- (BOOL)bindBannerRenderContext:(OSETBannerRenderContext *)context;

/// 主线程调用，幂等。
/// 模板真正上屏（有 window 且 bounds 非零）时传 YES，此时才调用渠道的
/// registerContainer:withClickableViews: 开始曝光监测，视频素材同时起播；
/// 移出 window 时传 NO，注销注册并暂停视频。
- (void)activateBannerRender:(BOOL)active;

/// 主线程调用，幂等。注销渠道注册、把渠道 View 从模板上摘掉、解绑关闭键。
/// 必须能被重复调用而不产生副作用。
- (void)unbindBannerRenderContext;

@end

NS_ASSUME_NONNULL_END
