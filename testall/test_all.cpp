#include<bits/stdc++.h>

using namespace std;
#define maxVexNum 100
#define INF 99999999 //无连接的边无穷大的距离
typedef struct {
    char vex[maxVexNum];
    int edge[maxVexNum][maxVexNum];
    int vexNum, edgeNum;
} MGraph;

bool tuopuSort(MGraph g, vector<int> &inDegree) {
    stack<int> stack;
    vector<int> res(g.vexNum, -1);//记录打印序列
    for (int i = 0; i < g.vexNum; i++)
        if (!inDegree[i])stack.push(i);
    int cnt = 0;

    while (!stack.empty()) {
        int top = stack.top();
        cout << top << " ";
        res[cnt++] = top;

        stack.pop();
        for (int i = 0; i < g.vexNum; i++) {
            if (g.edge[top][i] > 0 && g.edge[top][i] != INF) {
                inDegree[i]--;
                if (!inDegree[i]) stack.push(i);
            }
        }
    }

    if (cnt < g.vexNum) return false;
    return true;
}

int main() {

    MGraph graph;
    graph.vexNum = 5;
    graph.edgeNum = 7;
    int temp[5][5] = {
            {0,   INF, 1,   INF, 10},
            {INF, 0,   INF, 1,   5},
            {INF, 1,   0,   INF, 7},
            {INF, INF, INF, 0,   1},
            {INF, INF, INF, INF, 0}
    };


    for (int i = 0; i < graph.vexNum; i++)
        for (int j = 0; j < graph.vexNum; j++)
            graph.edge[i][j] = temp[i][j];

    return 0;
}