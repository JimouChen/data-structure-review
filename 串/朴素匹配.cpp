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

//模式串的暴力匹配，找模式串的位置
int getIndex(String s, String t) {
    int i = 1, j = 1;  // i指向s，j指向模式串t
    while (i <= s.length && j <= t.length) {
        if (s.ch[i] == t.ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;  // i移动到下一个位置，回退
            j = 1;
        }
    }
    if (j > t.length)
        return i - t.length;  //此时已经匹配到了
    else
        return 0;  //匹配失败
}

void showString(String s) {
    for (int i = 1; i <= s.length; i++) cout << s.ch[i];
    cout << endl;
}
int main() {
    String s, t;
    char a[] = "howareyou", b[] = "rey";
    StrAssign(s, a);
    StrAssign(t, b);
    showString(s);
    showString(t);
    cout << getIndex(s, t) << endl;

    return 0;
}