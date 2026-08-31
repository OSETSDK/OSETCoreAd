//
//  OSETBannerRenderData.h
//  OSETSDK
//
//  Banner 自渲染统一素材快照。
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 素材类型
typedef NS_ENUM(NSInteger, OSETBannerMaterialType) {
    /// 图片素材，展示 preparedImage
    OSETBannerMaterialTypeImage = 0,
    /// 视频素材，模板留出媒体容器由渠道挂自己的播放 View
    OSETBannerMaterialTypeVideo = 1,
};

/// 渠道素材的统一快照。
///
/// 设计约束（改动前务必先读）：
/// 1. 创建后只读。缓存中的广告对象可能在展示期间被渠道内部异步改写，
///    这里必须是一份不会再变的副本，否则模板可能读到半初始化状态。
/// 2. 只存值对象和已解码 UIImage。不持有渠道广告对象、manager、delegate、UIView，
///    否则统一模型会反向依赖渠道，模板改一次就要动所有 Adapter。
/// 3. 不提供 extras 字典兜底渠道私有字段。渠道私有行为留在各自 Adapter 里，
///    这个模型只承载跨渠道都成立的展示语义。
/// 4. 图片素材的 preparedImage 必须在 Adapter 回调 load success 之前就绪，
///    这样展示阶段不会出现"先白一下再出图"。
@interface OSETBannerRenderData : NSObject

/// 图片 / 视频
@property (nonatomic, assign, readonly) OSETBannerMaterialType materialType;

/// 主图，load 阶段已下载并解码完成。图片素材必填；视频素材可为封面图，允许为空。
@property (nonatomic, strong, readonly, nullable) UIImage *preparedImage;

/// 渠道广告标识图（如"广告"角标、渠道 logo），load 阶段已解码。
/// 部分渠道要求必须用它自己提供的标识 View，那种情况走 Context 的 adMarkContainerView，
/// 不走这个字段。
@property (nonatomic, strong, readonly, nullable) UIImage *adMarkImage;

/// 无标识图时的兜底文案，通常是"广告"。
@property (nonatomic, copy, readonly, nullable) NSString *adMarkText;

/// 素材原始像素尺寸，用于比例校验。未知时为 CGSizeZero。
@property (nonatomic, assign, readonly) CGSize materialPixelSize;

/// 是否是摇一摇素材。
///
/// ⚠️ 它只决定「要不要画摇一摇提示」，不代表核心会去监听传感器。
/// 摇动的检测和点击触发全部在渠道 SDK 内部（如 QDA 的 setSensorStatus: 全局开关），
/// 核心既收不到"摇触发"回调，也无法调阈值 —— 我们唯一负责的是把提示画出来，
/// 让用户知道这条广告可以摇。自家 API 奇点那条链（yyy/nyn + OSETAPIMotionManager）
/// 与此无关，不要混。
@property (nonatomic, assign, readonly) BOOL shakeEnabled;

#pragma mark - 图文字段

/// 以下字段决定模板走哪种形态：
/// title/desc 都为空 → 纯图（素材占满）；任一非空 → 图文（左图右文 + CTA）。
/// title 为空时模板会退到 appName，再空则由 desc 晋升为主标题，规则与 API 奇点一致。
/// callToAction 非空时才显示 CTA 按钮。
@property (nonatomic, copy, readonly, nullable) NSString *title;
@property (nonatomic, copy, readonly, nullable) NSString *desc;
@property (nonatomic, copy, readonly, nullable) NSString *callToAction;
@property (nonatomic, copy, readonly, nullable) NSString *appName;
/// 预留，首版模板不展示
@property (nonatomic, strong, readonly, nullable) NSURL *iconURL;

#pragma mark - 构造

/// 图片素材
+ (instancetype)imageDataWithImage:(UIImage *)image
                 materialPixelSize:(CGSize)materialPixelSize;

/// 视频素材（coverImage 可空）
+ (instancetype)videoDataWithCoverImage:(nullable UIImage *)coverImage
                      materialPixelSize:(CGSize)materialPixelSize;

/// 补充广告标识。渠道给了标识图就传 image，只有文案就传 text。
- (void)fillAdMarkImage:(nullable UIImage *)adMarkImage text:(nullable NSString *)adMarkText;

/// 标记为摇一摇素材。只允许在 Adapter 回调 load success 之前调用，之后视为只读。
- (void)fillShakeEnabled:(BOOL)shakeEnabled;

/// 补充文案类字段。只允许在 Adapter 回调 load success 之前调用，之后视为只读。
- (void)fillTitle:(nullable NSString *)title
             desc:(nullable NSString *)desc
     callToAction:(nullable NSString *)callToAction
          appName:(nullable NSString *)appName
          iconURL:(nullable NSURL *)iconURL;

/// 素材是否足以展示：图片素材必须有图，视频素材由 Adapter 另外保证 mediaView 就绪。
- (BOOL)isRenderable;

@end

NS_ASSUME_NONNULL_END
