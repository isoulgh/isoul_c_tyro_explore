//
// Created by NL on 2021/4/27.
//

#include <iostream>

using namespace std;

typedef struct {
    char *ch;     //指向存储区首地址的字符指针
    int length;
} Str;

//串的赋值操作
int strAssign(Str &s, char *c1) {
    if (s.ch)
        free(s.ch);

    int len = 0;
    char *c = c1;

    while (*c) {  //求字符串的长度
        len++;
        c++;
    }

    if (len == 0) {
        s.length = 0;
        s.ch = NULL;
        return 1;
    } else {
        s.ch = (char *) malloc(sizeof(char) * (len + 1));
        if (s.ch == NULL) //申请空间失败
            return 0;
        else {
            c = c1;
            s.length = len;

            for (int i = 0; i <= len; ++i) {
                s.ch[i] = *c;
                ++c;
            }
            return 1;
        }
    }
}

//显示串中元素
void displayStr(Str s) {
    for (int i = 0; i < s.length; ++i) {
        cout << " " << s.ch[i] << " ";
    }
}

int main() {
    Str s;
    char ch[] = {"asdasd"};
    strAssign(s, ch);
    displayStr(s);

    return 0;
}
