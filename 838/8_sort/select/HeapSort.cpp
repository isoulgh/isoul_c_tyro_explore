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
void AdjustDown(int A[], int k, int len);

void BuildMaxHeap(int A[], int n);

void HeapSort(int A[], int n);

int main() {
    int  n;
//    printf("请输入要输入的元素个数：");
//    scanf("%d", &n);
    n = 10;
//    printf("\n请输入要排序的序列：\n");
//    for (int i = 1; i <= n; i++) //输入的元素从1开始，0做哨兵
//        scanf("%d", &A[i]);
    int A[1024] = {0, 62, 41, 30, 28 , 16, 22, 13, 28, 28, 28};
    printf("\n使用堆排序算法后的结果：\n");
    HeapSort(A, n);
    for (int i = 1; i <= n; i++)
        printf("%d\t", A[i]);
    printf("\n");
    return 0;
}

// 构造大顶堆
void BuildMaxHeap(int A[], int n) {
    int temp, i, j;
    for (int i = n / 2; i > 0; i--) {   // 从后往前调整所有非终端结点
        AdjustDown(A, i, n);
    }
}

// 堆的父母=i/2，堆的左孩子=2*i，堆的右孩子=2*i+1
// 把根和子树中三个值的最大的放到根
// 较小的元素下移
void AdjustDown(int A[], int k, int len) {    // adjust调整
    A[0] = A[k];    // A[0]暂存子树的根结点
    for (int i = 2 * k; i <= len; i *= 2) {   //沿key较大的子节点向下筛选
        if (i < len && A[i] < A[i + 1]) i++;  // i取key较大的子结点的下标，判断i<len有无右兄弟
        if (A[0] >= A[i]) break;    // if父母大，则退出，筛选结束，判断要放的元素是否比左右孩子更大
        else {  // if父母比孩子小
            A[k] = A[i];    // 将A[i]调整到双亲结点上
            k = i;  // 修改k值，以便继续向下筛选，k到i，让最后一个调整的k
        }
    }
    A[k] = A[0];    // 被筛选结点的值放入最终位置，把原A[i]放到A[k]
}

void HeapSort(int A[], int n) {
    // 构造初始大根堆
    BuildMaxHeap(A, n);
    // 把根放到数组最后（堆），并将目前的根结点继续下沉一次，此时根节点为最大结点
    for (int i = n; i > 0; i--) {
        int t = A[1];
        A[1] = A[i];
        A[i] = t;
        AdjustDown(A, 1, i - 1);
    }
}

