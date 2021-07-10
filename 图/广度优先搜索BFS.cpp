//或者也叫做层序遍历

#include <bits/stdc++.h>
using namespace std;
#define maxVexNum 100

//树结点的定义
typedef struct Node {
    int data;
    struct Node *l, *r;
} Node, *TreeNode;

//图结点的定义
typedef struct {
    char vex[maxVexNum];
    int edge[maxVexNum][maxVexNum];
    int vexNum, edgeNum;
} MGraph;

//对于树的BFS
void bfsTree(TreeNode t) {
    if (t) {
        queue<TreeNode> q;
        q.push(t);
        while (!q.empty()) {
            TreeNode temp = q.front();
            cout << temp->data << endl;
            q.pop();
            if (temp->l) q.push(temp->l);
            if (temp->r) q.push(temp->r);
        }
    }
}

//获取该点的邻接点，没有就返回-1,有就返回顶点号
int getFirstVex(MGraph g, int x) {
    for (int i = 0; i < g.vexNum; i++)
        if (g.edge[x][i]) return g.edge[x][i];
    return -1;
}

// y是x的一个邻接点，获取除了y外x的下一个邻接点
//若y是最后一个邻接点，则返回-1
int getNextVex(MGraph g, int x, int y) {
    for (int i = y + 1; i < g.vexNum; i++) {
        if (g.edge[x][i]) return g.edge[x][i];
    }
    return -1;
}

//先设置一个标记数组，代表是否访问过顶点
bool flag[maxVexNum];  //从序号0开始,默认是flase

//对于图的BFS，这里以无向图为例,x是给定的起点
void bfsGraph(MGraph g, int x) {
    queue<int> q;  //存顶点的序号
    q.push(x);
    while (q.empty()) {
        int top = q.front();
        cout << g.vex[top] << endl;  //输出or访问
        flag[top] = true;
        q.pop();
        //接下来找到top的所有邻接点，把他们入队列
        int w = getFirstVex(g, top);
        while (w != -1) {
            if (!flag[w]) {
                q.push(w);
                flag[w] = true;
            }
            w = getNextVex(g, top, w);  //继续找下一个邻接点
        }

        /**
        //如果不借助getFirstVex和getNextVex，可以这样做
        for (int i = 0; i < g.vexNum; i++) {
            if (!flag[w] && g.edge[top][i]) {
                q.push(i);
                flag[i] = true;
            }
        }
        */
    }
}

//如果图里面有部分是没有连在一起的，需要这样处理
void visitGrapg(MGraph g) {
    //遍历标志数组，如果是flase的就作为起点开始遍历
    //这样就能够保证所有结点都遍历到
    for (int i = 0; i < g.vexNum; i++)
        if (!flag[i]) bfsGraph(g, i);
}

int main() { return 0; }