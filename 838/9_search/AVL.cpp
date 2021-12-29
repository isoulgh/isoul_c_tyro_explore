//
// Created by isoul on 2021/6/13.
//

//学习地址：https://blog.csdn.net/isunbin/article/details/81707606

#include <stdio.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} BTNode;

int height(Node *node);

int max(int a, int b);

BTNode *ll_rotate(BTNode *y) {
    BTNode *x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

BTNode *rr_rotate(BTNode *y) {
    BTNode *x = y->right;
    y->right = x->left;
    x->left = y;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// lr型右旋再左旋
BTNode *lr_rotate(BTNode *y) {
    BTNode *x = y->left;
    y->left = rr_rotate(x);
    return ll_rotate(y);
}

Node *rl_rotate(Node *y) {
    Node *x = y->right;
    y->right = ll_rotate(x);
    return rr_rotate(y);
}

int height(Node *node) {
    int result = 0;
    if (NULL != node) {
        if (node->left != NULL && node->right != NULL) {
            result = max(height(node->left), height(node->right));
        } else {
            if (node->left != NULL) {
                result = height(node->left);
            } else if (node->right != NULL) {
                result = height(node->right);
            } else {
                result = 0;
            }
        }
        result++;
    }
    return result;
}

int max(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

Node init() {
    Node T1, T2, T3, T4, T5, T6;
    T1.left = NULL;
    T1.right = NULL;
    T1.height = NULL;
    T2.left = NULL;
    T2.right = NULL;
    T2.height = NULL;
    T3.left = NULL;
    T3.right = NULL;
    T3.height = NULL;
    T4.left = NULL;
    T4.right = NULL;
    T4.height = NULL;
    T5.left = NULL;
    T5.right = NULL;
    T5.height = NULL;
    T6.left = NULL;
    T6.right = NULL;
    T6.height = NULL;
    T5.key = 5;
    T3.key = 3;
    T2.key = 2;
    T1.key = 1;
    T6.key = 6;
    T4.key = 4;
    T5.left = &T3;
    T5.right = &T6;
    T3.left = &T2;
    T3.right = &T4;
    T2.left = &T1;
    printf("%d", height(&T6));
    return T5;
}