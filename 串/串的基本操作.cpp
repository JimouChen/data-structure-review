#include <bits/stdc++.h>
using namespace std;
#define maxsize 255
typedef struct {
    char ch[maxsize];
    int length;
} String;

bool getSub(String &sub, String str, int pos, int len) {
    if (pos + len - 1 > str.length) return false;
    //一一赋值
    for (int i = pos; i <= pos + len; i++) {
        //从位置1开始存放
        sub.ch[i - pos + 1] = str.ch[i];
    }
    sub.length = len;
    return true;
}

//赋值操作，chars赋给T
void StrAssign(String &T, char *chars) {
    int i = 1;
    while (chars[i - 1] != '\0') {
        T.ch[i] = chars[i - 1];
        i++;
    }
    T.length = i;
}

//比较两个串,s>t返回大于0，<返回小于0，相同返回0
int strCmp(String s, String t) {
    int i = 1;
    while (i <= s.length && i <= t.length) {
        if (s.ch[i] != t.ch[i]) return s.ch[i] > t.ch[i];
        i++;
    }
    return s.length - t.length;
}

//取出子串的位置
int indexSub(String s, String sub) {
    int lenSub = sub.length;
    for (int i = 1; i < s.length - lenSub; i++) {
        String temp;
        getSub(temp, s, i, lenSub);
        if (strCmp(temp, sub) == 0) return i;
    }
    return 0;  //不存在返回0，0这个位置没有存放东西
}

int main() {
    String s, sub;
    char a[] = "hello world!";
    StrAssign(s, a);
    getSub(sub, s, 2, 4);
    for (int i = 1; i <= sub.length; i++) cout << sub.ch[i];
    cout << endl << strCmp(s, sub) << endl;
    cout << "子串位置：" << endl;
    cout << indexSub(s, sub) << endl;
    return 0;
}