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

//树的深搜类似先序遍历
void biTreeDFS(TreeNode t) {
    if (t) {
        cout << t->data << endl;
        if (t->l) biTreeDFS(t->l);
        if (t->r) biTreeDFS(t->r);
    }
}

//先设置一个标记数组，代表是否访问过顶点
bool flag[maxVexNum];  //从序号0开始,默认是flase

//图的深搜,从顶点v开始深搜
void graphDFS(MGraph g, int v) {
    cout << g.vex[v] << endl;
    flag[v] = true;

    //找到该点的邻接点，然后依次深度遍历
    int next = getFirstVex(g, v);
    while (next != -1) {
        if (!flag[next]) graphDFS(g, next);
        next = getNextVex(g, v, next);
    }

    /**
    //或者用这种来找所有邻接点
    for (int i = 0; i < g.vexNum; i++) {
        if (!flag[i] && g.edge[v][i])
            graphDFS(g, g.edge[v][i]);
    }
    */
}

//为了避免有部分子图是没有连在一起的
void trackDFS(MGraph g) {
    // flag初始化时默认是false
    for (int i = 0; i < g.vexNum; i++) {
        if (!flag[i]) graphDFS(g, i);
    }
}

int main() { return 0; }