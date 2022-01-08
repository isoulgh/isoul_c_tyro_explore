//
// Created by Jason on 2021/12/29.
//
#include <stack>
#include "vector"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    // ListNode的构造函数，如果你调用一个ListNode(5)，
    // 那么构造函数就把val设置成5，next设置成NULL.
    ListNode(int x) : val(x), next(NULL) {}
};

void method1() {
//    实例化节点
    ListNode *n1 = new ListNode(4);
    ListNode *n2 = new ListNode(5);
    ListNode *n3 = new ListNode(1);

//    构建引用指向
    n1->next = n2;
    n2->next = n3;
}

void method2() {
    stack<int> stk;
    stk.push(1);

    stk.push(2);
    stk.pop();
    stk.pop();
}

int main() {
    vector<int> array;

    array.push_back(2);
    array.push_back(3);
    array.push_back(1);
    array.push_back(0);
    array.push_back(2);
}