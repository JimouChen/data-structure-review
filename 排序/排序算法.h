#include <bits/stdc++.h>

using namespace std;

/**以升序为例*/

void show(vector<int> nums) {
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << " ";
    cout << endl;
}

//插入排序
void insertSort(vector<int> &nums) {
    int i, j;
    for (i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) {
            int temp = nums[i];
            //把nums[i]插入到前面排好序到位置
            for (j = i - 1; j >= 0 && temp < nums[j]; j--)
                nums[j + 1] = nums[j];
            nums[j + 1] = temp;
        }
    }
}

//折半插入排序，即插入排序+折半查找
void biInsertSort(vector<int> &nums) {
    int i, j;
    for (i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) {
            int temp = nums[i];
            //前面的元素是已经排序好的了，只需要用折半查找找到位置，然后右移元素
            int low = 0, high = i - 1;
            while (high >= low) {
                int mid = (high + low) / 2;
                if (temp >= nums[mid]) low = mid + 1;//注意等于的情况
                else high = mid - 1;
            }
            //将low到i-1区间的元素右移
            for (j = i - 1; j >= low; j--)
                nums[j + 1] = nums[j];

            nums[low] = temp;//最后的high在low-1位置
        }
    }
}

//希尔排序
void shellSort(vector<int> &nums) {
    for (int d = nums.size() / 2; d >= 1; d /= 2) {
        for (int i = d + 1; i < nums.size(); i++) {
            if (nums[i - d] > nums[i]) {
                int temp = nums[i];
                //这一步就是运用插入排序了，不同的是步长
                int j;
                for (j = i - d; j > 0 && temp < nums[j]; j -= d)
                    nums[j + d] = nums[j];
                nums[j + d] = temp;
            }
        }
    }
}