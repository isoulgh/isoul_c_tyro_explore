//
// Created by isoul on 2021/6/14.
//

#include <stdio.h>
int main () {
    char str[] = "abcdefg";
    char *str2 = "hello world2!";
    char *p_str = &str[3];
    printf("%c\n", str[3]);
//    str = "bala";
    str[1] = 'a';
    *++p_str = 'c';
    printf("%s\n", p_str);
    str2 = "bala2";
//    *str2++;
//  输出完之后再++，导致下一次输出时不一样
    printf("%c\n", *str2++);
    printf("%c\n", str2[2]);
    printf("%s\n", str);
    printf("%s\n", str2);
}

// 字符串数组存放再全局数据区域或栈区，
// 字符串常量存放再常量区
// 数组可读可写，常量可读不可写