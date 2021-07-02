#include <bits/stdc++.h>
using namespace std;
#define maxsize 10

typedef struct {
    int data[maxsize];
    int top;  //这里是栈顶指针
    //看情况，top也可以是栈顶指针的下一个
} Stack;

void initStack(Stack &s) { s.top = -1; }

bool isEmpty(Stack s) {
    if (s.top == -1) return true;
    return false;
}

bool push(Stack &s, int x) {
    if (s.top == maxsize - 1)  //栈满
        return false;
    s.data[++s.top] = x;
    return true;
}

//出栈元素由x带回
bool pop(Stack &s, int &x) {
    if (s.top == -1) return false;
    x = s.data[s.top--];
    return true;
}

//获取栈顶元素
bool getTop(Stack s, int &x) {
    if (s.top == -1) return false;
    x = s.data[s.top];
    return true;
}

//逻辑上的清空
void deleteStack(Stack &s) { s.top = -1; }