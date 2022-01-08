//
// Created by Jason on 2022/1/6.
//

#include <cstdio>

void sort(int *array, int &length, int p) {
    int root = array[p];
    int i;
    while (2 * p + 1 < length) {
        if (2 * p + 2 >= length) {
            if (array[2 * p + 1] > array[p]) {
                array[p] = array[2 * p + 1];
                p = 2 * p + 1;
            } else {
                break;
            }
        } else {
            if (array[2 * p + 1] > array[2 * p + 2]) {
                i = 2 * p + 1;
            } else {
                i = 2 * p + 2;
            }
            if (root < array[i]) {
                array[p] = array[i];
                p = i;
            } else {
                break;
            }
        }
    }
    array[p] = root;
}

void buildRoot(int *array, int &length) {
    for (int i = length / 2 - 1; i >= 0; --i) {
        sort(array, length, i);
    }
}

void heapSort(int *array, int &length) {
    buildRoot(array, length);
    for (int count = length; count > 0;) {
        int temp;
        temp = array[count - 1];
        array[count - 1] = array[0];
        array[0] = temp;
        --count;
        sort(array, count, 0);
    }
}

int main() {
    int a[] = {4, 5, 2, 6, 1, 6, 7, 2};
    int length = 8;
    heapSort(&a[0], length);
    for (int i = 0; i < length; ++i) {
        printf("%d", a[i]);
    }
}
