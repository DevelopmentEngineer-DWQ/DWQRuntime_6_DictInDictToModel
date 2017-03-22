//
//  User.h
//  DWQRuntime_6_dictToModel(二级转换)
//
//  Created by 杜文全 on 17/3/22.
//  Copyright © 2017年 com.iOSDeveloper.duwenquan. All rights reserved.

#import <Foundation/Foundation.h>

@interface User : NSObject

@property (nonatomic, strong) NSString *profile_image_url;

@property (nonatomic, assign) BOOL vip;

@property (nonatomic, strong) NSString *name;

@property (nonatomic, assign) int mbrank;

@property (nonatomic, assign) int mbtype;

@end
