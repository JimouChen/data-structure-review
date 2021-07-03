#include "staticQueue.h"

int main() {
    sqQueue q;
    initQueue(q);
    for (int i = 1; i <= 5; i++) {
        push(q, i);
    }
    int x;
    while (!isEmpty(q)) {
        pop(q, x);
        cout << x << " ";
    }
    return 0;
}