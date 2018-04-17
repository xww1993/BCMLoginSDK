//
//  BCMLoginManage.h
//  CDMUserLogin
//
//  Created by CodeMao_xw on 2017/12/5.
//  Copyright © 2017年 CodeMao_xw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCMLoginSDKConfig.h"
@class BCMUserInfoModel;
@class JYManageHelp;
@class BCMAccountStatusModel;

/**
 请求返回 Block (数据未处理)

 @param responseObject 返回信息
 @param error 可根据 - (NSString *)returnErrorStringWithError:(NSError *)error; 获取相应的提示;
 */
typedef void (^BCMLoginResult) ( NSDictionary * _Nullable responseObject, NSError * _Nullable error);

/**
 数据处理过的返回 Block

 @param respond 返回处理过的信息类
 @param error 错误
 @param sourceInfo 网络请求的话这里会返回原始数据
 */
typedef void (^BCMLoginSDKCompletionHandler) (id _Nullable respond, NSError * _Nullable error, id _Nullable sourceInfo);
NS_ASSUME_NONNULL_BEGIN
@interface BCMLoginManage : NSObject
//测试模式下优先级最高
@property (nonatomic, readonly, copy) NSString * test_BaseURL;
@property (nonatomic, readonly, strong) BCMUserInfoModel * userInfoModel;
@property (nonatomic, readonly, strong) BCMAccountStatusModel * accountStatusModel;


/**
 设置 PID (初始化方法)
 
 @param PID 产品 PID
 @return 初始化的实例
 */
+ (instancetype)initializeWithPID:(NSString *)PID;


/**
 获取当前默认的单例

 @return 单例
 */
+ (BCMLoginManage *)defaultManager;

/**
 设置 Debug 模式;
 */
- (void)setDebugMode;

/**
 设置 Debug 模式 & 服务器地址

  @param Test_URL @"https://set08.dev-backend.codemao.cn"<---这种格式
 */
- (void)setDebugMode:(NSString *)Test_URL;

/**
 判断是否是测试环境

 @return  BOOL 值
 */
- (BOOL)isDebugMode;

/**
 返回baseURL

 @return 当前的baseURL
 */
- (NSString *)baseURL;

/**
 获取登录返回的 Token;
 @return 当前登录用户的 Token
 */
- (NSString *)getAccountToken;


/**
 退出登录
 */
- (void)logout;

#pragma mark - 注册
#pragma mark 手机注册

/**
 手机账号注册
 (这个接口的本质其实就是手机验证码登录,后台会在没注册的情况下自动注册,已注册的根据手机验证码登录);
 @param UesrPhone 用户手机号
 @param VerificationCode 验证码
 @param CompletionHandler 请求返回结果
 */
- (void)phoneRegister:(NSString *)UesrPhone verificationCode:(NSString *)VerificationCode completionHandler:(BCMLoginSDKCompletionHandler)CompletionHandler;
#pragma mark 邮箱注册

/**
 邮箱注册

 @param Email   邮箱
 @param Password 密码
 @param Language 语言 (只接受 @"en",@"cn" 其一)
 @param Result 结果
 */
- (void)emailRegister:(NSString *)Email password:(NSString *)Password language:(NSString *)Language result:(BCMLoginResult)Result;

/**
 激活邮箱注册账号

 @param Active_code 激活码
 @param Result 结果
 */
- (void)activeEmail:(NSString *)Active_code result:(BCMLoginResult)Result;
#pragma mark- 登录
/**
 账号密码登录请求接口

 @param Account 用户名
 @param Passwords 用户密码
 @param CompletionHandler 返回请求结果
 */
- (void)accountLogin:(NSString *)Account passwords:(NSString *)Passwords completionHandler:(BCMLoginSDKCompletionHandler)CompletionHandler;

/**
 手机号码登录

 @param UesrPhone 用户手机号
 @param VerificationCode 验证码
 @param CompletionHandler 请求返回结果
 */
- (void)phoneLogin:(NSString *)UesrPhone verificationCode:(NSString *)VerificationCode completionHandler:(BCMLoginSDKCompletionHandler)CompletionHandler;

#pragma mark- 第三方登录
    
/**
 设置微信的 AppKey
 */
- (void)setWeChatAppKey:(NSString *)key;


