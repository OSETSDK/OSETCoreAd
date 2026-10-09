//
//  OSETBaseView.h
//  YhsADSProject
//
//  Created by Shens on 7/11/2024.
//

#import <UIKit/UIKit.h>
#import "OSETBaseAd.h"

NS_ASSUME_NONNULL_BEGIN

@class Sort;
@interface OSETBaseView : UIView

@property(nonatomic,readonly,assign)NSInteger eCPM;
/// 当前广告的唯一标识，与激励视频回调的 checkString 使用相同生成规则。
@property (atomic, copy, readonly, nullable) NSString *adRequestId;
@property(nonatomic,weak)Sort * sort;

/// 手动上报竞价成功。优先使用当前 View 绑定的 Sort 补全字段；取不到 Sort 时仅上报传入字段。
- (void)reportBiddingWinWithInfo:(nullable NSDictionary *)info;

/// 手动上报竞价失败。优先使用当前 View 绑定的 Sort 补全字段；取不到 Sort 时仅上报传入字段。
- (void)reportBiddingLossWithInfo:(nullable NSDictionary *)info;

@end

NS_ASSUME_NONNULL_END
