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

//冒泡排序
void bubbleSort(vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        bool isExchange = false;
        for (int j = i + 1; j < nums.size(); j++)
            if (nums[i] > nums[j]) {
                isExchange = true;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
    }

}

//链表的冒泡排序
typedef struct Node {
    int data;
    struct Node *next;
} Node, *linkNode;

void linkBubble(linkNode l) {
    Node *p = l->next;
    while (p && p->next) {
        Node *k = p->next;
        while (k) {
            if (k->data < p->data) {
                int temp = p->data;
                p->data = k->data;
                k->data = temp;
            }
            k = k->next;
        }
        p = p->next;
    }
}

void testLinkBubble() {
    linkNode link = (Node *) malloc(sizeof(Node));
    Node *node1 = (Node *) malloc(sizeof(Node));
    Node *node2 = (Node *) malloc(sizeof(Node));
    Node *node3 = (Node *) malloc(sizeof(Node));
    Node *node4 = (Node *) malloc(sizeof(Node));

    node1->data = 5;
    node2->data = 2;
    node3->data = 1;
    node4->data = 4;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    link->next = node1;

    linkBubble(link);
    Node *p = link->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//快速排序
//找到正确的位置
int findPosition(int nums[], int low, int high) {
    //设置排序区间的第一个数是基准数
    int firstNum = nums[low];
    while (low < high) {
        while (low < high && nums[high] > firstNum) --high;//跳出循环时说明找到一个比基准数小的数
        nums[low] = nums[high];
        while (low < high && nums[low] < firstNum) ++low;
        nums[high] = nums[low];
    }
    //跳出循环时候，此时low = high就是基准数正确的位置
    nums[low] = firstNum;
    return low;
}

void quickSort(int nums[], int low, int high) {
    if (low < high) {
        int rightPosition = findPosition(nums, low, high);
        //分治，对正确位置两边也使用快排
        quickSort(nums, low, rightPosition - 1);
        quickSort(nums, rightPosition + 1, high);
    }
}