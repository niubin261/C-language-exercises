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
void BiTree::FindNode(Node* Root,int& cnt) {

    if(Root->leftChild==NULL&&Root->rightChild!=NULL) {
        cnt++;
        FindNode(Root->leftChild,cnt);
    }
    else if (Root->leftChild!=NULL&&Root->rightChild==NULL) {
        cnt++;
        FindNode(Root->rightChild,cnt);
    }
    else if (Root->rightChild!=NULL&&Root->leftChild!=NULL) {
        FindNode(Root->leftChild,cnt);
        FindNode(Root->rightChild,cnt);
    }
    else return;

}
