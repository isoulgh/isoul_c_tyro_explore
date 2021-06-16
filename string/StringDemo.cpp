// Created by isoul on 2021/6/16 16:57.
// Copyright (c) 2021 isoul. All rights reserved.
#include <stdio.h>

#define MAXLEN 255
typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

typedef struct {
    char *ch;
    int length;
} HString;

// s.length > t.length
int Index(SString s, SString t) {
    int i = 0, j = 0;
    for (; i < s.length - t.length + 2;) {
        while (j < t.length && i < s.length) {
            if (s.ch[i] == t.ch[j]) {
                i++;
                j++;
            }
            else if (s.ch[i] != t.ch[j] && j != t.length) {
                i = i - j + 1;
                j = 0;
            }
        }
        if (j == t.length) {
            return i - j + 1;
        }
    }
    return 0;
}

int main() {
    SString s1;
    SString s2;
    s1.ch[0] = 'a';
    s1.ch[1] = 'b';
    s1.ch[2] = 'c';
    s1.ch[6] = 'd';
    s1.ch[3] = '1';
    s1.ch[4] = '2';
    s1.ch[5] = '3';
    s1.length = 7;
//    s1.length = 5;
    s2.ch[0] = '1';
    s2.ch[1] = '2';
    s2.ch[2] = '3';
    s2.length = 3;
    int sign = Index(s1, s2);
    printf("%d", sign);
    return 0;
}