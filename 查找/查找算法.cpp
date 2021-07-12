#include <bits/stdc++.h>

using namespace std;

//顺序查找
int orderSearche(vector<int> nums, int key) {
    nums[0] = key;//哨兵
    int i;
    for (i = nums.size() - 1; nums[i] != key; i--);
    return i;
}

//二分查找,nums是升序序列
int biSearch(vector<int> nums, int key) {
    int low = 0, high = nums.size() - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key > nums[mid])
            low = mid + 1;
        else if (key < nums[mid])
            high = mid - 1;
        else return mid;//找到
    }
    return -1;
}

int main() {
    vector<int> test{1,3,4,6,7,9,12};
    cout<<biSearch(test, 9);
    return 0;
}