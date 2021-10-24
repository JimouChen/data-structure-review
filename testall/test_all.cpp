#include<bits/stdc++.h>

using namespace std;
#define maxVexNum 100
#define INF 99999999 //无连接的边无穷大的距离
typedef struct {
    char vex[maxVexNum];
    int edge[maxVexNum][maxVexNum];
    int vexNum, edgeNum;
} MGraph;

//找到dist的最小值
int findMinDist(int dist[], bool final[], int vNum) {
    int min = INF;
    for (int i = 0; i < vNum; i++) {
        if (!final[i] && min > dist[i])
            min = dist[i];
    }
    return min;
}

//v是起点
void dijkstra(MGraph g, int v) {
    bool final[g.vexNum];
    int path[g.vexNum];
    int dist[g.vexNum];

    final[v] = true;
    dist[v] = 0;
    path[v] = -1;

    //初始化dist和path
    for (int i = 0; i != v && i < g.vexNum; i++) {
        final[i] = false;//不写这句也可以，默认是false
        dist[i] = g.edge[v][i];
        path[i] = (g.edge[v][i] == INF) ? -1 : 0;
    }

    //进行n-1轮处理
    for (int i = 0; i != v && i < g.vexNum; i++) {
        //找到未确定最短距离的且dist最小的点
        int j = findMinDist(dist, final, g.vexNum);
        final[j] = true;
        //并检查它的所有邻接点，更新最小值
        for (int k = 0; k != v && k != j && k < g.vexNum; k++) {
            if (g.edge[j][k] && g.edge[j][k] != INF) {
                if (!final[k] && dist[i] + g.edge[i][j] < dist[j]) {
                    dist[j] = dist[i] + g.edge[i][j];
                    path[k] = j;
                }
            }
        }
    }

    //得到path和dist后再显示处理
}

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

    floyd(graph);


    return 0;
}

