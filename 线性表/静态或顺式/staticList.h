#include <bits/stdc++.h>
using namespace std;
#define maxsize 50

typedef struct {
    int data[maxsize];
    int length;
} LinearList;

void initList(LinearList &l) { l.length = 0; }
int getLength(LinearList l) { return l.length; }

//第i位置插入，0开始
bool insert(LinearList &l, int i, int e) {
    if (i > l.length || i < 0) {
        return false;
    }
    for (int j = l.length; j > i; j--) {
        l.data[j] = l.data[j - 1];
    }
    //到达i这个位置，赋值
    l.data[i] = e;
    l.length++;
    return true;
}

bool deleteElem(LinearList &l, int i, int &e) {
    if (i < 0 || i >= l.length) {
        return false;
    }
    e = l.data[i];
    for (int j = i; j < l.length - 1; j++) {
        l.data[j] = l.data[j + 1];
    }
    l.length--;
    //带回
    return true;
}
void showList(LinearList l) {
    for (int i = 0; i < l.length; i++) {
        cout << l.data[i] << " ";
    }
    cout << endl;
}

//返回找到的位置
int seaerch(int a, LinearList l) {
    for (int i = 0; i < l.length; i++) {
        if (l.data[i] == a) {
            return i;
        }
    }
    return -1;  //找不到返回-1
}
