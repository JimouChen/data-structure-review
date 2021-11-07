#include<bits/stdc++.h>

using namespace std;
#define maxVexNum 100
#define INF 99999999 //无连接的边无穷大的距离
#define MAX 99999999 //无连接的边无穷大的距离
typedef struct {
    char vex[maxVexNum];
    int edge[maxVexNum][maxVexNum];
    int vexNum, edgeNum;
} MGraph;

//找到dist的最小值
int findMinDist(int dist[], bool final[], int vNum) {
    int min = INF, minIndex = -1;
    for (int i = 0; i < vNum; i++) {
        if (!final[i] && min > dist[i]) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

//v是起点
void dijkstra(MGraph g, int v) {
    bool final[g.vexNum];
    int path[g.vexNum];
    int dist[g.vexNum];

    //初始化dist和path
    for (int i = 0; i < g.vexNum; i++) {
        final[i] = false;//不写这句也可以，默认是false
        dist[i] = g.edge[v][i];
        path[i] = (g.edge[v][i] == INF) ? -1 : 0;
    }
    final[v] = true;
    path[v] = -1;

    //进行n-1轮处理
    for (int i = 0; i < g.vexNum - 1; i++) {
        //找到未确定最短距离的且dist最小的点
        int j = findMinDist(dist, final, g.vexNum);
        cout << "j = " << j << endl;
        final[j] = true;
        //并检查它的所有邻接点，更新最小值
        for (int k = 0; k < g.vexNum; k++) {
            if (!final[k] && dist[j] + g.edge[j][k] < dist[k]) {
                dist[k] = dist[j] + g.edge[j][k];
                path[k] = j;
            }
        }
    }

    //得到path和dist后再显示处理
    for (int i = 0; i < g.vexNum; ++i) {
        cout << path[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < g.vexNum; ++i) {
        cout << dist[i] << " ";
    }

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

//    int temp[5][5] = {
//            {0,   10, MAX, MAX, 5},
//            {MAX, 0,   1,  MAX, 2},
//            {MAX, MAX, 0, 4, MAX},
//            {7,   MAX, 6, 0, MAX},
//            {MAX, 3,   9, 2,    0}
//    };

    for (int i = 0; i < graph.vexNum; i++)
        for (int j = 0; j < graph.vexNum; j++)
            graph.edge[i][j] = temp[i][j];

    floyd(graph);
    cout << endl;
//    dijkstra(graph, 0);

    return 0;
}