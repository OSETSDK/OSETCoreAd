//
//  OSETShakeView.h
//  YhsADSProject
//
//  Created by Shens on 10/6/2025.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface OSETShakeView : UIView
@property (nonatomic, strong) UILabel * tipsLabel;
@property (nonatomic, strong) UIImageView * shakeImageView;
- (void)startRotationShakeAnimation;
@end

NS_ASSUME_NONNULL_END

//#import <UIKit/UIKit.h>
//
//NS_ASSUME_NONNULL_BEGIN
//
//@class OSETNativeDataAdObject;
//
//@interface OSETShakeView : UIView
//
//@property (nonatomic, strong) UILabel *tipsLabel;
//@property (nonatomic, strong) UIImageView *shakeImageView;
//
//// 关联的数据对象（弱引用，避免循环引用）
//@property (nonatomic, weak) OSETNativeDataAdObject *dataObject;
//
//// 可见性状态
//@property (nonatomic, assign, readonly) BOOL isVisible;
//@property (nonatomic, assign, readonly) BOOL isMonitoring;
//
//- (void)startRotationShakeAnimation;
//- (void)stopRotationShakeAnimation;
//
//// 可见性控制方法
//- (void)startVisibilityMonitoring;
//- (void)stopVisibilityMonitoring;
//
//@end
//
//NS_ASSUME_NONNULL_END
