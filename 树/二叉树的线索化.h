#include <bits/stdc++.h>
using namespace std;

typedef struct TNode {
    int data;
    struct TNode *l, *r;
    int ltag, rtag;
} TNode, *ThreadTree;

//先序线索化
void preThread(ThreadTree t, ThreadTree &pre) {
    if (t) {
        if (!t->l) {
            t->l = pre;
            t->ltag = 1;
        }
        if (pre && !t->r) {
            pre->r = t;
            pre->rtag = 1;
        }
        pre = t;
        //先序一定要判断，中后序不用
        if (t->l == 0) preThread(t->l, pre);
        preThread(t->r, pre);
    }
}

//中序线索化
void inThread(ThreadTree t, ThreadTree &pre) {
    if (t) {
        inThread(t->l, pre);
        if (!t->l) {
            t->l = pre;
            t->ltag = 1;
        }
        if (pre && !t->r) {
            pre->r = t;
            pre->rtag = 1;
        }
        pre = t;
        inThread(t->r, pre);
    }
}

//后序线索化
void postThread(ThreadTree t, ThreadTree &pre) {
    if (t) {
        postThread(t->l, pre);
        postThread(t->r, pre);
        if (!t->l) {
            t->l = pre;
            t->ltag = 1;
        }
        if (pre && !t->r) {
            pre->r = t;
            pre->rtag = 1;
        }
        pre = t;
    }
}

//中序/先序线索化的创建
void createThreadTree(ThreadTree t) {
    ThreadTree pre = NULL;
    if (t) {
        preThread(t, pre);
        // inThread(t, pre);
        pre->r = NULL;  //先序最后一个一定是指向叶子节点
        pre->rtag = 1;
    }
}

//后序线索化的创建
void postCreateThread(ThreadTree t) {
    ThreadTree pre = NULL;
    if (t) {
        postThread(t, pre);
        if (pre->r == NULL) {  //后序最后一个可能是有右节点的
            pre->rtag = 1;
        }
    }
}