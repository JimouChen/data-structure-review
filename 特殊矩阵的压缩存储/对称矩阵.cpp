#include <bits/stdc++.h>
using namespace std;

//把二维对称矩阵压缩成一维数组,并获取第r行第l列的值
int trans2to1(vector<vector<int>> matrix, int r, int l) {
    int len = (1 + matrix[0].size()) * matrix[0].size() / 2;
    vector<int> a(len, 0);
    int k = 0;
    for (int i = 0; i < matrix[0].size(); i++)
        for (int j = 0; j <= i; j++) a[k++] = matrix[i][j];

    return a[(r - 1) * r / 2 + l - 1];
}

int main() {
    vector<vector<int>> test = {{1, 2, 4, 7, 11},
                                {2, 3, 5, 8, 12},
                                {4, 5, 6, 9, 13},
                                {7, 8, 9, 10, 14},
                                {11, 12, 13, 14, 15}};

    int res = trans2to1(test, 4, 2);
    cout << res << endl;

    return 0;
}