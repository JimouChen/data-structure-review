#include "linkStack.h"

int main() {
    LinkStack s;
    initStack(s);
    for (int i = 1; i <= 5; i++) {
        push(s, i);
    }
    show(s);
    int x;
    pop(s, x);
    cout << x << endl;
    show(s);
    return 0;
}