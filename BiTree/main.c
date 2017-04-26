#include <iostream>
#include "tree.h"
int main()
{
    BiTree biTree;
    biTree.Root=biTree.CreateBiTree();
    biTree.PreOrderTraverse(biTree.Root);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
