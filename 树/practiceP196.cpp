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
void track0(BiTreeNode t) {
    if (t) {
        if (!t->left && !t->right) num++;
        if (t->left) track2(t->left);
        if (t->right) track2(t->right);
    }
}

//统计树的高度
int getHeight(BiTreeNode t) {
    if (t) {
        int left = getHeight(t->left);
        int right = getHeight(t->right);
        return right > left ? right + 1 : left + 1;
    }
    return 0;
}

//统计二叉树的宽度
int getWidth(BiTreeNode t) {
    queue<BiNode *> q;
    q.push(t);
    int width = 1;
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            BiNode *top = q.front();
            if (top->left) q.push(top->left);
            if (top->right) q.push(top->right);
            q.pop();
        }
        width = q.size() > width ? q.size() : width;
    }
    return width;
}

//从二叉树中删除所有叶节点
void deleteLeaves(BiTreeNode &t) {
    if (t) {
        if (t->left && !t->left->left && !t->left->right)
            t->left = NULL;
        if (t->right && !t->right->left && !t->right->right)
            t->right = NULL;
        deleteLeaves(t->left);
        deleteLeaves(t->right);
    }
}

//计算指定节点*p所在在的层次
int getPLevel(BiTreeNode t, BiNode *p) {
    int level = 1;
    queue<BiNode *> q;
    q.push(t);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            BiNode *top = q.front();
            if (top == p) return level;
            if (top->left) q.push(top->left);
            if (top->right) q.push(top->right);
            q.pop();
        }
        level++;
    }
    return -1;//找不到p指针
}

//p197
vector<stack<int>> path;
stack<int> s;
int sum = 0;

void getPath(int data, BiTreeNode t) {
    if (t) {
        sum += t->data;
        if (sum < data && !t->left && !t->right) {
            sum -= t->data;
            return;
        }
        if (sum < data && (t->left || t->right))
            s.push(t->data);
        if (sum == data && !t->left && !t->right) {
//            path.emplace_back(s);
            //打印
            while (!s.empty()) {
                auto top = s.top();
                cout << top << " ";
                s.pop();
            }
            cout << endl;
            sum -= t->data;
            return;
        }
        if (sum > data) {
            sum -= t->data;
            return;
        }

        getPath(data, t->left);
        getPath(data, t->right);
    }
}

int main() { return 0; }