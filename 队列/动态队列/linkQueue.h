//链队列,带头节点版本
#include <bits/stdc++.h>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

typedef struct {
    LNode *front, *rear;
} linkQueue;

void initQueue(linkQueue &q) {
    q.front = q.rear = (LNode *)malloc(sizeof(LNode));
    q.front->next = NULL;
}

bool isEmpty(linkQueue q) { return !(q.front == q.rear); }

void push(linkQueue &q, int x) {
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = x;
    p->next = NULL;
    q.rear->next = p;
    q.rear = p;
}

bool pop(linkQueue &q, int &x) {
    if (q.rear == q.front) return false;
    x = q.front->data;
    LNode *p = q.front->next;
    q.front->next = p->next;
    if (p == q.rear) {  //只有一个元素了
        q.rear = q.front;
    }
    free(p);
    return true;
}
