//
//  CodeMaoAccountv3.h
//  CMAccountSDK
//
//  Created by caili on 2018/10/29.
//  Copyright © 2018 CodeMao_xw. All rights reserved.
//  v3新接口

//#import <CMAccountSDK/CMAccountSDK.h>
#import "CodeMaoAccountBase.h"

@interface CodeMaoAccount : CodeMaoAccountBase

#pragma mark - 登录和注册
/// v3的接口
+ (CodeMaoAccount*)defaultManager;
/// v2的接口
+ (CodeMaoAccountBase*)oldApiManager;

/***************************v3新接口************************/

/// 手机注册 (密码可选)
- (void)phoneRegister:(NSString *)UesrPhone password: (nullable NSString*)password verificationCode:(NSString *)VerificationCode completionHandler:(BCMLoginSDKCompletionHandler)CompletionHandler;

/// 第三方账户激活（验证码可选，如果传验证码则绑定手机）
- (void)thirdPartActive: (NSString*)authTicket captcha: (nullable NSString*)captcha  completionHandler:(BCMLoginSDKCompletionHandler)CompletionHandler;

- (void)logout:(BCMLoginResult)Result;

#pragma mark - 绑定与解绑

/// 发送绑定手机验证码（用于第三方账户第一次登录）
- (void)getThirdPartBindPhoneCaptcha: (NSString*)phone authTicket: (NSString*)authTicket result:(BCMLoginResult)Result;

/// 检测输入手机是否是绑定手机(可选方法)
- (void)judgeBindPhone: (NSString*)phone result:(void (^)(BOOL, NSError*))Result;

/// 发送更新绑定手机的验证码
- (void)getChangePhoneNumberCaptcha:(NSString *)oldPhone newPhone: (NSString*)newPhone result:(BCMLoginResult)Result;

/// 绑定手机
- (void)bindPhone:(NSString *)Phone captcha:(NSString *)Captcha result:(BCMLoginResult)Result;

/// 更换手机号
- (void)changePhoneNumber:(NSString *)newPhone captcha:(NSString *)Captcha result:(BCMLoginResult)Result;

#pragma mark - 密码

/// 更新密码（通过验证码）
- (void)changePassword:(NSString *)Password phone: (NSString*)phone captcha:(NSString *)captcha result:(BCMLoginResult)Result;

/// 更新密码（通过旧密码）
- (void)changePassword: (NSString*)password oldPassword: (NSString*)oldPassword  result:(BCMLoginResult)Result;

/// 重置密码 (需要ticket）
- (void)resetPassword:(NSString *)Password ticket:(NSString *)ticket result:(BCMLoginResult)Result;

/// 检查重置密码的验证码, 返回ticket
- (void)checkResetPasswordCaptcha: (NSString*)phone captcha: (NSString*)captcha result:(BCMLoginResult)Result;

#pragma mark - 用户

/// 设置用户名，有且只能设置一次
- (void)changeUserName:(NSString *)Username result:(BCMLoginResult)Result;


/// 获取基本用户信息
- (void)getBasicUserInfo: (BCMLoginSDKCompletionHandler)completionHandler;

/// 获取主账号信息（私密信息）
- (void)getPrivateUserInfo: (BCMLoginSDKCompletionHandler)completionHandler;

@end
