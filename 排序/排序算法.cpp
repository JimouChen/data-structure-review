#pragma once

#include "排序算法.h"

int main() {
    vector<int> test = {0, 2, 1, 6, 4, 3, 76, 50, 33};
    vector<int> test2 = {0, 2, 1, 6, 4, 3, 76, 50, 33};
    int nums[10] = {0, 87, 45, 78, 32, 17, 65, 53, 9};
//    insertSort(test);
//    biInsertSort(test);
//    shellSort(test);
//    bubbleSort(test);
    selectSort(test);
    show(test);
//    testLinkBubble();

//    quickSort(nums, 0, 8);
//    for (int i = 0; i < 9; ++i)
//        cout << nums[i] << " ";
//    cout << endl;

    heapSort(nums, 8);
    for (int i = 1; i < 9; ++i)
        cout << nums[i] << " ";
    cout << endl;
    vector<int> t1 = {1, 2, 4, 6, 9, 19};
    vector<int> t2 = {0, 3, 5, 6, 8, 15, 23, 99};

    vector<int> res = mergeSortW(t1, t2);
    show(res);

    int t3[10] = {7, 4, 6, 3, 1, 2, 98, 32, 11, 0};
    mergeSort(t3, 0, 9);
    for (int i = 0; i < 10; ++i)
        cout << t3[i] << " ";
    cout << endl;

    return 0;
}