#include <bits/stdc++.h>

using namespace std;

int find(vector<int> &uSet, int x);

void unionSet(vector<int> uSet, int x, int y) {
    //先找到x的祖先,把x的祖先作为y的祖先
    int grandFa = find(uSet, x);
    uSet[y] = grandFa;
}

int find(vector<int> &uSet, int x) {
    //这里传进来的uSet是还没有更新祖先的
    if (x == uSet[x]) return x;
    else {
        int grandFa = find(uSet, uSet[x]);
        uSet[x] = grandFa;//更新，这样下次就省去查找
        return grandFa;
    }
}

vector<int> initUnion(int n) {
    vector<int> unionSet(n);
    for (int i = 0; i < n; i++) unionSet[i] = i;
    return unionSet;
}


int main() {


    return 0;
}