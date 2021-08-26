#include<bits/stdc++.h>

using namespace std;

//graph = [[4,3,1],[3,2,4],[3],[4],[]]
void bfs(vector<vector<int>> &graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    cout << start << " ";

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        //遍历到top的所有邻接点
        for (int v : graph[top]) {
            if (!visited[v]) {
                cout << v << " ";
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {{4, 3, 1},
                                 {3, 2, 4},
                                 {3},
                                 {4},
                                 {}};
    bfs(graph, 0);
    return 0;
}