#include <bits/stdc++.h>
using namespace std;
#define maxsize 255

typedef struct {
    char ch[maxsize];
    int length;
} String;

//复制操作，初始化一个串
void StrAssign(String &T, char *chars) {
    int i = 1;
    while (chars[i - 1] != '\0') {
        T.ch[i] = chars[i - 1];
        i++;
    }
    T.length = i - 1;
}

void getNext(String t, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;  //都是从位置1开始的
    while (i < t.length) {
        if (j == 0 || t.ch[i] == t.ch[j]) {
            i++;
            j++;
            next[i] = j;
        } else
            j = next[j];
    }
}

// next的改进
void getNextPro(String t, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;  //都是从位置1开始的
    while (i < t.length) {
        if (j == 0 || t.ch[i] == t.ch[j]) {
            i++;
            j++;
            if (t.ch[i] != t.ch[j])
                next[i] = j;
            else
                next[i] = next[j];
        } else
            j = next[j];
    }
}

int kmpIndex(String s, String t) {
    int i = 1, j = 1;
    int next[t.length + 1];
    getNextPro(t, next);  //求出next数组
    while (i <= s.length && j <= t.length) {
        if (j == 0 || s.ch[i] == t.ch[j]) {
            i++;
            j++;
        } else
            j = next[j];
    }
    if (j > t.length)
        return i - t.length;
    else
        return 0;  //匹配失败
}

int main() {
    String s, t;
    char a[] = "hellomyfriends", b[] = "friend";
    StrAssign(s, a);
    StrAssign(t, b);
    cout << kmpIndex(s, t) << endl;
    return 0;
}