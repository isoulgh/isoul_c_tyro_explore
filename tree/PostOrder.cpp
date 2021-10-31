//
// Created by Jason Luo on 2021/10/30.
//

//不递归的二叉树后序遍历

#include <iostream>
//using namespace std;

typedef struct BiNode {
    int data;
    struct BiNode *lChild;
    struct BiNode *rChild;
} BiNode;

void visit(int i);

// C后序：
void PostOrder(BiNode *T) {
    BiNode stack[10];
    int tag[10];
    for (int i = 0; i < 10; ++i) {
        stack[i] = {0,nullptr,nullptr};
        tag[i] = 0;
    }
    BiNode *p = T;
    int top = 0;
    // 一直指到最左边，如果右孩子为空则输出根节点，不为空则指到最左边。
    while (top > 0 || p != nullptr) {
        while (p != nullptr) {  // 把上一圈的右孩子放到栈中，一直指到最左边的孩子
            top++;
            stack[top] = *p;
            tag[top] = 0;
            p = p->lChild;
        }
        if (top > 0) {//if1
            p = &stack[top];
            while (tag[top] == 1) { // 若可则推出
                top--;
                visit(p->data);
                p = &stack[top];
            }
            if (top > 0) {//if2 // 指向右孩子，并将根标记为可推出
                p = &stack[top];
                p = p->rChild;
                tag[top] = 1;
            }//if2
        }//if1
    }
}

void visit(int i) {
    std::cout << i << '\n';
}

int main() {
    BiNode *T;
    T = (BiNode *) malloc(sizeof(BiNode));
    T->data = 1;
    BiNode a[6];
    for (int i = 1; i < 6; ++i) {
        a[i].data = i + 1;
    }
    T->lChild = &a[1];
    T->rChild = &a[2];
    a[1].lChild = &a[3];
    a[1].rChild = &a[4];
    a[2].lChild = nullptr;
    a[2].rChild = &a[5];
    a[3].lChild = nullptr;
    a[3].rChild = nullptr;
    a[4].lChild = nullptr;
    a[4].rChild = nullptr;
    a[5].lChild = nullptr;
    a[5].rChild = nullptr;
    PostOrder(T);
    return 0;
}

// 后序遍历2_王道_更清晰易懂
//void PostOrder(BiTree T) {
//    InitStack(S);
//    p = T;
//    r = NULL;
//    while (p || !IsEmpty(S)) {
//        if (p) {                            //走到最左边
//            push(S, p);
//            p = p->Ichild;
//        } else {                            //向右
//            GetTop(S, p);                   //读栈顶结点 （非出栈）
//            if (p->rchild && p->rchild != r)//若右子树存在，且末被访问过
//                p = p->rchild;              //转向右
//            else {                          //否则，弹出结点并访问
//                pop(S, p);                  //将结点弹出
//                visit(p -›data);            //访问该结点
//                r = p;                      //记录最近访问过的结点
//                p = NULL;                   //结点访问完后，重置p指针
//            }
//        }//else
//    }//while
//}