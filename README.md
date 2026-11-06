# OSETCoreAd

OSET 零渠道 Core 二进制交付仓库。`7.0.4.0` 提供 M 渠道的 `tuiyi` 运行时注册；渠道实现和渠道 SDK 通过独立 Pod 安装。

该版本使用当前 Core 源码快照构建，同时包含已有 SKT 实现与 `jili` 配置类型容错。发布包沿用外置阿里云日志依赖方式，公开头仅声明 Release 二进制提供的接口。

## CocoaPods

```ruby
source 'https://github.com/OSETSDK/Specs.git'
source 'https://cdn.cocoapods.org/'

platform :ios, '12.0'

target 'YourApp' do
  pod 'OSETCoreAd', '7.0.4.0'
end
```

新项目执行 `pod install --repo-update`。已有项目保留锁文件，使用定向 `pod update OSETCoreAd`，并检查依赖变化及 `SPEC REPOS`。

## M 渠道

M 渠道接入安装 `AdSetQDMAdapter 2.0.0.0`，其依赖为 `OSETCoreAd >= 7.0.4.0` 和 `AdSetQDMAdSDK = 1.4.16`。Core 使用 `tuiyi` 映射初始化、开屏、插屏、激励视频和 Native 模板适配器。NativeData、Banner、独立 FullscreenVideo 和 Draw 不开放。

仅安装 Core 不会包含 M 渠道实现。M 渠道 SDK 是动态框架，应用需正确嵌入和签名。

## 交付内容

- 静态 `OSETSDK.xcframework`：真机 arm64；模拟器 arm64 和 x86_64。
- `OSETSDK.bundle`：由 Podspec 的 `OSETResources` 资源 bundle 集成。
- `AliyunLogProducer`：继续通过 CocoaPods 外置依赖，Core 不内置该依赖实现。
- 最低 iOS 12.0。整体工程的模拟器能力同时受所选第三方 Pod 限制；`AliyunLogProducer 4.3.3` 官方规格排除 arm64 模拟器，该配置不由本仓库覆盖。

本仓库的编译和安装检查不代替真实广告加载、展示、奖励、点击及关闭流程验收。
