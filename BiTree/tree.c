#include "tree.h"
#include <iostream>
void BiTree::PreOrderTraverse(Node* Root) {
    if (Root != NULL) {
        printf("%d", Root->value);
    } else {
        return;
    }
    PreOrderTraverse(Root->leftChild);
    PreOrderTraverse(Root->rightChild);
}
Node* BiTree::CreateBiTree() {
    int value;
    Node*Root=NULL;
    scanf("%d", &value);
    if (value == 0) {
        return NULL;
    } else {
        Root = (Node*)malloc(sizeof(Node));
        Root->value = value;
        Root->leftChild = CreateBiTree();
        Root->rightChild = CreateBiTree();
    }
    return Root;
}
