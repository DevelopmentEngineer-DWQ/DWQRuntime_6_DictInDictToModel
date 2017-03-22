# DWQRuntime_6_DictInDictToModel
Runtime字典转模型，二级转换的简单示例
![DWQ-LOGO.jpeg](http://upload-images.jianshu.io/upload_images/2231137-1545493cd60adb2b.jpeg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

##引述
  在上一篇中我们讲述了利用Runtime字典转模型的一级转化，但是，我们发现，在我们的模型中，还是存在字典，如何再将其转化成模型呢？其实原理很简单，既然已经做过一级转换，想实现二级转化，再调用一次一级转换的方法不就解决了吗？

##二级转换步骤：

- 1，将模型中的NSDictionary转化为模型类，首先要再创建一个模型类，例子中为User，然后声明属性

- 2，在一级模型中引入二级模型的头文件，将NSDictionary替换为 User

- 3，在NSObject+Model的类方法中，我们赋值之前做判断，将字典再次进行模型转换

- 4，我们考虑的是遇到字典就转换，但是也要考虑有些字典不需要转换，那么我们要加以判断【 /值是字典,成员属性的类型不是字典,才需要转换成模型】

```objective-c
  if ([value isKindOfClass:[NSDictionary class]] && ![propertyType containsString:@"NS"]) { 
// 需要字典转换成模型
}
```

- 5,获取类名，但是通过打印得知propertyType带有@和转义字符，此时需要截取

```objective-c
// @"@\"User\"" User
            NSRange range = [propertyType rangeOfString:@"\""];
            propertyType = [propertyType substringFromIndex:range.location + range.length];
            // User\"";
            range = [propertyType rangeOfString:@"\""];
            propertyType = [propertyType substringToIndex:range.location];

```
- 6,然后根据类名转换成类对象

```objective-c
  Class modelClass =  NSClassFromString(propertyType);

```
- 7,再次调用字典转模型的方法实现二级转换

```objective-c
 if (modelClass) {
                value =  [modelClass modelWithDict:value];
                
            }
```

##效果展示：

![二级转换.png](http://upload-images.jianshu.io/upload_images/2231137-02a121cad4c4aead.png)
从断点得知，我们已经成功将User这个字典做了二级转换。
