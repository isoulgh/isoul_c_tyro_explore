//
// Created by Jason Luo on 2021/11/4.
//

// 一个A[0]作为哨兵

// 直接插入排序是插入排序的一种，插入排序是每次将一个待排序的序列插入到一个前面已经排好序的子序列当中。
// 直接插入排序的算法思想如下：
// （1）查找出L[i]在L[1~i-1]中的插入位置k；
// （2）将L[k~i-1]中所有的元素全部向后移一个位置；
// （3）将L[i]复制到L[k]中。
#include <cstdio>
#include <ctime>
#include <iostream>
#include "unistd.h"
// Notes
// ①时间复杂度为O(n^2)
// ②适用于顺序存储和链式存储(上面的代码是顺序存储)
// ③是稳定的排序算法

// 使用插入排序进行升序排列
int InsertSort(int A[], int n) {
    int i, j;   // 两次循环变量
    // for循环，先条件2判断，再执行语句体，最后条件3（++i比i++效率高）
    for (i = 2; i <= n; i++) { // 数组下标从2开始，A[0]做监视哨，A[1]一个数据无可比性
        A[0] = A[i];    // A[0]为哨兵
        for (j = i - 1; A[0] < A[j]; j--) { // 如果j位置元素比i位置小，则每项元素后移
            A[j + 1] = A[j];    // 元素后移
        }
        A[j + 1] = A[0];    // 将A[j+1] ,即A[i]插入
    }
    return 0;
}

int main() {
    int A[1024], n;
//    printf("请输入要输入的元素个数：");
//    scanf("%d", &n);
    n = 5;
//    printf("\n请输入要排序的序列：\n");
//    for (int i = 1; i <= n; i++) //输入的元素从1开始，0做哨兵
//        scanf("%d", &A[i]);
//    printf("\n使用直接插入排序算法后的结果：\n");
    A[1] = 6;
    A[2] = 5;
    A[3] = 9;
    A[4] = 2;
    A[5] = 4;
//    clock_t begin = clock();
//    clock_t *begin;
//    time(begin);
//    time_t begin1;
//    time(&begin1);  // 获取1970年1月1日到现在的0区秒数，精确秒

    auto t1 = std::chrono::steady_clock::now();
//    auto res = Run;
//    sleep(1);
    InsertSort(A, n);
    auto t2 = std::chrono::steady_clock::now();
    auto dt = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    std::cout << "Elapsed time: " << dt << "ns" << std::endl;
//    std::cout  << "elapsed time: "
//               << double() * std::chrono::nanoseconds::period::num / std::chrono::nanoseconds::period::den
//               << "s"
//               << std::endl;

//    clock_t end = clock();
//    double time_consumption = (double)(end - begin) / CLOCKS_PER_SEC;
    for (int i = 1; i <= n; i++)
        printf("%d\t", A[i]);
    printf("\n");
//    printf("总计耗时%f\n", time_consumption);
//    std::cout << time_consumption << std::endl;
//    std::cout << begin1 << std::endl;
//    std::cout << begin << std::endl;
//    std::cout << end << std::endl;
    return 0;
}

