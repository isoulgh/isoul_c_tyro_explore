//
// Created by NL on 2021/4/11.
//
#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

//创建单链表(尾插法)
void createListR(LNode *&A, int a[], int n) {
    LNode *s, *r;
    A = (LNode *) malloc(sizeof(LNode));
    A->next = NULL;
    r = A;
    for (int i = 0; i < n; i++) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}

//创建单链表（头插法）
void createListH(LNode *&A, int a[], int n) {
    LNode *s;
    A = (LNode *) malloc(sizeof(LNode));
    A->next = NULL;
    for (int i = 0; i < n; i++) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = a[i];
        s->next = A->next;
        A->next = s;
    }

}

//显示链表元素
void manifestList(LNode *l) {
    while (l->next != NULL) {
        cout << "LinkList" << l->data << endl;
        l = l->next;
    }
}

int main() {
    int num[5] = {1, 2, 3, 4, 5};
    LNode *A, *B, *C, *D;
    createListR(A, num, 4);
    createListR(B, num, 5);
    createListH(C, num, 4);
    createListH(D, num, 5);
    manifestList(A);
    cout << endl;
    manifestList(B);
    cout << endl;
    manifestList(C);
    cout << endl;
    manifestList(D);
    return 0;
}

