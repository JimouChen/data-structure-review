#include <bits/stdc++.h>

using namespace std;

//t-10
//方法一
void reverse(int a[], int from, int to) {
    int cha = (to - from + 1) / 2;
    for (int i = 0; i < cha; i++) {
        int temp = a[from + i];
        a[from + i] = a[to - i];
        a[to - i] = temp;
    }
}

//第二种方法，双指针，O(n)
void reverse2(int a[], int from, int to) {
    int low = from, high = to;
    while (low <= high) {
        int temp = a[low];
        a[low++] = a[high];
        a[high--] = temp;
    }
}
//res = 4 5 6 7 1 2 3
void circleLeft(int R[], int n, int p) { // 0 < p < n
//    reverse(R, 0, p - 1);
//    reverse(R, p, n - 1);
//    reverse(R, 0, n - 1);

    reverse2(R, 0, p - 1);
    reverse2(R, p, n - 1);
    reverse2(R, 0, n - 1);
}