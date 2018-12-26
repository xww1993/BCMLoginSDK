//
//  CodeMaoAccount+Extension.h
//  CMAccountSDK
//
//  Created by caili on 2018/11/6.
//  Copyright © 2018 CodeMao_xw. All rights reserved.
//

//#import <CMAccountSDK/CodeMaoAccount.h>
#import "CodeMaoAccount.h"

@interface CodeMaoAccount (Extension)

/// 判断密码（注册、修改、重置）
+ (BOOL)isValidPassword:(NSString*)password;

/// 判断手机号
+ (BOOL)isValidPhoneNumber:(NSString*)phone;

/// 判断验证码
+ (BOOL)isValidCaptcha:(NSString*)captcha;

/// 判断用户名
+ (BOOL)isValidUserName:(NSString*)userName;

/// 判断昵称
+ (BOOL)isValidNickName:(NSString*)nickName;

/// 判断真实姓名
+ (BOOL)isValidFullName:(NSString*)fullName;

/// 判断性别
+ (BOOL)isValidSex:(NSInteger)sex;

/// 判断email
+ (BOOL)isValidEmail:(NSString*)email;

/// 判断个性签名
+ (BOOL)isValidDescription:(NSString*)desc;

/// 判断qq号
+ (BOOL)isValidQQ:(NSString*)qq;
@end
