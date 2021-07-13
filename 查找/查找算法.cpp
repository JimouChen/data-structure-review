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

//二分查找的递归写法
int biSearchDG(vector<int> &nums, int low, int high, int key) {
    if (low > high) return 0;
    int mid = (low + high) / 2;

    if (key > nums[mid])
        return biSearchDG(nums, mid + 1, high, key);
    else if (key < nums[mid])
        return biSearchDG(nums, low, mid - 1, key);
    else
        return mid;
}

int main() {
    vector<int> test{1, 3, 4, 6, 7, 9, 12};
    cout << biSearch(test, 9) << endl;
    cout << biSearchDG(test, 0, test.size() - 1, 9);
    return 0;
}