#include "staticList.h"

int main() {
    LinearList l;
    for (int i = 0; i < 10; i++) {
        insert(l, i, i + 1);
    }
    showList(l);
    // insert(l, 2, 233);
    int e;
    deleteElem(l, 9, e);
    cout<<e<<endl;
    showList(l);

    return 0;
}