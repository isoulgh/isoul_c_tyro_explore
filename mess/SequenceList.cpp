//
// Created by Donald Trump on 2021/4/11.
//

#include "iostream"

using namespace std;

#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int length;
} SqList;

#define InitSize 100
typedef struct {
    int *data;
    int maxsize, length;
} SeqList;

bool ListInsert(SqList &L, int i, int e) {
    if (i < 1 || i > (L.length + 1))
        return false;
    if (L.length > MaxSize)
        return false;
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, int &e) {
    if (i < 1 || i >= L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i - 1; j < L.length; j++) {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return true;
}

int LocateElem(SqList L, int e) {
    int i;
    for (i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}

void m1() {
    cout << "aaa" << endl;
}

int main() {
    SeqList L;
    L.data = new int[InitSize];
    SqList L1;
    for (int i = 0; i < MaxSize; i++) {
        L1.data[i] = 0;
    }
    int e;
    cout << "Here si e first:" << e << endl;
//    cout << L1.length << endl;
    ListInsert(L1, 1, 1);
    ListInsert(L1, 1, 2);
    ListInsert(L1, 1, 3);
    ListInsert(L1, 1, 4);
    ListInsert(L1, 1, 5);
    ListDelete(L1, 3, e);
    cout << "Here is e:" << e << endl;
    e = LocateElem(L1, 1);
    cout << "Here is e:" << e << endl;
//    cout << L1.length << endl;
    for (int i = 0; i < L1.length; i++) {
        cout << L1.data[i] << "\n";
    }
}