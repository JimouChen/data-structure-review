#include <bits/stdc++.h>

using namespace std;
#define hashSize 16 //元素个数
#define p 13 //距离表长最近的质数且小于表长


typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node *has;
    int size;//记录哈希表长度
} hasTable[hashSize];

int hashFaction(int value) {
    return value % p;
}

//链地址法
bool hashSearch(hasTable hs, int key) {
    int index = hashFaction(key);
    if (!hs[index].has) return true;//找到
    node *q = hs->has->next;
    while (q) {
        if (q->data == key) return true;
        q = q->next;
    }
    return false;
}


//开放地址法——线性探测法,isElem是表示该位置有没有存放元素
bool hasSearchLinear(int table[], int key, bool isElem[]) {
    //设增量
    int di = 1;
    int index = hashFaction(key);
    if (table[index] == key) return true;
    else {
        for (int i = 0; i < hashSize; ++i) {
            index = (index + (di++)) % hashSize;
            if (table[index] == key)
                return true;
            if ((isElem[index] && table[index] != key) || (isElem[index] == false))
                continue;//下一个位置有元素就继续查下一个
        }
    }

}

//哈希表的插入赋值和上面查找是类似的，稍作改动即可
//另外，开放定址法的增量可以改动为平方探测法的增量变化
int main(){
    return 0;
}