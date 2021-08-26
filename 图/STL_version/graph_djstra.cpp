#include <bits/stdc++.h>

#define MAX 99999999
using namespace std;

//这里的edge传进去的是个邻接矩阵，带权，值就是权
void djstra(vector<vector<int>> &edge, int start) {
    //设置三个数组
    int n = edge.size();
    vector<bool> finished(n, false);//代表是否已经确定找到start到各点的最短路径
    vector<int> path(n, -1);//记录上一个点
    vector<int> distance(n, MAX);//记录起点到各点最短距离

    //初始化
    finished[start] = true;
    distance[start] = 0;
    for (int i = 0; i < n; i++) {
        distance[i] = edge[start][i];
        path[i] = (edge[start][i] == MAX || edge[start][i] == 0) ? -1 : 0;
    }


    //遍历所有顶点，找到还未确定找到最短的，且distance最小的点
    int cnt = n - 1;//循环n-1轮即可
    while (cnt--) {
        //先找到这个顶点
        int curMinVer = -1;
        int curMin = MAX;
        for (int i = 0; i < n; i++) {
            if (!finished[i] && distance[i] < curMin) {
                curMinVer = i;
                curMin = distance[i];
            }
        }
        finished[curMinVer] = true;//找到最小顶点后就是确定了它的dis值

        //遍历curMinVer的所有邻接点，判断更新距离即可
        for (int i = 0; i < n; i++) {
            if (!finished[i] && distance[i] > distance[curMinVer] + edge[curMinVer][i]) {
                distance[i] = distance[curMinVer] + edge[curMinVer][i];
                path[i] = curMinVer;
            }
        }
    }

    cout << "come from last node:" << endl;
    for (auto i: path)cout << i << " ";
    cout << endl << endl;
    cout << "shortest distance to every node:" << endl;
    for (auto i: distance)cout << i << " ";
    cout << endl;
}

int main() {
    vector<vector<int>> test = {
            {0,   10, MAX, MAX, 5},
            {MAX, 0,   1,  MAX, 2},
            {MAX, MAX, 0, 4, MAX},
            {7,   MAX, 6, 0, MAX},
            {MAX, 3,   9, 2,    0}
    };
    djstra(test, 0);//0 2 1 3 4

    return 0;
}