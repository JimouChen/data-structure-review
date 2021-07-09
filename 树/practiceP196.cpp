#include <bits/stdc++.h>
using namespace std;

typedef struct BiNode {
    int data;
    struct BiNode *left, *right;
} BiNode, *BiTreeNode;

//统计度为1的节点
int num = 0;
void track1(BiTreeNode t) {
    if (t) {
        if ((t->left && !t->right) || (t->right && !t->left)) num++;
        if (t->left) track1(t->left);
        if (t->right) track1(t->right);
    }
}

//统计度为2的节点
void track2(BiTreeNode t) {
    if (t) {
        if (t->left && t->right) num++;
        if (t->left) track2(t->left);
        if (t->right) track2(t->right);
    }
}

//统计度为0的节点
void track2(BiTreeNode t) {
    if (t) {
        if (!t->left && !t->right) num++;
        if (t->left) track2(t->left);
        if (t->right) track2(t->right);
    }
}

int main() { return 0; }