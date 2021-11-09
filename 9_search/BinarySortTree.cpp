//
// Created by xxx on 2021/5/7.
//

#include "iostream"

typedef struct BSTNode {
    int data;
    BSTNode *leftChild;
    BSTNode *rightChild;
} *BNode;

// 查找
BNode findTree(int value, BNode root) {
    BNode result = nullptr;
//    int i = 1;
    while (root != nullptr && value != root->data) {
        if (value < root->data) {
//            i *= 2;
            root = root->leftChild;
//            cout << root->data;
        } else {
//            i = i * 2 + 1;
            root = root->rightChild;
        }
    }
    result = root;
//    return i;
}

// 插入
int insertTree(int value, BNode &root) {
    BNode insertNode = (BNode) malloc(sizeof(BSTNode));
    insertNode->leftChild = nullptr;
    insertNode->rightChild = nullptr;
    insertNode->data = value;
    if (root == nullptr) {
        root = insertNode;
    } else {
        BNode root1 = root;
        while (root1 != nullptr) {
            if (value < root1->data) {
                if (root1->leftChild == nullptr) {
                    root1->leftChild = insertNode;
                    return 1;
                }
                root1 = root1->leftChild;
            } else {
                if (root1->rightChild == nullptr) {
                    root1->rightChild = insertNode;
                    return 1;
                }
                root1 = root1->rightChild;
            }
        }
    }
//    if (root->data > value) {
//        root->leftChild = insertNode;
//    } else {
//        root->rightChild = insertNode;
//    }
    return 0;
}

void createTree(int *a, int length, BNode &root) {
    root = nullptr;
    int i = 0;
    while (i < length) {
        insertTree(a[i], root);
        i++;
//        a++;
    }
}

// 层序遍历
void LayerOrder(BNode T) {

}

int main() {
    BNode tree;
    int a[6] = {6, 2, 8, 1, 4, 3};
    createTree(a, 6, tree);
    int result = findTree(3, tree);
    std::cout << result;
//    BNode tree = (BNode) (malloc(sizeof(BSTNode)));
//    tree->leftChild = NULL;
//    tree->rightChild = NULL;
//    tree->data = 6;
//    BNode tree1 = (BNode) (malloc(sizeof(BSTNode)));
//    tree1->leftChild = NULL;
//    tree1->rightChild = NULL;
//    tree1->data = 2;
//    tree->leftChild = tree1;
//    BNode tree2 = findTree(2, tree);
//    cout << (tree2->data);
//
//    insertTree(8,tree);
//    cout << "\n" << tree->data << "\n";
//    insertTree(1,tree);
//    insertTree(4,tree);
//    insertTree(3,tree);

}