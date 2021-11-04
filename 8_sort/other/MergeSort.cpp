//
// Created by Jason Luo on 2021/11/4.
//
// 归并是将两个或多个存序记录序列合并成一个有序序列。一般来说，一次对几个有序记录进行归并，就称为几路归并排序。以二路归并排序为例，其基本方法如下：
// (1) 将 n 个记录看成是 n 个长度为 1 的有序子表。
// (2) 将两两相邻时有序序列进行归并。
// (3) 重复执行步骤 (2) 直到归并成一个长度为 n 的有序表
// 二路归并
#include <stdio.h>
// Notes
// ①时间复杂度为O(nlog2n)，空间复杂度为O(n)
// ②适用于顺序存储和链式存储
// ③归并排序算法是稳定的排序算法
int MergeSort(int A[],int B[],int low,int high);
void Merge(int A[],int B[],int low,int mid,int high);

int main() {
    int A[1024],high;
    printf("请输入要输入的元素个数：");
    scanf("%d",&high);
    int B[high];
    printf("\n请输入要排序的序列：\n");
    for (int i=1; i<=high; i++) //输入的元素从1开始，0做哨兵
        scanf("%d",&A[i]);
    printf("\n使用二路归并排序算法后的结果：\n");
    MergeSort(A,B,1,high);
    for(int i=1; i<=high; i++)
        printf("%d\t",A[i]);
    printf("\n");
    return 0;
}

void Merge(int A[],int B[],int low,int mid,int high) {
    int i,j,k;
    i = low;
    j = mid + 1;
    k = 0;
    while (i<=mid&&j<=high) {
        if(A[i]<=A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    while(i<=mid)
        B[k++]=A[i++];
    while(j<=high)
        B[k++]=A[j++];

    for (i=0;i<k;i++)
        A[low+i]=B[i];
}

int MergeSort(int A[],int B[],int low,int high) {
    if(low<high) {
        int mid=(low+high)/2;
        MergeSort(A,B,low,mid);//左边有序
        MergeSort(A,B,mid+1,high);//右边有序
        Merge(A,B,low,mid,high);//合并左右
    }
    return 0;
}

