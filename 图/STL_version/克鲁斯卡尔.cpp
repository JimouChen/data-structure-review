#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<vector<int>, int> &a, pair<vector<int>, int> &b) {
    return a.second < b.second;
}

vector<pair<vector<int>, int>> res;//最小生成树

vector<pair<vector<int>, int>> Kruscal(vector<pair<vector<int>, int>> &graph, int verNum) {
    vector<bool> isAdd(verNum, false);//是否已经加入最小生成树
    sort(graph.begin(), graph.end(), cmp);
    res.emplace_back(graph[0]);
    isAdd[graph[0].first[0]] = isAdd[graph[0].first[1]] = true;

    for (const auto &item: graph) {
        if (res.size() == verNum - 1) break;
        if (isAdd[item.first[0]] && isAdd[item.first[1]])
            continue;
        else {
            res.emplace_back(item);
        }
    }
    return res;
}

int main() {
    vector<pair<vector<int>, int>> graph = {{{0, 1}, 6},
                                            {{0, 2}, 4},
                                            {{0, 3}, 2},
                                            {{1, 2}, 2},
                                            {{1, 5}, 1},
                                            {{2, 4}, 1},
                                            {{2, 5}, 5},
                                            {{3, 4}, 3}};


    Kruscal(graph, 6);
    for (const auto &item: res) {
        cout << "边：" << item.first[0] << "---" << item.first[1] << "  值:" << item.second << endl;
    }

    return 0;
}