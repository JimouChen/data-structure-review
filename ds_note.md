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



- 在队列中，入队操作只改变rear指针，不改变front指针

## 中缀表达式转后缀表达式算法
先创建一个栈来存放不确定的运算符号
- 遇到操作数，直接加入表达式，即直接输出
- 遇到括号，如果是左括号就直接入栈，如果是右括号，就把栈运算符一直出栈加入表达式，直到把栈内的第一个左括号出栈，就停止。
- 遇到运算符，就比较一下栈里面的运算符和当前运算符，如果栈内的优先级大于或者等于当前的，就把栈内的运算符出栈，否则就把当前的入栈，如果栈顶当前是括号，那也把当前的运算符入栈；
如果当前是空栈或者是左括号，就直接把当前的运算符入栈。

## 中缀表达式求值
- 本质上就是中缀转后缀+后缀表达式求值的结合
![](https://img2020.cnblogs.com/blog/2134757/202107/2134757-20210709214658885-606832130.png)


- 伪代码
```c++
//写一个比较符号栈和当前扫描到的运算符优先级的函数
bool cmp(char op1, char op2){
    if (op1的优先级 >= op2的优先级)return true;
    return false;
}

int getValue(string s){
    stack<int> numStack; 
    stack<int> opStack; 
    //扫描
    for (int i = 0; i <= s.size(); i++){
        if(当前是操作数，入栈)
            numStack.push(s[i]);
        else if(当前是左括号，入栈)
            opStack.push(s[i]);
        else if (当前是右括号){
            //依次弹出符号栈的运算符，直到遇到左括号停止
            while(opStack.top() != 对应的左括号){
                char op = opStack.top();
                opStack.pop();
                //出栈2个操作数
                int right = numStack.top();
                numStack.pop();
                int left = numStack.top();
                numStack.pop();
                //执行right op left，结果入栈
                if (op == 对应的运算符'+-*/') 
                    numStack.push(right op left);
            }
            //把左括号丢掉
            opStack.pop();
        }else if(当前是运算符){
            char op2 = 当前运算符;
            if (opStack.top() == 左括号 || opStack.empty())
                opStack.push(op2);
            else{
                //比较栈中的运算符
                char op1 = opStack.top();
                if (cmp(op1, op2)){
                    优先级高于当前的，依次弹出op1
                    然后numStack出栈2个操作数
                    //执行right op left，结果入栈
                    numStack.push(right op left);
            }
        }

    }
    //返回操作数栈的最后一个数即是结果
    return numStack.top();
}

```

## 线索化找前驱和后继节点总结
- 这个可以现推

![](https://img2020.cnblogs.com/blog/2134757/202107/2134757-20210709214413768-1119176102.png)


- 对于中序，前驱后继都可以找到
- 对于先序，前驱找不到，后继可以找到
- 对于后序，前驱可以找到，后继找不到

> 找不到到的话，除非用三叉链表或者从根结点从头找

## 二叉排序树
- 插入操作可用递归或者非递归，具体见代码
- 删除操作分情况

![](https://img2020.cnblogs.com/blog/2134757/202107/2134757-20210709214214605-1581466468.png)


## 图

![](https://img2020.cnblogs.com/blog/2134757/202107/2134757-20210709213912857-326983507.png)

### 图的深搜和广搜
- 深搜dfs其实就和树的先序遍历类似（借助递归工作栈）
- 广搜bfs其实就是树的层次遍历（借助一个队列）
- 用在图也是一样道理，只不过需要用一个标志数组来记录顶点是否被访问过