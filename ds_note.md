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

### 图的应用
#### 最小生成树
![](https://img2020.cnblogs.com/blog/2134757/202107/2134757-20210711155154783-60274522.png)

- prim算法
- kruskal算法

prim算法实现：
- 先用一个二维```int g[n][n]```数组(假设是int权值)存这个有向图的权值
- 再用一个大小与顶点数一样的数组```bool isAdd[n]```,这个是来表示该点有没有加入最小生成树里面的，加了就设为true，没有就false
- 还需要一个数组```int temp[n]```,来记录该生成树与每个未加入的顶点的最小距离，每次加入一个isAdd[i]=false且是最小距离的结点后，需要重新更新这个temp数组的值，已经加入的点可以不用更新，更新未加入的点到生成树的最小距离即可
- 准备工作做完后，算法开始：
> 先把v0或者随便选一个点作为起始点，也就是这个初始生成树
> 开始遍历每个点，找到距离最小的加入生成树,需要O(n)
>> 每次遍历都要更新未加入点到生成树的最小距离，需要O(n),更新可以这样做：
>>> 遍历当前生成树的每个顶点vi，找到vi与那些未加入的顶点vj中距离最小的值和对应的vj，然后完成这次遍历后就有min{vj,...}和对应的未加入的顶点，然后把这个顶点加入生成树...

>> 上面过程也是更新temp[]的过程

> 直到所有的顶点都加入，也就是isAdd全部是false即完成

- 时间复杂度是O(n^2)

kruskal算法实现思想：
> 初始时，先把各边权值按照从小到大的顺序排序
![](https://img2020.cnblogs.com/blog/2134757/202107/2134757-20210711152944296-476640185.png)

> 设有e条边，则遍历e次,需要O(e)
>> 每次使用并查集判断两个顶点是不是属于一个集合，需要O(loge)

- 时间复杂度是O(eloge)

###最短路径
- bfs无权图的最短路径
- 狄杰斯特拉算法
- 弗洛伊德算法


bfs无权图的最短路径，其实就是在图的广搜访问操作那粒做修改
- d[]:记录起点到其它点的最短路径
- visited[]:记录是否访问过该结点
- path[]:记录访问到的当前结点的前驱结点，也就是从哪里来的

![](https://img2020.cnblogs.com/blog/2134757/202107/2134757-20210711163619778-843149490.png)

dijkstra算法：
需要三个数组，final是表示是否确定找到最短距离
dist：记录最短距离
path：记录前驱
- 初始：若从V0开始，令
```c++
final[0]=ture;
dist[0]=0;
path[0]=-1;
```
其余顶点:
```c++
final[k]=false;
dist[k]=arcs[0][k];
path[k]=(arcs[0][k]==INF)?-1:0;
```

- 然后进行n-1轮处理：循环遍历所有顶点，找到还没确定最短路径，且dist最⼩的顶点Vi，令```ﬁnal[i]=ture```,
并检查所有邻接⾃Vi的顶点，对于邻接⾃Vi的顶点Vj，若
```c++
final[j]==false && dist[i]+arcs[i][j]<dist[j]
```

- 则令
```c++
dist[j]=dist[i]+arcs[i][j];//更新最小值
path[j]=i;//记录前驱
```
- 注：arcs[i][j]表示Vi到Vj的弧的权值
- 时间复杂度O(n^2)

佛洛依德算法
- 先准备2个数组
- 一个存放距离，一个存放前驱
```c++
//佛洛依德算法，动态规划，三层遍历
//需要实现准备2个二维数组a,path
void floyd(MGraph g) {
    MGraph a = g;
    int path[g.vexNum][g.vexNum];
    for (int i = 0; i < g.vexNum; i++)
        for (int j = 0; j < g.vexNum; j++)
            path[i][j] = -1;

    for (int k = 0; k < g.vexNum; k++)//k是中转点
        for (int i = 0; i < g.vexNum; i++)
            for (int j = 0; j < g.vexNum; j++) {
                if (a.edge[i][j] > a.edge[i][k] + a.edge[k][j]) {
                    a.edge[i][j] = a.edge[i][k] + a.edge[k][j];
                    path[i][j] = k;//记录中转点（上一个点）
                }
            }

    //得到记录最短路径的a和前驱path，可做输出显示

    for (int i = 0; i < g.vexNum; i++) {
        for (int j = 0; j < g.vexNum; j++)
            cout << a.edge[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < g.vexNum; i++) {
        for (int j = 0; j < g.vexNum; j++)
            cout << path[i][j] << " ";
        cout << endl;
    }
}
```

## 拓扑排序

### 算法步骤

- 首先2个数组，inDegree[]存放所有顶点的入度是多少，res[]存放拓扑排序的序列
- 然后初始化一个栈来存放inDegree里面入度是0的顶点(序号)
- 执行循环：
  
```c++
cnt = 0
while (栈不空){
    出栈栈顶顶点vi
    记录该点到res[cnt++] = vi
    然后找到相连的所有顶点，把他们的度都减1
    对应的inDegree[j]--;
    如果减完为0的话，就入栈
}
栈空后如果cnt == 顶点个数，则排序成功
如果cnt < 顶点个数，则说明有回路，拓扑排序失败
```
- 算法结束

## 查找

### B树

![](https://img2020.cnblogs.com/blog/2134757/202107/2134757-20210713121738843-1738135710.png)
- 最大和最小高度
  ![](https://img2020.cnblogs.com/blog/2134757/202107/2134757-20210713134145331-902608055.png)
