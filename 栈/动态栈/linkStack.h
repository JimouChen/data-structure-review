#include <bits/stdc++.h>
using namespace std;

//动态栈其实本质就是单链表
typedef struct LNode {
    int data;
    struct LNode *next;
} * LinkStack, Lstack;

void initStack(LinkStack &s) {
    s = (LinkStack)malloc(sizeof(Lstack));
    s->next = NULL;
    s->data = -1;//初始化栈顶是-1
}

//入栈在表头插入元素
void push(LinkStack &s, int x) {
    Lstack *p = (Lstack *)malloc(sizeof(Lstack));
    p->data = x;
    p->next = s;
    s = p;
}

//出栈
void pop(LinkStack &s, int &x) {
    x = s->data;
    Lstack *temp = s;
    s = s->next;
    free(temp);
}

void show(LinkStack s) {
    Lstack *temp = s;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}