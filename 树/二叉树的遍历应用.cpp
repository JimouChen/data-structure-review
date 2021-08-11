#include <bits/stdc++.h>

using namespace std;

typedef struct BiNode {
    int data;
    struct BiNode *left, *right;
} BiNode, *BiTreeNode;

int sum = 0;

//从根结点到叶子结点的每条路径的权值和
void dfs(BiTreeNode root) {
    if (root) {
        cout << root->data << " ";
        sum += root->data;

        dfs(root->left);
        dfs(root->right);

        if (!root->right && !root->left)
            cout << "sum = " << sum << endl;
        sum -= root->data;
    }
}

void preOrder(BiTreeNode root) {
    if (root) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(BiTreeNode root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(BiTreeNode root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

//二叉树的层次遍历
void levelOrder(BiTreeNode t) {
    if (t) {
        queue<BiTreeNode> q;
        q.push(t);
        while (!q.empty()) {
            BiTreeNode top = q.front();
            cout << top->data << " ";
            q.pop();
            if (top->left) q.push(top->left);
            if (top->right) q.push(top->right);
        }
    }
}

//获取二叉树的深度
//其实是后序遍历的应用
int depthTree(BiTreeNode t) {
    if (t) {
        int l = depthTree(t->left);
        int r = depthTree(t->right);
        return l > r ? l + 1 : r + 1;
    }
    return 0;  //空树
}

int main() {
    BiTreeNode t = (BiTreeNode) malloc(sizeof(BiNode));
    BiTreeNode a = (BiTreeNode) malloc(sizeof(BiNode));
    BiTreeNode b = (BiTreeNode) malloc(sizeof(BiNode));
    BiTreeNode c = (BiTreeNode) malloc(sizeof(BiNode));
    BiTreeNode d = (BiTreeNode) malloc(sizeof(BiNode));
    BiTreeNode e = (BiTreeNode) malloc(sizeof(BiNode));

    t->data = 1;
    t->left = a;
    t->right = b;
    a->data = 2;
    b->data = 3;
    c->data = 6;
    b->left = NULL;
    b->right = c;
    a->left = d;
    a->right = e;
    d->data = 4;
    e->data = 5;
    d->left = NULL;
    e->left = NULL;
    d->right = NULL;
    e->right = NULL;
    c->left = NULL;
    c->right = NULL;

    levelOrder(t);
    preOrder(t);

    return 0;
}