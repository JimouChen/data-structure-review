#pragma once

#include "排序算法.h"

int main() {
    vector<int> test = {0, 2, 1, 6, 4, 3, 76, 50, 33};
    vector<int> test2 = {0, 2, 1, 6, 4, 3, 76, 50, 33};
    int nums[9] = {10, 2, 1, 6, 4, 3, 76, 50, 33};
//    insertSort(test);
//    biInsertSort(test);
//    shellSort(test);
    bubbleSort(test);
    show(test);
//    testLinkBubble();

    quickSort(nums, 0, 8);
    for (int i = 0; i < 9; ++i)
        cout << nums[i] << " ";
    cout << endl;


    return 0;
}