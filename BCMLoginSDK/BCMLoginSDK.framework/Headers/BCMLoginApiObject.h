//
//  BCMLoginApiObject.h
//  BCMLoginSDK
//
//  Created by code_xw on 2018/4/12.
//  Copyright © 2018年 CodeMao_xw. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface BCMUserInfoModel : NSObject
//MARK: 这个不能通过传值改变
@property (nonatomic, copy) NSString * user_id;

@property (nonatomic, copy) NSString * nickname;
@property (nonatomic, copy) NSString * avatar_url;
@property (nonatomic, copy) NSString * fullname;
@property (nonatomic, copy) NSString * birthday;
@property (nonatomic, copy) NSString * sex;
@property (nonatomic, copy) NSString * user_description;

@end
@interface BCMAccountStatusModel : NSObject
@property (nonatomic, copy) NSString * user_id;
@property (nonatomic, copy) NSString * phone_number;
@property (nonatomic, copy) NSString * email;
@property (nonatomic, assign) BOOL has_password;
@property (nonatomic, assign) BOOL is_disabled;
@end

@interface BCMLoginInfoModel : NSObject
@property (nonatomic, copy) NSString * token;
@property (nonatomic, copy) NSString * cmid;
@property (nonatomic, copy) NSString * expiration_time;
@property (nonatomic, strong) BCMUserInfoModel * userInfo;
@end;

