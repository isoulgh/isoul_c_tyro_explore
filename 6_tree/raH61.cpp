//
// Created by Jason Luo on 2021/11/12.
//

// 函数传递：1. 值传递 2. 引用传递 3. 指针传递
// 构建二叉树：1. 先序遍历 + 中序遍历 2. 后序遍历 + 中序遍历 3. 先序遍历 + 后续遍历（不可行）

#include "iostream"
#define MAXLENGTH 100

struct BiNode {
    int value;
    BiNode *left;
    BiNode *right;
};

struct Queue {
    BiNode *T[MAXLENGTH];
    int length;
};

struct Stack {
    BiNode *T[MAXLENGTH];
    int length;
};

void EnStack(Stack &S, BiNode *T) {
    S.T[S.length] = T;
    ++S.length;
}

BiNode *DeStack(Stack &S) {
    S.length--;
//    if (S.length > 0) {
//        std::cout << S.T[S.length]->value << "\t";
//    }
    return S.T[S.length];
}

void EnQueue(Queue &Q, BiNode *T) {
    Q.T[Q.length] = T;
    ++Q.length;
}

bool isEmptyStack(Stack s) {
    if (s.length > 0) {
        return false;
    }
    return true;
}

BiNode* GetStack(Stack s) {
    return s.T[s.length - 1];
}

BiNode GetQueue(Queue &Q, int n) {
    return *Q.T[n];
}

// 我自己写的
Queue PostOrder(BiNode &T) {
    Queue Q{};
    Q.length = 0;
    for (auto &i: Q.T) {
        i = nullptr;
    }
    Stack S{};
    S.length = 0;
    for (auto &i: S.T) {
        i = nullptr;
    }
    BiNode *p = &T;
    int flag = 0;
    while (nullptr != p) {
        while (nullptr != p && nullptr != p->left && flag == 0) {
            EnStack(S, p);
            p = p->left;
        }
        EnQueue(Q, p);
        if (nullptr == p->right && S.length > 0) {
            p = DeStack(S);
            flag = 1;
        } else {
            p = p->right;
            flag = 0;
        }
    }
    return Q;
}

void visit(Stack s) {
    std::cout << s.T[s.length - 1]->value << "\t";
}

// 我自己写的
void PostOrderSearch(BiNode &T, int search) {
    Stack S{};
    S.length = 0;
    for (auto &i: S.T) {
        i = nullptr;
    }
    BiNode *p = &T;
    EnStack(S, p);
    int flag = 0;
    while (nullptr != p) {
        while (nullptr != p && nullptr != p->left && flag == 0) {
            if (S.T[S.length - 1]->value == search) {
                for (int i = 0; i < S.length; ++i) {
                    DeStack(S);
                }
                return;
            }
            p = p->left;
            EnStack(S, p);
        }
        if (nullptr == p->right && S.length > 0) {
            if (S.T[S.length - 1]->value == search) {
                for (int i = 0; i < S.length; ++i) {
                    DeStack(S);
                }
                return;
            }
            p = DeStack(S);
            flag = 1;
        } else {
            p = p->right;
            EnStack(S, p);
            flag = 0;
        }
    }
}

void PostOrderSearch1(BiNode T, int search) {
    Stack s;
    s.length = 0;
    BiNode *p = nullptr, *r = nullptr;
    p = &T;
    while (p != nullptr || !isEmptyStack(s)) {
        if (p != nullptr) {
            EnStack(s, p);
            p = p->left;
        } else {
            p = GetStack(s);
            if (p->value == search) {
                DeStack(s);
                while (!isEmptyStack(s)) {
                    visit(s);
                    DeStack(s);
                }
                return;
            }
//            p = DeStack(s);
            if (p->right != nullptr && r != p->right) {
                p = p->right;
                r = p;  // 标记此时已经入栈的向右孩子拐的结点
//                EnStack(s, p);
            } else {
                p = DeStack(s);
                p = nullptr;    // 不让它进第一个if，一直指向左孩子的循环
            }
        }
    }
}

void PrintQueue(Queue Q) {
    for (int i = 0; i < Q.length; ++i) {
        std::cout << Q.T[i]->value << "\t";
    }
}

void PrintStack(Stack s) {
    for (int i = 0; i < s.length; ++i) {
        std::cout << s.T[i]->value << "\t";
    }
}

//我自己写的
//BiNode *InitTree(int *post, int postl, int postr, int *in, int inl, int inr) {
//    if (postl > postr) { //已经遍历完了，返回
//        return NULL;
//    }
//    BiNode *root = new BiNode; //建立一个根结点，用来存放当前的树结点
//    root->value = post[postr];  // 因为是已知后序，所以当前树的值，一定等于后序的最右边
//    int k;
//    for (k = inl; k <= inr; k++) {
//        if (in[k] == post[postr]) //找到位置，跳出，k不再++
//            break;
//    }
//    int numleft = k - inl;//当前树的左子树的数量
//    root->left = InitTree(post, postl, postl + numleft - 1, in, inl, k - 1);//将这部分存入左子树
//    root->right = InitTree(post, postl + numleft, postr - 1, in, k + 1, inr);// 将这部分存入右子树
//    return root; //返回根结点的地址，将整个树的结点连接起来
//}

