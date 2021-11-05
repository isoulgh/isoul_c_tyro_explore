//
// Created by Jason Luo on 2021/11/4.
//

// 快速排序是交换排序的一种，通过分而治之的策略，交换两个不相邻的元素，一次可以消去多个逆序，效率极高。
// 基本思想
// 在待排序的序列L[1~n]中，任意取一个元素pivot作为“枢轴”，凡是关键字小于枢轴的记录，均移动到该记录之前，关键字大于枢轴的记录，均移动到该记录之后，即对无序的记录进行“以此划分”，之后分别对分割所得的两个子序列“递归”调用进行快排。
#include <stdio.h>

// Notes
// ①平均时间复杂度O(nlog2n)，平均空间复杂度O(log2n)；最坏时间复杂度O(n^2)，最坏空间复杂度O(n)
// ②快速排序是不稳定的排序算法
int Partition(int A[], int low, int high);

void QuickSort(int A[], int low, int high);

int main() {
    int A[1024], n;
    printf("请输入要输入的元素个数：");
    scanf("%d", &n);
    printf("\n请输入要排序的序列：\n");
    for (int i = 1; i <= n; i++) //输入的元素从1开始，0做哨兵
        scanf("%d", &A[i]);
    printf("\n使用快速排序算法后的结果：\n");
    QuickSort(A, 1, n);
    for (int i = 1; i <= n; i++)
        printf("%d\t", A[i]);
    printf("\n");
    return 0;
}

int Partition(int A[], int low, int high) {
    int pivot = A[low];//pivot枢点
    while (low < high) {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}

