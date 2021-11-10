#include <bits/stdc++.h>

#define INF 9999999
using namespace std;

//s是起点，t是顶点个数
void spfa(vector<vector<int>> &graph, int s, int t, vector<int> &dist) {
    queue<int> q;
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
            if ((graph[top][i] != INF) && (i != top)) {
                if (dist[i] > dist[top] + graph[top][i]) {
                    dist[i] = dist[top] + graph[top][i];
                    if (!flag[i]) {
                        q.push(i);
                        flag[i] = true;
                    }
                }
            }
        }
    }
}

int main() {
    int t, r, p, s;
    cin >> t >> r >> p >> s;
    vector<vector<int>> graph(t, vector<int>(t, INF));
    vector<int> dist(t, INF);

    int j = t;
    while (j--) graph[j][j] = 0;

    //道路
    while (r--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = c;
    }
    //航路
    while (p--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
        graph[b - 1][a - 1] = INF;
    }

    spfa(graph, s - 1, t, dist);

    for (int i = 0; i < t; i++) {
        if (dist[i] == INF)cout << "NO PATH" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}

/*

6 3 3 4
1 2 5
3 4 5
5 6 10
3 5 -100
4 6 -100
1 3 -10

 */