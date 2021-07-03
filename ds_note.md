# 一些笔记

## 注意
- 在定义结构体时，如果里面元素有用到自身结构体类型的，struct后面加名字，则定义的框架如下：
```c++
typedef struct Name{
    ElemType a;
    struct Name *b;//这里用到
    //...其它定义
} MyName;
```

- 如果里面没有涌用到自身结构体的话，struct后面不用加名字，定义如下：
```c++
typedef struct{
    ElemType a;
    //...其它定义
} MyName;//直接就命名
```

