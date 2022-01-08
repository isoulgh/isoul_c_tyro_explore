//
// Created by Jason on 2022/1/6.
//

#include "stdio.h"

int main() {
    int in = 193;
    int a[] = {100, 50, 20, 10, 5, 2, 1};
    int b[100];
    for (int i = 0; i < 100; ++i) {
        b[i] = 0;
    }
    for (int i = 0; i < 7; ++i) {
        while (in - a[i] >= 0) {
            b[i]++;
            in = in - a[i];
        }
    }
    printf("一百元：%d\t", b[0]);
    printf("五十元：%d\t", b[1]);
    printf("二十元：%d\t", b[2]);
    printf("十元：%d\n", b[3]);
    printf("五元：%d\t", b[4]);
    printf("二元：%d\t", b[5]);
    printf("一元：%d\t", b[6]);
}