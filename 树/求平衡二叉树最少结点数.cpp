#include <bits/stdc++.h>
using namespace std;

//求高度为h的平衡二叉树的最少结点数
int getMinNodeNum(int h) {
    vector<int> n(h + 3);
    n[0] = 0;
    n[1] = 1;
    n[2] = 2;
    for (int i = 3; i <= h; i++) n[i] = n[i - 1] + n[i - 2] + 1;
    return n[h];
}

int main() {
    cout << getMinNodeNum(5) << endl;
    return 0;
}