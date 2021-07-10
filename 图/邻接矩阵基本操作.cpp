#include <bits/stdc++.h>
using namespace std;
#define maxVexNum 100
//假设这里元素是char，边是int
//这里是无向图，有向图的实现也类似

typedef struct {
    char vex[maxVexNum];             //存顶点值
    int edge[maxVexNum][maxVexNum];  //存边
    int vexNum, edgeNum;             //存当前点数和边数
} MGraph;

//判断是否存在边<v1, v2>
bool isHasEdge(MGraph g, int x, int y) { return g.edge[x][y]; }

void getNeighbor(MGraph g, int x) {
    for (int i = 0; i < g.vexNum; i++) {
        if (g.edge[x][i]) cout << g.vex[i] << endl;
    }
}

void insertVex(MGraph &g, char data) { g.vex[g.vexNum++] = data; }

void deleteVex(MGraph &g, int x) {
    for (int i = 0; i < g.vexNum; i++) {
        g.edge[x][i] = 0;
        g.edge[i][x] = 0;
    }
    g.vexNum--;
}

void addEdge(MGraph &g, int x, int y, int value) {
    g.edge[x][y] = value;
    g.edge[y][x] = value;  //无向图
    g.edgeNum += 2;
}

void findFirstNeigh(MGraph g, int x) {
    bool flag = 0;
    for (int i = 0; i < g.vexNum; i++) {
        if (g.edge[x][i]) {
            cout << g.vex[i] << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0) cout << "None" << endl;
}

void getNextNeighbor(MGraph g, int x) {
    int c = 0;
    for (int i = 0; i < g.vexNum; i++) {
        if (g.edge[x][i]) c++;
        if (c == 2) {  //存在下一个邻接点
            cout << g.vex[i] << endl;
            break;
        }
    }
    if (c != 2) cout << "None" << endl;
}

int getEdgeValue(MGraph g, int x, int y) { return g.edge[x][y]; }

void setEdgeValue(MGraph &g, int x, int y, int v) {
    g.edge[x][y] = v;
    g.edge[y][x] = v;
}

int main() { return 0; }