#include <bits/stdc++.h>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *Linklist;

//头插法创建
Linklist headInit(Linklist &l) {
    l = (Linklist)malloc(sizeof(LNode));
    l->next = NULL;
    LNode *s;
    int x;
    cout << "输入数据值：9999是结束" << endl;
    cin >> x;
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = l->next;
        l->next = s;
        cout << "请输入下一个值：" << endl;
        cin >> x;
    }
    return l;
}

//尾插法创建
Linklist tailInit(Linklist &l) {
    l = (Linklist)malloc(sizeof(LNode));
    l->next = NULL;
    LNode *s, *temp = l;
    int x;
    cout << "输入数据值：9999是结束" << endl;
    cin >> x;
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        temp->next = s;
        temp = s;
        cout << "请输入下一个值：" << endl;
        cin >> x;
    }
    temp->next = NULL;
    return l;
}

//按序号查找值，从1开始
LNode *searchByNum(Linklist l, int i) {
    //开始之前可以去判断一下i的范围合理
    int j = 1;
    LNode *temp = l->next;
    while (temp) {
        if (i == j) return temp;
        temp = temp->next;
        j++;
    }
    return NULL;
}

//按值查找
LNode *searchByValue(Linklist l, int e) {
    LNode *temp = l->next;
    while (temp) {
        if (temp->data == e) return temp;
        temp = temp->next;
    }
    return NULL;
}

//在第i个位置插入节点,i从1开始
bool insertNode(Linklist &l, int i, int e) {
    if (i <= 0) return false;
    //需要找到插入位置的前一个节点
    LNode *temp = l;
    int j = 1;
    while (temp) {
        if (i == j) {
            // LNode *p = temp;
            LNode *s = (LNode *)malloc(sizeof(LNode));
            s->data = e;
            s->next = temp->next;
            temp->next = s;
        }
        temp = temp->next;
        j++;
    }
    return true;
}

//删除第i个位置的节点，1开始
bool deleteByNum(Linklist &l, int i) {
    if (i <= 0) return false;
    LNode *temp = l;
    int j = 0;
    //需要找到删除节点的前一个节点
    while (temp) {
        if (i - 1 == j) {
            LNode *s = temp->next;
            temp->next = s->next;
            free(s);
            return true;
        }
        temp = temp->next;
        j++;
    }
    return false;
}

int getLength(Linklist l) {
    int length = 0;
    LNode *temp = l->next;
    while (temp) {
        length++;
        temp = temp->next;
    }
    return length;
}
void showLinkList(Linklist l) {
    LNode *temp = l->next;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}