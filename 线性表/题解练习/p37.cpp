#include "p37.h"

int main(){
    Linklist l = initLink(l);
    dispLink(l);
    LNode *temp = l;
    deleteSame(l, 3);
    dispLink(temp);

    return 0;
}