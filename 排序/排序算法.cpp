#include "排序算法.h"

int main() {
    vector<int> test = {2, 1, 6, 4, 3, 76, 50, 33};
//    insertSort(test);
    biInsertSort(test);
    show(test);

    return 0;
}