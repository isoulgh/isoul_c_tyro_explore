//
// Created by NL on 2021/4/29.
//

#include <iostream>

using namespace std;

typedef struct {
    char *ch;     //指向存储空间的首地址的指针
    int length;
} Str;

int strAssign(Str &s, char *c) {
//    if ((s.ch!=NULL))
//        return 0;

    int len = 0;   //统计给定串c的长度，便于后续赋值操作
    char *temp = c;
    while (*temp) {
        len++;
        temp++;
    }

    if (len == 0) {
        s.length = 0;
        s.ch = NULL;
        return 1;
    } else {
        s.length = len;
        s.ch = (char *) malloc(sizeof(char) * (len + 1));   //给串中的ch指针申请空间，也可以看成定义一个数组名为ch的长度为len+1的数组
//        cout << (s.ch==NULL);
        if (s.ch = NULL)
//            cout << "true";
            return 0;
        for (int i = 0; i <= len; ++i) {
            s.ch[i] = *c;
            c++;
        }
        return 1;
    }
}

//显示串中的元素
int displayStr(Str s) {
    for (int i = 0; i < s.length; ++i) {
        cout << " " << s.ch[i] << " ";
//        s.ch++;
    }
}

int main() {
    cout << "jfkdaj";
    Str s;
    char c1[] = {"asdaef"};
    strAssign(s, c1);
    displayStr(s);


    return 0;
}
