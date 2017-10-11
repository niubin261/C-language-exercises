//
// Created by Administrator on 2017/4/15.
//

#include<stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
using  namespace std;
typedef struct treenode{
    int value;
    struct treenode*lchild;
    struct treenode*rchild;
}node;

node* CreateTree() {
    int value;
    node*Root=NULL;
    scanf("%d", &value);
    if (value == 0) {
        return NULL;
    } else {
        Root = (node*)malloc(sizeof(node));
        Root->value = value;
        Root->lchild = CreateTree();
        Root->rchild = CreateTree();
    }
    return Root;
}
void PreOrderTraverse(node*Root) {
    if (Root != NULL) {
        printf("%d", Root->value);
    } else {
        return;
    }
    PreOrderTraverse(Root->lchild);
    PreOrderTraverse(Root->rchild);
}
void InOrderTraverse(node*Root) {
    if (Root==NULL) {
        return;
    }
    InOrderTraverse(Root->lchild);
    printf("%d", Root->value);
    InOrderTraverse(Root->rchild);
}
void PostOrderTraverse(node*Root) {
    if (Root == NULL) {
        return;
    }
    PostOrderTraverse(Root->lchild);
    PostOrderTraverse(Root->rchild);
    printf("%d", Root->value);
}
int max(int a, int b) {
    if (a>b) {
        return a;
    } else { return b; }
}
int HightTree(node*Root) {
    if (Root == NULL)return 0;
    return max(HightTree(Root->lchild) + 1, HightTree(Root->rchild) + 1);
}

void LevelOrderTraverse(node*Root) {
    if (Root==NULL){
        return;
    }
    queue<node*>TraverseQueue;
    TraverseQueue.push(Root);
    if(!TraverseQueue.empty()){
        node*now=TraverseQueue.front();
        cout<<now->value;
        TraverseQueue.pop();
        if(now->lchild!=NULL){
            TraverseQueue.push(now->lchild);

        }
        if(now->rchild!=NULL){
            TraverseQueue.push(now->rchild);
        }
    }
}

int WidthTree(node*Root){
    if(Root=NULL){
        return 0;
    }
    int curwidth=1;
    int nextwidth=0;
    int width=1;
    queue<node*>WidthQueue;
    WidthQueue.push(Root);
    while (!WidthQueue.empty()) {
        while (curwidth!=0) {
            node*curnode=WidthQueue.front();
            WidthQueue.pop();
            curwidth--;
            if (curnode->lchild!=NULL) {
                WidthQueue.push(curnode->lchild);
                nextwidth++;
            }
            if (curnode->rchild!=NULL) {
                WidthQueue.push(curnode->rchild);
                nextwidth++;
            }

        }
        if (width<nextwidth) {
            width = nextwidth;

        }
        curwidth = width;
        nextwidth = 0;
    }



}
int FindNodeFather(node*Root,int value){

    if(Root==NULL)return 0;//没有找到

    if (Root->lchild!=NULL&&Root->lchild->value==value){
        return Root->value;
    } else if (Root->rchild!=NULL&&Root->rchild->value==value){
        return Root->value;
    } else {
        FindNodeFather(Root->lchild,value);//继续找
        FindNodeFather(Root->rchild,value);
    }
    return -1;//没有找到


}
int main(int argc,char* argv[]){
    node*BiTreeRoot = CreateTree();
    PostOrderTraverse(BiTreeRoot);
    LevelOrderTraverse(BiTreeRoot);
    printf("%d",WidthTree(BiTreeRoot));
}
