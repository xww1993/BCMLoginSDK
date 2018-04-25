//
//  BCMLoginSDKConfig.h
//  BCMLoginSDK
//
//  Created by code_xw on 2018/4/13.
//  Copyright © 2018年 CodeMao_xw. All rights reserved.
//

#import <Foundation/Foundation.h>


#define IS_DEBUGMODE [CodeMaoAccount defaultManager].isDebugMode
#define DEBUGMODE_TEST_URL [CodeMaoAccount defaultManager].test_BaseURL

#ifdef DEBUG
#define DLog(...)  NSLog(__VA_ARGS__)
#else
#define DLog(...)
#endif

typedef NS_ENUM(NSUInteger, BCMSDKErrorCode) {
    BCMSDKErrorCode_NetWorkError,//网络错误
    BCMSDKErrorCode_WECHATLoginFail,//微信登录错误
    BCMSDKErrorCode_WECHATBindFail,//微信绑定错误
    BCMSDKErrorCode_QQLoginFail,//QQ 登录错误
    BCMSDKErrorCode_QQBindFail,
    BCMSDKErrorCode_NeedLogin,//需要登录
    BCMSDKErrorCode_TokenExpired//Token 过期需要重新登录
};
typedef NS_ENUM(NSUInteger, BCMSDKCaptchaType) {
    BCMSDKCaptchaType_UpdatePassword = 1,//更新密码
    BCMSDKCaptchaType_ResetPassword,     //重置密码
};

FOUNDATION_EXTERN NSString * const BCMLOGINSDK_VERSION;
FOUNDATION_EXTERN NSString * const BCMLOGINSDK_VERSION_CODE;
FOUNDATION_EXTERN NSString * const BCMLOGINSDK_ERROR_DOMAIN;






