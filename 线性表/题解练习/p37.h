#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int data;
    struct Node *next;
} LNode, *Linklist;

Linklist initLink(Linklist &l) {
    l = (Linklist)malloc(sizeof(LNode));
    l->next = NULL;
    LNode *temp = l;
    int i = 0;
    int a[10] = {1, 2, 3, 4, 3, 5, 7, 3, 9};
    while (i < 9) {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        p->data = a[i];
        temp->next = p;
        temp = p;
        i++;
    }
    return l->next;
}

void dispLink(Linklist l) {
    Linklist p = l;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// p37-1写个递归，删除不带头节点的的链表所有值为x的元素
void deleteSame(Linklist &l, int x) {
    if (l == NULL) return;
    if (x == l->data) {
        LNode *s = l;
        l = l->next;
        free(s);
        deleteSame(l, x);
    } else
        deleteSame(l->next, x);
}

// p38-2
void deleteSameWithNode(Linklist l, int x) {
    LNode *temp = l->next, *pre = l;
    while (temp) {
        if (temp->data == x) {
            LNode *s = temp;
            pre->next = temp->next;
            temp = temp->next;
            free(s);
        } else {
            pre = temp;
            temp = temp->next;
        }
    }
}