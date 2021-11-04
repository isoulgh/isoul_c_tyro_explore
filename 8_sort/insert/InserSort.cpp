//
// Created by Jason Luo on 2021/11/4.
//
// 直接插入排序是插入排序的一种，插入排序是每次将一个待排序的序列插入到一个前面已经排好序的子序列当中。
// 直接插入排序的算法思想如下：
// （1）查找出L[i]在L[1~i-1]中的插入位置k；
// （2）将L[k~i-1]中所有的元素全部向后移一个位置；
// （3）将L[i]复制到L[k]中。
#include <stdio.h>
// Notes
// ①时间复杂度为O(n^2)
// ②适用于顺序存储和链式存储(上面的代码是顺序存储)
// ③是稳定的排序算法

// 使用插入排序进行升序排列
int InsertSort(int A[], int n) {  /* 自定义函数 InsertSort()*/
    int i, j;
    for (i = 2; i <= n; i++) { //数组下标从2开始，A[0]做监视哨，A[1]一个数据无可比性
        A[0] = A[i];    //A[0]为哨兵
        for (j = i - 1; A[0] < A[j]; j--) {
            A[j + 1] = A[j];    //元素后移
        }
        A[j + 1] = A[0];    //将A[j+1] ,即A[i]插入
    }
    return 0;
}

int main() {
    int A[1024], n;
    printf("请输入要输入的元素个数：");
    scanf("%d", &n);
    printf("\n请输入要排序的序列：\n");
    for (int i = 1; i <= n; i++) //输入的元素从1开始，0做哨兵
        scanf("%d", &A[i]);
    printf("\n使用直接插入排序算法后的结果：\n");
    InsertSort(A, n);
    for (int i = 1; i <= n; i++)
        printf("%d\t", A[i]);
    printf("\n");
    return 0;
}

