//
// Created by xxx on 2021/5/7.
//

#include "iostream"

using namespace std;

typedef struct BSTNode {
    int data;
    BSTNode *leftchild;
    BSTNode *rightchild;
} *BNode;

BSTNode *findtree(int value, BNode root) {
    BNode result;
    while (root != NULL && value != root->data) {

        if (value < root->data) {
            root = root->leftchild;
//            cout << root->data;
        } else {
            root = root->rightchild;
        };
    }
    result = root;
    return result;
}

int inserttree(int value, BNode &root) {
    BNode insertNode = (BNode) malloc(sizeof(BSTNode));
    insertNode->leftchild = NULL;
    insertNode->rightchild = NULL;
    insertNode->data = value;
    if (root == NULL) {
        root = insertNode;
    } else {
        BNode root1 = root;
        while (root1 != NULL) {
            if (value < root1->data) {
                if (root1->leftchild == NULL) {
                    root1->leftchild =insertNode;
                    return 1;
                }
                root1 = root1->leftchild;
            } else {
                if (root1->rightchild == NULL) {
                    root1->rightchild =insertNode;
                    return 1;
                }
                root1 = root1->rightchild;
            }
        }
    }
//    if (root->data > value) {
//        root->leftchild = insertNode;
//    } else {
//        root->rightchild = insertNode;
//    }
    return 1;
}

void createtree(int *a, int length, BNode &root) {
    root = NULL;
    int i = 0;
    while (i < length) {
        inserttree(a[i], root);
        i++;
        a++;
    }
}

int main() {
    BNode tree;
    int a[6] = {6, 2, 8, 1, 4, 3};
    createtree(a, 6, tree);
    BNode result = findtree(4, tree);
    cout << result->data;
//    BNode tree = (BNode) (malloc(sizeof(BSTNode)));
//    tree->leftchild = NULL;
//    tree->rightchild = NULL;
//    tree->data = 6;
//    BNode tree1 = (BNode) (malloc(sizeof(BSTNode)));
//    tree1->leftchild = NULL;
//    tree1->rightchild = NULL;
//    tree1->data = 2;
//    tree->leftchild = tree1;
//    BNode tree2 = findtree(2, tree);
//    cout << (tree2->data);
//
//    inserttree(8,tree);
//    cout << "\n" << tree->data << "\n";
//    inserttree(1,tree);
//    inserttree(4,tree);
//    inserttree(3,tree);

}