//BiNode *InitTree(int *post, int *in, int length) {
//
//    Stack s;
//    int stackN[100];
//    int stackV[100];
//    int j = 0;
//    for (int i = 0; i < 100; ++i) {
//        stackN[i] = 0;
//    }
//    for (int i = 0; i < 100; ++i) {
//        stackV[i] = 0;
//    }
//    BiNode *root = new BiNode;
//    root->value = post[length];
//    int node = 1;
//    int postL = 0, postR = length;
//    int inL = 0, inR = length;
//    BiNode *p = root;
//    while (node != length) {
//        while (postL < postR) {
//            for (int k = inL; k < inR; k++) {
//                if (in[k] == post[postR]) { //找到位置，跳出，k不再++
//                    if (k != postR - 1) {
//                        stackV[j] = k - postL;
//                        stackN[j] = postR - 1;
//                        j++;
//                    }
//                    postR = k - postL - 1;
//                    BiNode *a = new BiNode;
//                    a->left = nullptr;
//                    a->right = nullptr;
//                    a->value = post[postR];
//                    node++;
//                    p->left = a;
//                    p = a;
//                    break;
//                }
//            }
//        }
//
//    }
//    return nullptr;
//}

// 指针传递
// 通过中序和后序构建树
void CreateBiTree(BiNode **T, int *in, int *post, int len) {
    int k = 0;
    int *temp = 0;
    if (len <= 0) {
        T = nullptr;
        return;
    }
    for (temp = in; temp <= in + len - 1; temp++) {
        if (*(post + len - 1) == *temp) {
            k = temp - in;
            *T = (BiNode *) malloc(sizeof(BiNode));
            (*T)->value = *temp;
            (*T)->left = nullptr;
            (*T)->right = nullptr;
            break;
        }
    }
    CreateBiTree(&((*T)->left), in, post, k);
    CreateBiTree(&((*T)->right), in + k + 1, post + k, len - k - 1);
}

// 引用传递
//void CreateBiTree(BiNode &T, int *in, int *post, int len) {
//    int k = 0;
//    int *temp = 0;
//    if (len <= 0) {
//        T = {-1, nullptr, nullptr};
//        return;
//    }
//    for (temp = in; temp <= in + len - 1; temp++) {
//        if (*(post + len - 1) == *temp) {
//            k = temp - in;
//            T.value = *temp;
//            T.left = (BiNode *) malloc(sizeof(BiNode));
//            T.left->value = -1;
//            T.left->left = nullptr;
//            T.left->right = nullptr;
//            T.right = (BiNode *) malloc(sizeof(BiNode));
//            T.right->value = -1;
//            T.right->left = nullptr;
//            T.right->right = nullptr;
//            break;
//        }
//    }
//    CreateBiTree(*(T.left), in, post, k);
//    CreateBiTree(*(T.right), in + k + 1, post + k, len - k - 1);
//}

int main() {
    int post[] = {6,4,2,5,3,1};
    int in[] = {2,6,4,1,3,5};
    int length = 6;
//    BiNode T = {0, nullptr, nullptr};
    BiNode *T = nullptr;

    BiNode **T1 = &T;
    CreateBiTree(T1, in, post, length);

    PostOrderSearch1(**T1, 6);
//    PrintStack(S);
//    PrintQueue(Q);
    return 0;
}

// 网上答案
// 算法思想：采用非递归后序遍历，最后访问根结点，
// 当访问到值为x的结点时，栈中所有元素均为该结点的祖先，依次出栈打印即可。
//int PrintParent_1(BiNode *&p, char x) {
//    Stack S;
//    InitStack(S);
//    BiNode *r = NULL;
//    while (!StackEmpty(S) || p != NULL) {
//        if (p != NULL) {
//            Push(S, p);
//            p = p->lChild;
//        } else {
//            GetTop(S, p);
//            if (p->data == x) {   // 判断是否是要找的结点
//                Pop(S, p);
//                while (StackEmpty(S) != true) {
//                    Pop(S, p);
//                    visit(p);
//                }
//                return 0;
//            }
//            if (p->rChild != NULL && p->rChild != r)  // 第二个条件重要
//                p = p->rChild;
//            else {
//                Pop(S, p);
//                //visit(p);
//                r = p;//标记右孩子已经访问过了
//                p = NULL;//访问完一个结点之后需要置空，不置空的话又会把这个结点压进去
//            }
//        }
//    }
//}


