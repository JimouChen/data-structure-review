#include <bits/stdc++.h>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

typedef struct {
    LNode *front, *rear;
} linkQueue;

void init(linkQueue &q) { q.front = q.rear = NULL; }

bool isEmpty(linkQueue q) { return !(q.front == NULL); }

void push(linkQueue &q, int x) {
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = x;
    p->next = NULL;
    //插入时分情况
    //如果是空队列的话
    if (q.front == NULL) {
        q.front = q.rear = p;
    } else {
        q.rear->next = p;
        q.rear = p;
    }
}

bool pop(linkQueue &q, int &x) {
    if (q.front == NULL) return false;
    LNode *p = q.front;
    x = p->data;
    //看看是不是pop出的是不是只剩最后一个的情况
    //如果是只剩最后一个元素
    if (q.front == NULL) {
        q.front = q.rear = NULL;
    } else {
        q.front = p->next;
    }
    free(p);
    return true;
}