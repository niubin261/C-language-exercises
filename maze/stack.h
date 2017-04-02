
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

typedef struct NodeType {
	ElemType data;
	NodeType *next;

}NodeType,*LinkType;//节点指针，指针类型
typedef struct
{
	LinkType top;
	int size;
}Stack;//栈的类型

