#include <bits/stdc++.h>
using namespace std;
#define maxsize 50
typedef struct {
    char data[maxsize];
    int top;  //栈顶指针
} SqStack;

void initStack(SqStack &s) { s.top = -1; }

bool push(SqStack &s, char c) {
    if (s.top == maxsize) return false;
    s.data[++s.top] = c;
    return true;
}

bool pop(SqStack &s, char &c) {
    if (s.top == -1) return false;
    c = s.data[s.top--];
    return true;
}

bool isEmpty(SqStack s) {
    if (s.top == -1) return true;
    return false;
}
int getLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

//括号匹配
bool bracketCheck(char str[]) {
    SqStack s;
    initStack(s);

    for (int i = 0; i < getLength(str); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(s, str[i]);
        } else {
            if (isEmpty(s)) return false;
            char temp;
            pop(s, temp);
            if ((temp == '(') && (str[i] != ')')) return false;
            if ((temp == '[') && (str[i] != ']')) return false;
            if ((temp == '{') && (str[i] != '}')) return false;
        }
    }
    return isEmpty(s);
}
int main() {
    char str[] = "{[(())]}";
    if (bracketCheck(str))
        cout << "匹配成功" << endl;
    else
        cout << "匹配失败" << endl;

    return 0;
}