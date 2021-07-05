#include <bits/stdc++.h>
using namespace std;
//实现起来和对称矩阵差不多，只是压缩后的一维数组多加一个存储单元
//假设这里是行存储，存在上三角，常数在下三角
int getTriangle(vector<vector<int>> matrix, int i, int j) {
    int n = matrix[0].size();
    int len = (n + 1) * n / 2 + 1;
    int k = 0;
    vector<int> a(len, 0);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) a[k++] = matrix[i][j];

    a[k] = matrix[n - 1][0];
    return a[(2 * n + 2 - i)*(i - 1) / 2 + j - i];
}
int main() {
    vector<vector<int>> m = {{1, 2, 3}, 
                             {0, 4, 5},
                             {0, 0, 6}};

    cout<<getTriangle(m, 2, 3) << endl;
    return 0;
}