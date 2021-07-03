#include <bits/stdc++.h>
using namespace std;
#define maxsize 10
typedef struct {
    int data[maxsize];
    int front, rear;
} sqQueue;

// rear这里是指向队尾元素的下一个位置
// front指向队头元素
//所以牺牲一个队列里面的一个空间
void initQueue(sqQueue &q) { q.front = q.rear = 0; }

//判断队空
bool isEmpty(sqQueue q) {
    if (q.rear == q.front) return true;
    return false;
}

bool push(sqQueue &q, int x) {
    //判断满了没有
    if ((q.rear + 1) % maxsize == q.front) return false;
    q.data[q.rear] = x;
    q.rear = (q.rear + 1) % maxsize;
    return true;
}

bool pop(sqQueue &q, int &x) {
    if (q.rear == q.front) return false;
    x = q.data[q.front];
    q.front = (q.front + 1) % maxsize;
    return true;
}

//取队头元素
int getTop(sqQueue q){
    return q.data[q.front];
}
