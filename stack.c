#ifndef STACK_H
#define STACK_H
#define STACK_INIT_SIZE 100;
#define STACK_INCE 10///严的数据结构真是垃圾代码写的好难受
#include<stdio.h>//老子要用链表实现栈的数据结构，不用数组
typedef struct{
	int*top;
	int*base;//不知道有什么狗屁用
	int stacksize;
}Stack;
/*其实这个zhan设置的抽象死了，太麻烦了，在我的理解中top始终指向栈顶,就是最上面的数据的上面一个，
*当栈空的时候top指向了base避免了数组中数组0开始的尴尬到后来发现其实base指针真的很好用
* |-----|<---top
* |     |
* |     |
* |     |
* |     |<---base
* |-----|
*还有就是时刻要考虑着栈的空间stacksize指的是当前有多少空间
*/
extern void InitStack(Stack&);
extern void DestroyStack(Stack&);
extern void ClearStack(Stack&);
extern bool StackEmpty(Stack);
extern int StackLength(Stack);
extern int GetTop(Stack);
extern void Push(Stack&,int);
extern void Pop(Stack&);
extern void StackTraverse(Stack);//不好意思我要从栈底遍历，你咬我呀

#endif
————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include"stack.h"
#include <stdio.h>
#include <cstdlib>
//最麻烦的就是那个如果是空栈怎么办
void InitStack(Stack&S){
	S.base = (int*)malloc(sizeof(int)*S.stacksize);
	if (!S.base)exit(0);//分配失败了，哈哈，垃圾电脑
	S.top = S.base;//空栈
	S.stacksize = STACK_INIT_SIZE;
	 
}
void DestroyStack(Stack&S){
	
	for (int i = 0; i < S.stacksize; i++){
		int*p = S.base+1;
		free(S.base);
		 
		S.base = p;
	}
	 
}
int GetTop(Stack&S){
	if (S.base == S.top)exit(0);//空栈哈哈
	return *(S.top-1);
	 
}
void Push(Stack&S, int e){
	int*p;
	if (S.stacksize == S.top - S.base){
		S.base = (int*)realloc(S.base, (S.stacksize + STACK_INCE)*sizeof(int));//realloc函数将原来的数据复制到一个新的空间
		if (!S.base)exit(0);
		S.top = S.base + S.stacksize;
		S.stacksize = S.stacksize + STACK_INCE;
		
	}
	p = S.top;
	*S.top = e;
	p++;
	S.top = p;

}
void Pop(Stack&S){
	if (S.top == S.base)exit(0);
	S.top = S.top-1;
	printf("%d", *(S.top));
}
void StackTraverse(Stack S){
	for (int*p = S.base; p != S.top; p++){
		printf("%d", *p);
	}
}
void ClearStack(Stack&S){
	S.top = S.base;
}
bool StackEmpty(Stack S){
	if (S.base == S.top){
		return true;
	} else{
		return false;
	}
}
int StackLength(Stack S){
	return S.top - S.base;
}
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "stack.h"
#include <stdio.h>
int main(int argc, char* argv[]){


	Stack S;
	InitStack(S);
	Push(S, 1);
	Push(S, 2);
	Pop(S);
	Push(S, 3);
	StackTraverse(S);
	printf("%d", StackLength(S));
	ClearStack(S);
	printf("%d", StackEmpty(S));
	StackTraverse(S);
	DestroyStack(S);
	
}
代码有点bug,Destroy函数到最后老是会free掉我不知道的地方
