
#ifndef TREECLASS_TREE_H
#define TREECLASS_TREE_H

#include <iostream>
using namespace std;
typedef struct BiTreeNode {
    int value;
    struct BiTreeNode*leftChild;
    struct BiTreeNode*rightChild;
}Node;
class BiTree {
public:
    Node*Root;
public:
    BiTree():Root(NULL){}
    Node*CreateBiTree();
    void PreOrderTraverse(Node*Root);

};
#endif //TREECLASS_TREE_H
