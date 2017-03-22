//
//  NSObject+Model.h
//  DWQRuntime_6_dictToModel(二级转换)
//
//  Created by 杜文全 on 17/3/22.
//  Copyright © 2017年 com.iOSDeveloper.duwenquan. All rights reserved.


#import <Foundation/Foundation.h>

@interface NSObject (Model)

+ (instancetype)modelWithDict:(NSDictionary *)dict;

@end
