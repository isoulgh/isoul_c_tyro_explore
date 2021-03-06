//
// Created by Jason Luo on 2021/11/4.
//
// 希尔排序是插入排序的一种，也称作缩小增量排序，其基本思想是：
// 先将待排序的序列分割成d个形如L[i,i+d,i+2d,…,i+kd]的特殊子表，分别进行直接插入排序，当整个表中的元素呈"基本有序时"，再对全体记录进行一次直接插入排序。最终得到排好序的序列。
#include <stdio.h>
// Notes
// ①时间复杂度为O(n^2)，空间复杂度为O(1)【希尔排序的时间复杂度和增量的选取有关】
// ②适用于顺序存储
// ③不是稳定的排序算法

// 使用希尔排序进行升序排列
int ShellInsert(int A[], int n);

int main() {
    int A[1024], n;
    printf("请输入要输入的元素个数：");
    scanf("%dk", &n);
    printf("\n请输入要排序的序列：\n");
    for (int i = 1; i <= n; i++) //输入的元素从1开始，0做哨兵
        scanf("%dk", &A[i]);
    printf("\n使用直接插入排序算法后的结果：\n");
    ShellInsert(A, n);
    for (int i = 1; i <= n; i++)
        printf("%d\t", A[i]);
    printf("\n");
    return 0;
}

int ShellInsert(int A[], int n) {   // 希尔排序是分组后分别进行插入排序
    int dk, i, j;   // dk是分组距离
    for (dk = n / 2; dk >= 1; dk = dk / 2) {    // 每次dk/2
        for (i = dk + 1; i <= n; i++) { // 对分组进行插入排序
            if (A[i] < A[i - dk]) {   // 可有可无
                A[0] = A[i];    // 哨兵
                for (j = i - dk; j > 0 && A[0] < A[j]; j -= dk) {   // 每项后移，并插入
                    A[j + dk] = A[j];
                }
                A[j + dk] = A[0];
            }
        }
    }
}