/**
 微信登录
 //MAKR: 先设置 SourceID
 @param CompletionHandler 返回结果
 */
- (void)loginByWeChat:(BCMLoginSDKCompletionHandler)CompletionHandler;

/**
 设置QQ互联的 AppKeY
 */
- (void)setQQAppKey:(NSString *)key;

/**
 QQ登录接口
 //MAKR: 先设置 SourceID
 @param CompletionHandler 返回结果
 */
- (void)loginByQQ:(BCMLoginSDKCompletionHandler)CompletionHandler;

/**
 *  获得从sso或者web端回调到本app的回调
 *
 *  @param url qq微信等打开本app的回调的url
 *
 *  @return 是否处理  YES代表处理成功，NO代表不处理
 */
-(BOOL)handleOpenURL:(NSURL *)url;
#pragma mark - 第三方账号绑定解绑

/**
 绑定微信
 */
- (void)bindWechat:(BCMLoginSDKCompletionHandler)CompletionHandler;

/**
 解绑微信
 @param Result  结果
 */
- (void)unBindWeChat:(BCMLoginResult)Result;

/**
 绑定 QQ
 */
- (void)bindQQ:(BCMLoginSDKCompletionHandler)CompletionHandler;

/**
 解绑 QQ

 @param Result 结果
 */
- (void)unBindQQ:(BCMLoginResult)Result;

/**
 查询绑定状态列表

 @param Result 结果
 */
- (void)checkBindStatus:(BCMLoginResult)Result;

#pragma mark- 设置初始化

/**
 发送绑定手机时所需的验证码
 PS:记得60S间隔 ,否则后台会返回错误;
 @param Phone 手机号码
 @param Result 返回结果
 */
- (void)getBindPhoneCaptcha:(NSString *)Phone result:(BCMLoginResult)Result;


/**
 绑定第三方账号的手机(默认带重设密码)

 @param Phone 手机号码
 @param Captcha 验证码(极验)
 @param Password 密码 ---> //MARK: 选填参数;
 @param Result 返回结果
 */
- (void)bindPhone:(NSString *)Phone captcha:(NSString *)Captcha password:(nullable NSString *)Password result:(BCMLoginResult)Result;


/**
 账号注册后设置初始化密码
 (根据登录返回的 is_having_password 字段判断)
 @param Password 用户设置的初始密码
 @param Result 返回设置结果
 */
- (void)setDefaultPassword:(NSString *)Password result:(BCMLoginResult)Result;

#pragma mark- 修改
#pragma mark 修改密码


/**
 重置密码 V2 (未登录状态忘记密码重设)

 @param Password 新密码
 @param Token 验证码验证返回的 Token
 @param Result 返回结果
 */
- (void)resetPassword:(NSString *)Password token:(NSString *)Token result:(BCMLoginResult)Result;

/**
 发送修改密码需要的验证码
 (60秒一次否则后台报错)
 @param Phone 电话号码
 @param Result 返回结果
 */
- (void)getChangePasswordCaptcha:(NSString *)Phone result:(BCMLoginResult)Result;


/**
 修改密码 V2接口

 @param Password 新密码
 @param Token  Token (验证密码返回的 Token)
 @param Result 返回结果
 */
- (void)changePassword:(NSString *)Password token:(NSString *)Token result:(BCMLoginResult)Result;

#pragma mark 修改手机
/**
 发送修改绑定手机的验证码

 @param Phone 手机号码
 @param Result 返回结果
 */
- (void)getChangePhoneNumberCaptcha:(NSString *)Phone result:(BCMLoginResult)Result;

/**
 修改绑定手机号

 @param Old_phone 旧号码
 @param New_phone 新号码
 @param Captcha 验证码
 @param Result 结果  
 */
- (void)changePhoneNumber:(NSString *)Old_phone new_Phone:(NSString *)New_phone captcha:(NSString *)Captcha result:(BCMLoginResult)Result;


/**
 验证手机验证码是否正确

 @param Phone 手机号
 @param Captcha 验证码
 @param CaptchaType 验证码类型
 @param Result 返回接口信息
 */
- (void)checkPhoneCaptcha:(NSString *)Phone captcha:(NSString *)Captcha captchaType:(BCMSDKCaptchaType)CaptchaType result:(BCMLoginResult)Result;
#pragma mark 修改用户名

