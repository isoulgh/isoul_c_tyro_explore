//
// Created by Jason Luo on 2021/11/4.
//
// 冒泡排序是交换排序的一种，其基本思想是：假设待排序的序列长度为n,从后往前（从前往后）两两比较相邻元素的值，若为逆序（当i<j时，A[j]>A[i]，称逆序），则交换他们直到序列比较结束。
// 一次冒泡会将一个元素放在它最终的位置上，以后比较时不用比较该元素。
#include <stdio.h>
// Notes
// ①时间复杂度为O(n^2)，空间复杂度为O(1)
// ②适用于顺序存储和连式存储
// ③冒泡排序是稳定的排序算法

// 使用冒泡排序进行升序排列
void BubbleSort(int A[], int n);

int main() {
    int A[1024], n;
    printf("请输入要输入的元素个数：");
    scanf("%dk", &n);
    printf("\n请输入要排序的序列：\n");
    for (int i = 1; i <= n; i++) //输入的元素从1开始，0做哨兵
        scanf("%dk", &A[i]);
    printf("\n使用冒泡排序算法后的结果：\n");
    BubbleSort(A, n);
    for (int i = 1; i <= n; i++)
        printf("%d\t", A[i]);
    printf("\n");
    return 0;
}

void BubbleSort(int A[], int n) {
    int flag, t;
    for (int i = 1; i <= n; i++) {//趟数
        flag = 0;
        for (int j = n - 1; j > i; j--) {//每趟的次数
            if (A[j - 1] > A[j]) {//逆序交换
                t = A[j - 1];
                A[j - 1] = A[j];
                A[j] = t;
                flag = 1;
            }

        }
        if (flag == 0)//若未被交换，则序列有序
            return;
    }
}


