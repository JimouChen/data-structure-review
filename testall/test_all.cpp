#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
        unordered_map<int, vector<int>> map;
        int firstNum = 0;
        for (int i = 0; i < adjacentPairs.size(); i++) {
            map[adjacentPairs[i][0]].emplace_back(adjacentPairs[i][1]);
            map[adjacentPairs[i][1]].emplace_back(adjacentPairs[i][0]);
        }
        //找到第一个元素
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second.size() == 1) {
                firstNum = it->first;
                break;
            }
        }
        vector<int> res(map.size());
        //加入第一个元素
        res[0] = firstNum;
        res[1] = map[firstNum][0];
        for (int i = 2; i < map.size(); i++) {
            if (map[res[i - 1]][0] != res[i - 2])
                res[i] = map[res[i - 1]][0];
            else res[i] = map[res[i - 1]][1];
        }
        return res;
    }
};

int main() {
    cout<<pow(2, 3);
    return 0;
}