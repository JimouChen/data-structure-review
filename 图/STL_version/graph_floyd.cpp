#include<bits/stdc++.h>

#define INF 99999999
using namespace std;

void floyd(vector<vector<int>> &graph) {
    vector<vector<int>> a = graph;
    vector<vector<int>> path(a.size(), vector<int>(a.size()));//记录中转点

    for (int k = 0; k < graph.size(); k++)
        for (int i = 0; i < graph.size(); i++)
            for (int j = 0; j < graph.size(); j++) {
                if (a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    path[i][j] = k;
                }
            }

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

}

int main() {
    vector<vector<int>> temp = {
            {0,   INF, 1,   INF, 10},
            {INF, 0,   INF, 1,   5},
            {INF, 1,   0,   INF, 7},
            {INF, INF, INF, 0,   1},
            {INF, INF, INF, INF, 0}
    };
    vector<vector<int>> graph(temp.size(), vector<int>(temp.size()));

    for (int i = 0; i < graph.size(); i++)
        for (int j = 0; j < graph.size(); j++)
            graph[i][j] = temp[i][j];
    floyd(graph);

    return 0;
}

/*
 0 2 1 3 4
99999999 0 99999999 1 2
99999999 1 0 2 3
99999999 99999999 99999999 0 1
99999999 99999999 99999999 99999999 0
 */