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

void testCircleLeft() {
    int R[] = {1, 2, 3, 4, 5, 6, 7};
    circleLeft(R, 7, 3);
    for (int i = 0; i < 7; i++)cout << R[i] << " ";
    cout << endl;
}

//t-11
int getMidNum(int a[], int b[], int n) {
    //不相交的情况
    if (a[0] >= b[n - 1]) return a[0];
    if (b[0] >= a[n - 1]) return b[0];

    int c[n * 2];
    int al = 0, bl = 0, j = 0;
    while (al < n && bl < n) {
        if (a[al] <= b[bl]) c[j++] = a[al++];
        else c[j++] = b[bl++];
    }
    while (al < n)c[j++] = a[al++];
    while (bl < n)c[j++] = b[bl++];
    return c[2 * n / 2];
}

void testGetMidNum() {
    int a[] = {1, 2, 3, 4, 5};//01233 45567
//    int b[] = {0, 3, 5, 6, 7};
    int b[] = {7, 8, 9, 10, 11};
    cout << getMidNum(a, b, 5) << endl;
}
