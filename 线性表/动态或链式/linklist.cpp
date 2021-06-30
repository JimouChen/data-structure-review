#include "linklist.h"

int main(){
    // Linklist l = headInit(l);
    // showLinkList(l);
    Linklist l = tailInit(l);
    showLinkList(l);
    // LNode *p = searchByNum(l, 4);
    // LNode *p = searchByValue(l, 4);
    // cout<<endl<<p->data;
    // cout<<"插入值\n";
    // insertNode(l, 3, 666);
    // cout<<"删除第i个值\n";
    // deleteByNum(l, 1);
    showLinkList(l);
    // cout<<getLength(l)<<endl;
    // Linklist rv = reverseLink1(l);
    // showLinkList(rv);
    reverseLink2(l);
    showLinkList(l);
    deleteSameWithNode(l, 3);
    showLinkList(l);
    
    return 0;
}