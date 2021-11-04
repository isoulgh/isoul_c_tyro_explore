//
// Created by Jason Luo on 2021/11/4.
//
// 折半插入排序是插入排序的一种情况，其效率比直接插入排序，其实现过程和折半查找类似。
#include<stdio.h>
// Notes
// ①时间复杂度为O(n^2)，空间复杂度为O(1)
// ②是稳定的排序算法
// ③适用于顺序查找

// 使用折半插入排序进行升序排列
void BinsertSort(int A[], int n) {
    int i, j;
    int low, high, mid;
    for (int i = 2; i <= n; i++) {
        A[0] = A[i];   //哨兵
        low = 1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] > A[0])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (int j = i - 1; j >= high + 1; j--)
            A[j + 1] = A[j];
        A[high + 1] = A[0];
        //A[low]=A[0];
    }
}

int main() {
    int A[1024], n;
    printf("请输入要输入的元素个数：");
    scanf("%d", &n);
    printf("\n请输入要排序的序列：\n");
    for (int i = 1; i <= n; i++) //输入的元素从1开始，0做哨兵
        scanf("%d", &A[i]);
    printf("\n使用直接插入排序算法后的结果：\n");
    BinsertSort(A, n);
    for (int i = 1; i <= n; i++)
        printf("%d\t", A[i]);
    printf("\n");
    return 0;
}