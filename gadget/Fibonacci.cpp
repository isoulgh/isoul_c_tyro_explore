//
// Created by Jason on 2021/7/15.
//

#include "cstdio"
#include "cstdlib"

void printArray(int* a, int length);
int* fibonacci();
int* recursionFibonacci();
void recursionFibonacciStep1(int* array, int length);


int LENGTH = 10;

int main() {
    int flag = 3;
    switch (flag) {
        case 1: {
            int *result = fibonacci();
            printArray(result, LENGTH);
            break;
        }
        case 2: {
            int *result1 = recursionFibonacci();
            printArray(result1, LENGTH);
            break;
        }
        case 3: {
            int* a;
            printf("%d\n", a);
            a = (int*)malloc(4);
            printf("%d\n", a);
            printf("%d\n", a[0]);
            printf("%d\n", a[50]);
        }
    }
}

void printArray(int* a, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d\t", a[i]);
    }
}

int* fibonacci() {
    int* result = (int *)malloc(sizeof(int) * LENGTH);
    result[0] = 1;
    result[1] = 1;
    for (int i = 2; i < LENGTH; i++) {
        result[i] = result[i - 1] + result[i - 2];
    }
    return result;
}


int* recursionFibonacci() {
    int* array = (int *)malloc(sizeof(int) * LENGTH);
    int length = 0;
    recursionFibonacciStep1(array, length);
    return array;
}

void recursionFibonacciStep1(int* array, int length) {
    if (length == 0) {
        array[0] = 1;
        array[1] = 1;
        length = 2;
    }
    if (length < LENGTH) {
        array[length] = array[length - 1] + array[length - 2];
        length++;
        recursionFibonacciStep1(array, length);
    }
}