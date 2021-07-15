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
            //把nums[i]插入到前面排好序的位置
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

//简单选择排序
void selectSort(vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        int min = i;//记录最小值的下标
        for (int j = i + 1; j < nums.size(); j++)
            if (nums[min] > nums[j])min = j;

        //交换
        if (min != i) {
            int temp = nums[min];
            nums[min] = nums[i];
            nums[i] = temp;
        }
    }
}

//堆排序,以大根堆排序为例，nums长度是len+1
void heapAdjust(int nums[], int root, int len);

//建立大根堆,O(n)
void buildMaxHeap(int nums[], int len) {
    //从nums[]中第len/2个根结点开始，逐渐向前面堆根结点移动调整堆
    for (int i = len / 2; i > 0; --i)
        heapAdjust(nums, i, len);
}

//这里设置nums[0]来存放每次比较的根结点,O(log2n)
void heapAdjust(int nums[], int root, int len) {
    nums[0] = nums[root];//nums[0]暂存根结点
    //每次都先从根结点的左孩子开始,一直下坠到父结点大于孩子结点
    for (int i = 2 * root; i <= len; i *= 2) {
        //如果左孩子小于右孩子，就拿右孩子和父结点比较
        if (i < len && nums[i] < nums[i + 1]) i++;
        //如果父结点本来就比左右孩子都大，即符合，所以不用交换
        if (nums[0] >= nums[i]) break;
        else {
            nums[root] = nums[i];
            root = i;//根结点的位置就到来最大的孩子，继续下坠判断，等待下一步把nums[i]覆盖
        }
    }
    nums[root] = nums[0];
}

//O(nlog2n)
void heapSort(int nums[], int len) {
    buildMaxHeap(nums, len);
    for (int i = len; i > 1; --i) {
        //交换首尾
        swap(nums[i], nums[1]);
        heapAdjust(nums, 1, i - 1);//每次都要调整成大根堆
    }
}

//外部的归并排序
vector<int> mergeSortW(vector<int> nums1, vector<int> nums2) {
    int i = 0, j = 0, k = 0;
    vector<int> res(nums1.size() + nums2.size());
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] > nums2[j])
            res[k++] = nums2[j++];
        else
            res[k++] = nums1[i++];
    }
    //剩下的直接赋值到res
    while (i < nums1.size())res[k++] = nums1[i++];
    while (j < nums2.size())res[k++] = nums2[j++];

    return res;
}

#define lenA 10
int *b = (int *) malloc(sizeof(int) * lenA);//辅助数组

//归并排序，同一个数组内部,mid指向的是a中第一个有序序列的最后一个下标
//也就是对low -> mid 和 mid+1 -> high进行归并
void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k;
    //先把a暂存到b
    for (k = 0; k <= high; ++k)
        b[k] = a[k];
    k = i;//k = low
    //在b内操作，处理后再赋值回a
    while (i <= mid && j <= high) {
        if (b[i] <= b[j])
            a[k++] = b[i++];
        else a[k++] = b[j++];
    }

    //对b剩下的赋值到a
    while (i <= mid) a[k++] = b[i++];
    while (j <= high) a[k++] = b[j++];
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (high + low) / 2;
        //分别对左右两个区间进行合并排序
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);//归并
    }
}