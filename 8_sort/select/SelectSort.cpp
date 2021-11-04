//
// Created by Jason Luo on 2021/11/4.
//
//简单选择排序是选择排序的一种，其基本思想是将每一趟在后面的n-i+1个待排序的序列中选取关键字最小的元素，作为有序子序列中的第i个元素，直到n-1趟完成，待排序序列中只有一个元素，即得到最终的排好序的序列。（一趟排序会将一个元素放在最终的位置上)

#include<stdio.h>
// Notes
// ①时间复杂度为O(n^2)，空间复杂度为
// ②适用于顺序存储和链式存储
// ③简单选择排序是不稳定的排序算法
void SelectSort(int A[],int n);

int main() {
    int A[1024],n;
    printf("请输入要输入的元素个数：");
    scanf("%d",&n);
    printf("\n请输入要排序的序列：\n");
    for (int i=1; i<=n; i++) //输入的元素从1开始，0做哨兵
        scanf("%d",&A[i]);
    printf("\n使用简单选择排序算法后的结果：\n");
    SelectSort(A,n);
    for(int i=1; i<=n; i++)
        printf("%d\t",A[i]);
    printf("\n");
    return 0;
}

void SelectSort(int A[],int n){
    for(int i=1;i<=n;i++){
        int min=i;
        for(int j=i+1;j<=n;j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
        if(min!=i){
            int t=A[i];
            A[i]=A[min];
            A[min]=t;
        }

    }
}

