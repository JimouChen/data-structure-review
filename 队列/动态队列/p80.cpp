#include <bits/stdc++.h>
using namespace std;
// p37-4
typedef struct node {
    int data;
    struct node *next;
} LNode;

typedef struct {
    LNode *rear, *front;
} LinkQueue;

void init(LinkQueue &q) {
    q.front = q.rear = NULL;
    q.rear->next = q.front;
}
void enQueue(LinkQueue &q, int x) {
    if (q.rear->next == q.front) {
        //队满
        LNode *p = (LNode *)malloc(sizeof(LNode));
        p->data = x;
        q.rear->next = p;
        q.rear = p;
        q.rear->next = q.front;
    } else {
        q.rear->next->data = x;
        q.rear = q.rear->next;
    }
}

bool deQueue(LinkQueue &q, int &x) {
    if (q.rear == q.front) {
        return false;  //队空
    }
    x = q.front->data;
    q.front = q.front->next;
    return true;
}

int main() { return 0; }