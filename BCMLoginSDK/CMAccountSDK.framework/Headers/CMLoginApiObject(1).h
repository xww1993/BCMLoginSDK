//
//  CMLoginApiObject.h
//  BCMLoginSDK
//
//  Created by code_xw on 2018/4/12.
//  Copyright © 2018年 CodeMao_xw. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface BCMUserInfoModel : NSObject

@property (nonatomic, readonly ,copy) NSString * user_id;

@property (nonatomic, copy) NSString * nickname;
@property (nonatomic, copy) NSString * avatar_url;
@property (nonatomic, copy) NSString * fullname;
//格林威治时间1970年01月01日00时00分00秒(北京时间1970年01月01日08时00分00秒)起至现在的总秒数, 如2018年1月1日，即birthday值为:1514736000
@property (nonatomic, copy) NSString * birthday;
// 性别 0女  1男
@property (nonatomic, copy) NSString * sex;
@property (nonatomic, copy) NSString *qq;           // v3新增属性
@property (nonatomic, copy) NSString * user_description;

- (NSDictionary*)dictionary;

@end
@interface BCMAccountStatusModel : NSObject
@property (nonatomic, copy) NSString * username;          // v3新增属性
@property (nonatomic, copy) NSString * user_id;
@property (nonatomic, copy) NSString * phone_number;
@property (nonatomic, copy) NSString * email;
@property (nonatomic, assign) BOOL has_password;
@property (nonatomic, assign) BOOL is_disabled;
@property (nonatomic, assign) BOOL is_first_login;//true 代表首次登录（即注册），false 则代表之前已经登录（注册）过
@end

@interface BCMLoginInfoModel : NSObject
@property (nonatomic, copy) NSString * token;
@property (nonatomic, copy) NSString * cmid;
@property (nonatomic, copy) NSString * expiration_time;
@property (nonatomic, strong) BCMUserInfoModel * userInfo;
@end;

/// v3 新增
@interface BCMAuthModel : NSObject
@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *phone_number;
@property (nonatomic, copy) NSString *has_password;
@property (nonatomic, copy) NSString *email;
@end

/// v3 返回的登录数据
@interface BCMNewLoginInfoModel : NSObject
@property (nonatomic, assign) BOOL existed;
@property (nonatomic, copy) NSString *oauth_ticket;
@property (nonatomic, strong) BCMAuthModel *auth;
@property (nonatomic, strong) BCMUserInfoModel *userInfo;

@end
