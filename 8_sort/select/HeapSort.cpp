//
// Created by Jason Luo on 2021/11/4.
//
// 基本概念：
// （1）n个关键字序列L[1~n]称为堆，当且仅当该序列满足：
// ①L(i)<=L(2i)&&L(i)<=L(2i+1)，则称该堆为小根堆
// ②L(i)>=L(2i)&&L(i)>=L(2i+1)，则称该堆为大根堆
// 在排序过程中将序列视为一棵完全二叉树的顺序存储结构。
// （2）堆的初始化
// 对所有具有双亲结点含义编号从大到小（n/2~1)做如下调整：
// ①若孩子结点都小于双亲结点，则不做调整
// ②若存在孩子结点大于双亲结点，则将最大的孩子结点与双亲结点交换，并对该孩子结点进行①②，直到出现①中情况或到叶子结点为止。
#include <stdio.h>

// Notes
// ①时间复杂度为O(nlog2n)，空间复杂度为O(1)
// ②堆排序算法是不稳定的排序算法
// ③适用于顺序存储和链式存储
void AdjustDown(int A[], int k, int n);

void BuildMaxHeap(int A[], int n);

void HeapSort(int A[], int n);

int main() {
    int A[1024], n;
    printf("请输入要输入的元素个数：");
    scanf("%d", &n);
    printf("\n请输入要排序的序列：\n");
    for (int i = 1; i <= n; i++) //输入的元素从1开始，0做哨兵
        scanf("%d", &A[i]);
    printf("\n使用堆排序算法后的结果：\n");
    HeapSort(A, n);
    for (int i = 1; i <= n; i++)
        printf("%d\t", A[i]);
    printf("\n");
    return 0;
}

void BuildMaxHeap(int A[], int n) {
    int temp, i, j;
    for (int i = n / 2; i > 0; i--) {
        AdjustDown(A, i, n);
    }
}

void AdjustDown(int A[], int k, int n) {
    A[0] = A[k];
    for (int i = 2 * k; i <= n; i *= 2) {
        if (i < n && A[i] < A[i + 1]) i++;
        if (A[0] >= A[i]) break;
        else {
            A[k] = A[i];
            k = i;
        }

    }
    A[k] = A[0];//插入
}

void HeapSort(int A[], int n) {
    BuildMaxHeap(A, n);
    for (int i = n; i > 0; i--) {
        int t = A[1];
        A[1] = A[i];
        A[i] = t;
        AdjustDown(A, 1, i - 1);
    }
}

