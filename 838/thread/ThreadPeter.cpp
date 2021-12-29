// Created by isoul on 2021/6/15 20:19.
// Copyright (c) 2021 isoul. All rights reserved.
/*线程的基本操作 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include <iostream>
//#include<windows.h>
using namespace std;

struct sign {
    bool flag[2] = {false, false};
    int turn = 0;
};

/* 子线程1 */
void *thread_routine1(void *arg) {
    sleep(1);
    struct sign *sign1 = (sign *) arg;
    printf("线程1进入区\n");
    sign1->flag[1] = true;
    sign1->turn = 1;
    sleep(1);
    printf("线程1进入区2\n");
    while (sign1->flag[1] && sign1->turn == 1) {
//        cout << sign1->flag[0], sign1->turn;
    }
    sleep(1);
    printf("线程1进入临界区\n");
    sleep(1);
    printf("线程1进入退出区\n");
    sign1->flag[0] = false;
    sleep(1);
    printf("线程1进入剩余区\n");
    sleep(1);
    pthread_exit(NULL);
}

/* 子线程2 */
void *thread_routine2(void *arg) {
    sleep(1);
    struct sign *sign1 = (sign *) arg;
    printf("线程2进入区\n");
    sign1->flag[1] = true;
    sign1->turn = 1;
    sleep(1);
    printf("线程2进入区2\n");
    while (sign1->flag[0] && sign1->turn == 0) {
        cout << sign1->flag[1], sign1->turn;
    }
    sleep(1);
    printf("线程2进入临界区\n");
    sleep(1);
    printf("线程2进入退出区\n");
    sign1->flag[1] = false;
    sleep(1);
    printf("线程2进入剩余区\n");
    sleep(1);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    struct sign *sign = new struct sign;
    sign->flag[0] = false;
    sign->flag[1] = false;
    sign->turn = 0;

    /* 创建子线程1 */
    pthread_t t1;
    if (pthread_create(&t1, NULL, thread_routine1, sign) != 0) {
        fprintf(stderr, "create thread fail.\n");
        exit(-1);
    }

    /* 创建子线程2， 并将主线程id 传给子线程2 */
    pthread_t t2;
    if (pthread_create(&t2, NULL, thread_routine2, sign) != 0) {
        fprintf(stderr, "create thread fail.\n");
        exit(-1);
    }

    pthread_exit(NULL);
}
