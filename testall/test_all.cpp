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

//二叉树中序遍历非递归做法
void noDGInOrder(BiTreeNode t) {
    stack<BiNode *> stack;
    BiTreeNode p = t;//遍历指针p
    while (p || !stack.empty()) {
        if (p) {//如果有左孩子就先入栈
            stack.push(p);
            p = p->left;
        } else {
            //没有左孩子，此时已经到底了
            //出栈并访问,转向访问该出栈节点的右子树
            p = stack.top();
            stack.pop();
            cout << p->data << " ";
            //如果有右孩子就入栈
            p = p->right;
        }
    }
}

// 非递归先序遍历，类似中序
void noDGPreOrder(BiTreeNode t) {
    stack<BiNode *> stack;
    BiTreeNode p = t;
    while (p || !stack.empty()) {
        if (p) {
            //先序先访问
            cout << p->data << " ";
            stack.push(p);
            p = p->left;
        } else {
            //访问右子树
            p = stack.top();
            stack.pop();
            p = p->right;
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

int wpl = 0;

void dfsWPL(BiTreeNode t, int depth) {
    if (t) {
        if (!t->left && !t->right)
            wpl += t->data * depth;
        dfsWPL(t->left, depth + 1);
        dfsWPL(t->right, depth + 1);
    }
}

void levelWPL(BiTreeNode t) {
    queue<BiNode *> q;
    q.push(t);
    int level = 0;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (!top->left && !top->right) {
            level--;
            wpl += top->data * level;
        }
        if (top->left) q.push(top->left);
        if (top->right) q.push(top->right);
        level++;
    }
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

stack<int> s;
//int sum = 0;

void getPath(int data, BiTreeNode t) {
    if (t) {
        sum += t->data;
        if ((sum < data && !t->left && !t->right) || sum > data){
            sum -= t->data;
            return;
        }

        if (sum < data && (t->left || t->right))
            s.push(t->data);
        if (sum == data && !t->left && !t->right) {
            s.push(t->data);
//            path.emplace_back(s);
            //打印
            while (!s.empty()) {
                auto top = s.top();
                cout << top << " ";
                s.pop();
            }
            cout << endl;
            sum = 0;
            return;
        }


        getPath(data, t->left);
        getPath(data, t->right);
    }
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


    getPath(10, t);
//    cout << getPLevel(t, b) << endl;
//    levelOrder(t);
//    cout << endl;
//    preOrder(t);
//    cout << endl;
//    inOrder(t);
//    cout << endl;
//    noDGInOrder(t);
//    cout << endl;
//    noDGPreOrder(t);

//    dfsWPL(t, 1);
//    levelWPL(t);
//    cout << wpl;
//    deleteLeaves(t);
//    cout << getWidth(t);

    return 0;
}