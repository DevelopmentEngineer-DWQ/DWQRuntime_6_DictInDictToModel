//
//  weibo.m
//  DWQRuntime_6_dictToModel(二级转换)
//
//  Created by 杜文全 on 17/3/22.
//  Copyright © 2017年 com.iOSDeveloper.duwenquan. All rights reserved.
//

#import "weibo.h"

@implementation weibo
+ (weibo *)weiboWithDict:(NSDictionary *)dict
{
    weibo *wb = [[self alloc] init];
    
    // KVC
    [wb setValuesForKeysWithDictionary:dict];
    
    return wb;
}

// 解决KVC报错
- (void)setValue:(id)value forUndefinedKey:(NSString *)key
{
    if ([key isEqualToString:@"id"]) {
        _ID = [value integerValue];
    }
    // key:没有找到key
    // value:没有找到key对应的值
    NSLog(@"%@ %@",key,value);
}

@end
