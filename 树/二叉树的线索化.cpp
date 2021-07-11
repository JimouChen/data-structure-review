#include <bits/stdc++.h>

using namespace std;

typedef struct CueingNode {
    int data;
    struct CueingNode *lchild, *rchild;
    int ltag, rtag;
} CueingNode, *CueingTree;
CueingNode *pre = NULL;

//定义一个全局的前驱指针
void visit(CueingTree t) {
    if (!t->lchild) {
        t->lchild = pre;
        t->ltag = 1;
    }
    //右孩子不存在,且此时t已经走到了下一个节点
    //也就是t现在是pre的后继节点
    if (pre && !pre->rchild) {
        pre->rchild = t;  //右孩子指针指向后继节点
        pre->rtag = 1;
    }
    pre = t;  //这句结束后，t就指向t的下一个访问节点
}

//中序线索化遍历
void InThread(CueingTree t) {
    if (t) {
        InThread(t->lchild);
        visit(t);
        InThread(t->rchild);
    }
}

void initThread(CueingTree t) {
    pre = NULL;
    if (t) {  //非空二叉树才可以线索化
        InThread(t);
        if (pre->rchild == NULL)  //处理最后一个节点
            pre->rtag = 1;
    }
}


int main() { return 0; }