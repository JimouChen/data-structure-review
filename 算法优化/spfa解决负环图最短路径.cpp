#include <bits/stdc++.h>

#define INF 9999999
using namespace std;
typedef long long ll;

//s是起点，t是顶点个数
vector<int> spfa(vector<vector<int>> &graph, int s) {
    int t = graph.size();
    vector<int> dist(t, INF);//记录s到每个点最短路径
    queue<int> q;
    vector<int> pre(t);//前驱节点
    vector<bool> flag(t, false);
    dist[s] = 0;
    q.push(s);
    flag[s] = true;
    while (!q.empty()) {
        int top = q.front();
        flag[top] = false;
        q.pop();
        //遍历top的邻接点
        for (int i = 0; i < t; i++) {
            if ((graph[top][i] != INF) && (i != top))
                if (dist[i] > dist[top] + graph[top][i]) {
                    dist[i] = dist[top] + graph[top][i];
                    pre[i] = top;
                    if (!flag[i]) {
                        q.push(i);
                        flag[i] = true;
                    }
                }
        }
    }
    return dist;
}

int main() {

    return 0;
}