/**
 发送修改用户名的验证码

 @param Phone 手机号码
 @param Result 结果
 */
- (void)getChangeUserNameCaptcha:(NSString *)Phone result:(BCMLoginResult)Result;

/**
 修改用户名

 @param Username 新的用户名
 @param captcha 验证码
 @param Phone 手机号
 @param Result 结果
 */
- (void)changeUserName:(NSString *)Username captcha:(NSString *)captcha phone:(NSString *)Phone result:(BCMLoginResult)Result;
#pragma mark 修改账号信息


/**
 修改账号信息
 InfoModel --> 设置需要改变的值
 @param InfoModel BCMUserInfoModel
 @param Result 结果
 */
- (void)changeAccountInfo:(BCMUserInfoModel *)InfoModel result:(BCMLoginResult)Result;
#pragma mark 老师端修改学生密码


/**
 老师端修改学生密码

 @param UserID (应该是学生的 UserID 如果是用户的后期再封装)
 @param Password 新密码
 @param Nonce_str 随机字符串
 @param Sign 对应参数签名
 @param Result 返回结果
 */
- (void)changeStudentPassword:(NSString *)UserID password:(NSString *)Password nonce_str:(NSString *)Nonce_str sign:(NSString *)Sign result:(BCMLoginResult)Result;


#pragma mark- 获取信息详情

/**
 异步判断是否登录
 登录CompletionHandler直接返回缓存数据;
 未登录调请求返回实时数据;
 (未完成!!!!!!)---<------

 @param CompletionHandler CompletionHandler
 */
- (void)getCachedUserInfo:(BCMLoginSDKCompletionHandler)CompletionHandler;
/**
 获取用户详情(网络接口请求)
 @param Result 返回请求结果
 */
- (void)getBasicAuthUserInfo:(BCMLoginResult)Result;

/**
 获取用户信息(从本地缓存)
 //TODO: 判断 TOKEN过期;
 @return 返回用户信息 Model;
 */
- (BCMUserInfoModel *)getCachedUserInfo;
/**
 获取账号状态

 @param Result 返回请求结果
 */
- (void)loadAccountStatusResult:(BCMLoginResult)Result;
#pragma mark- 极验
/**
 进入需要极验的界面显示之前调用的方法
    <<Request :初始化极验 >>>>

 @param Result 结果(返回即成功)
 */
- (void)startRegistJYManager:(void(^)(void))Result;

/**
 普通极验验证码发送

 @param Phone 手机号码
 @param success 验证码发送成功
 @param failure 验证码发送失败
 @param animated 是否动画
 */
- (void)sendCommonCaptcha:(NSString *)Phone success:(void (^)(void))success failure:(void (^)(void))failure animated:(BOOL)animated;

/**
 注册极验验证码发送

 @param Phone 手机号码
 @param success 验证码发送成功
 @param failure 验证码发送失败
 @param animated 是否动画
 */
- (void)getRegisterCaptcha:(NSString *)Phone success:(void (^)(void))success failure:(void (^)(void))failure animated:(BOOL)animated;
/**
 登录极验验证码发送
 
 @param Phone 手机号码
 @param success 验证码发送成功
 @param failure 验证码发送失败
 @param animated 是否动画
 */
- (void)getLoginCaptcha:(NSString *)Phone success:(void (^)(void))success failure:(void (^)(void))failure animated:(BOOL)animated;
/**
 重设密码极验验证码发送(未登录找回密码)
 
 @param Phone 手机号码
 @param success 验证码发送成功
 @param failure 验证码发送失败
 @param animated 是否动画
 */
- (void)sendResetPasswordCaptcha:(NSString *)Phone success:(void (^)(void))success failure:(void (^)(void))failure animated:(BOOL)animated;




/**
 根据错误返回错误提示;

 @param NSString @""
 @return 错误提示;
 */
#pragma mark - 错误码获取方法
- (NSString *)returnErrorStringWithError:(NSError *)error;
@end
NS_ASSUME_NONNULL_END
//@interface BCMLoginManage (UMengLoginSDKInitialize)
//- (void)initializeUMengSDK_QQ_WithAppKey:(NSString *)Key appSecret:(NSString *)Secret redirectURL:(NSString *)URL;
//@end

