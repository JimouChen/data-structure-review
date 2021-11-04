#include <bits/stdc++.h>
using namespace std;

typedef struct BSTNode {
    int data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTTree;

//查找指定值，返回对应节点，空间复杂度O(1)
BSTNode *seachBST(BSTTree t, int key) {
    while (t && t->data != key) {
        if (t->data > key)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return t;
}

//用递归查找，空间复杂度O(h),h是深度
BSTNode *searchBSTDigui(BSTTree t, int key) {
    if (!t) return NULL;
    if (t->data == key)
        return t;
    else if (t->data > key)
        return searchBSTDigui(t->lchild, key);
    else
        return searchBSTDigui(t->rchild, key);
}

//递归插入节点，插入的节点最终一定是叶子节点
int insertNodeDiGui(BSTTree &t, int key) {
    if (t == NULL) {  //原来的树是空树
        //直接修改这个空节点
        t = (BSTNode *)malloc(sizeof(BSTNode));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return 1;
    } else if (t->data == key)
        return 0;  //不能插入重复的节点
    else if (t->data > key)
        return insertNodeDiGui(t->lchild, key);
    else
        return insertNodeDiGui(t->rchild, key);
}

//非递归实现插入节点
int insertNode(BSTTree &t, int key) {
    while (t) {
        if (t->data == key)
            return 0;
        else if (t->data > key)
            t = t->lchild;
        else
            t = t->rchild;
    }
    //现在已经找到这个叶子节点了或者一开始t就是空的根
    t = (BSTTree)malloc(sizeof(BSTNode));
    t->data = key;
    t->lchild = t->rchild = NULL;
    return 1;
}

//建立一棵二叉排序树，给定输入序列,n是个数
void createBST(BSTTree &t, int value[], int n){
    t = NULL;
    int i = 0;
    while(i<n){
        insertNode(t, value[i]);
        i++;
    }
}

int main() { return 0; }