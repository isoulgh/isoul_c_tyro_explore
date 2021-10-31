//
// Created by Jason Luo on 2021/10/30.
//

// 变量要初始化

#include "iostream"

int main() {
    int *p;
    p = nullptr;
    if (!p) {
        std::cout << "yes";
    }
}

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