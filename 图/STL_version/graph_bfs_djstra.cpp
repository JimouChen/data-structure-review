#include<bits/stdc++.h>

using namespace std;

//用于无权图
void bfsDjstra(vector<vector<int>> graph, int start) {
    queue<int> q;
    vector<bool> visited(graph.size(), false);
    vector<int> path(graph.size(), -1);//记录前驱
    vector<int> distance(graph.size(), INT_MAX);//记录最短距离
    q.push(start);
    visited[start] = true;
    distance[start] = 0;
//    cout << start + 1 << " ";

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (auto v: graph[top]) {
            if (!visited[v]) {
//                cout << v + 1 << " ";
                visited[v] = true;
                path[v] = top;
                distance[v] = distance[top] + 1;
                q.push(v);
            }
        }
    }

    for (auto p: path)cout << p << " ";
    cout << endl;
    for (auto d:distance)cout << d << " ";
    cout << endl;
}

int main() {
    vector<vector<int>> test = {
            {1, 4},
            {0, 5},
            {3, 5, 6},
            {2, 6, 7},
            {0},
            {1, 2, 6},
            {2, 3, 5, 7},
            {3, 6}
    };
    vector<vector<int>> graph = {{4, 3, 1},
                                 {3, 2, 4},
                                 {3},
                                 {4},
                                 {}};
    bfsDjstra(test, 0);
    bfsDjstra(graph, 0);
    return 0;
}