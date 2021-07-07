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

/**确定完遍历的前驱和后继之后，接下来是借助前驱后继指针
 * 来实现查找线索二叉树遍历的前驱和后继节点*/

//中序线索二叉树找前驱节点
TNode *inLastNode(ThreadTree t) {
    if (t->ltag == 1) return t->l;
    //如果t->ltag == 0
    t = t->l;
    while (t->rtag == 0) t = t->r;
    return t;
}

//中序线索找后继节点
TNode *inNextNode(ThreadTree t) {
    if (t->rtag == 1) return t->r;
    //若有右节点，则下一个访问的一定是右节点的最左下节点
    t = t->r;
    while (t->ltag == 0) t = t->l;
    return t;
}

//先序找前驱
TNode *preLastNode(ThreadTree t) {
    if (t->ltag == 1)
        return t->l;
    else {
        cout << "这种情况找不到前驱" << endl;
        //这种情况一定是找不到前驱的,除非弄个三叉链表用他的父亲指针来找
        return NULL;
    }
}

//先序找后继
TNode *preLastNode(ThreadTree t) {
    if (t->rtag == 1)
        return t->r;
    else {
        if (t->l) return t->l;
        if (t->r) return t->r;
    }
}

//后序找前驱
TNode *postLastNode(ThreadTree t) {
    if (t->ltag == 1)
        return t->l;
    else {
        if (t->r) return t->r;
        if (t->l) return t->l;
    }
}

//后序找后继
TNode *postNextNode(ThreadTree t) {
    if (t->rtag == 1)
        return t->r;
    else {
        //除非给你父节点，否则找不到
        cout << "这种情况找不到后继节点" << endl;
        return NULL;
    }
}