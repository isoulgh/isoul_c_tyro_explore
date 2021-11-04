// Created by isoul on 2021/6/20 14:46.
// Copyright (c) 2021 isoul. All rights reserved.

#include <cstdio>

#define MAXLEN 255
typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

void get_next(SString T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while(i < T.length) {
        if(j == 0 || T.ch[i] == T.ch[j]) {
            ++i; ++j;
            next[i] = j; // 若p[i] = p[j]，则next[j + 1] = next[j] + 1
        } else
            j = next[j]; // 否则令 j = next[j]，循环继续
    }
}

int Index_KMP(SString S, SString T, int next[]) {
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length) {
        if(j == 0 || S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
        if(j > T.length)
            return i - T.length;
        else
            return 0;
    }
}

int main () {
    SString ps;
    ps.ch[0] = 'a';
    ps.ch[1] = 'b';
    ps.ch[2] = 'a';
    ps.ch[3] = 'a';
    ps.ch[4] = 'b';
    ps.ch[5] = 'c';
    ps.length = 6;

    SString ps2;
    ps2.ch[0] = 'a';
    ps2.ch[1] = 'b';
    ps2.ch[2] = 'a';
    ps2.ch[3] = 'a';
    ps2.ch[4] = 'b';
    ps2.ch[5] = 'c';
    ps2.length = 6;
    int next[ps2.length + 1];
    get_next(ps2, next);
    printf("%d", next[4]);
    printf("%d", Index_KMP(ps2, ps, next));
}