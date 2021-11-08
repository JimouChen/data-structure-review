/*
 Created by jmchen on 2021/7/12.
 基本思想：
    选择一个没有前驱的顶点，输出
    找到该顶点相连的其他点，把这些相邻点的度减1
    重复上面过程
*/

#ifndef DATA_STRUCTURE_REVIEW_拓扑排序_H
#define DATA_STRUCTURE_REVIEW_拓扑排序_H

#include <bits/stdc++.h>

using namespace std;
#define maxsize 100

/**定义有向图的邻接表存储结构*/
typedef struct eNode {
    int edgeToVex;          //表示该边所指向顶点的位置/序号
    struct eNode *nextNode; //表示指向下一个了邻接点的指针
} eNode;//边表

typedef struct vNode {
    char data;//假设是char型的顶点
    eNode *firstNode;//指向上面边表的第一个结点的指针
} vNode, vexList[maxsize];//记录结点的表结构

typedef struct {
    vexList vList;//邻接表
    int vexNum, edgeNum;
} Graph;

//初始化inDegree由外面给
bool topoSort(Graph g, int inDegree[]) {
    /**
     * 需要创建2个数组
     * res[]存放最终的排序结果
     * inDegree[]存放顶点的入度情况
     * */

    int res[g.vexNum];
    for (int i = 0; i < g.vexNum; i++)
        res[i] = -1;

    stack<int> stack;
    //把开始入度是0的入栈
    for (int i = 0; i < g.vexNum; ++i)
        if (!inDegree[i])stack.push(i);
    int cnt = 0;
    while (!stack.empty()) {
        int top = stack.top();
        res[cnt++] = top;//记录排序的点
        //找到顶点top相连的邻接点，删掉与他们连接的边
        //其实这里是逻辑上的删除，把邻接点的入度减1即可
        eNode *temp = g.vList[top].firstNode;
        while (temp) {
            inDegree[temp->edgeToVex]--;
            //要是度减完是0的就入栈
            if (!inDegree[temp->edgeToVex])
                stack.push(temp->edgeToVex);
            temp = temp->nextNode;
        }
    }
    if (cnt < g.vexNum) return false;
    else return true;
}

//也可以用DFS实现拓扑排序
//其实就是图的DFS,这里用的是邻接矩阵
#define maxVexNum 100
//假设这里元素是char，边是int
//这里是无向图，有向图的实现也类似

typedef struct {
    char vex[maxVexNum];             //存顶点值
    int edge[maxVexNum][maxVexNum];  //存边
    int vexNum, edgeNum;             //存当前点数和边数
} MGraph;

void dfs(MGraph g, int vex);

bool visited[maxVexNum];

void topoDFS(MGraph g) {

    for (int i = 0; i < g.vexNum; i++) {
        if (!visited[i])dfs(g, i);
    }
}

void dfs(MGraph g, int vex) {
    cout << vex << " ";
    visited[vex] = true;
    //找到所有邻接点
    for (int i = 0; i < g.vexNum; ++i) {
        if (!visited[i] && g.edge[vex][i]) {
            dfs(g, i);
        }
    }
    //如果把vex的输出放在这行位置，则是逆拓扑排序序列
}

#endif //DATA_STRUCTURE_REVIEW_拓扑排序_H
