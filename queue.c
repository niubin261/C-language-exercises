
#include <stdio.h>
#include <cstdlib>
#define QUEUE_SIZE 100;
#define QUEUE_INC 10;
typedef struct
{
	int*base;//初始化函数的时候可以为其分配空间使其变为数组
	int rear;
	int front;
	int size;//标记着这个队列有多少元素

}Queue;
/* |------|
 * |      |rear的位置
 * |  3   |
 * |  2   |	front的位置
 * |      |<-----base
 * |------|
 * 队满队空的判断比较难，循环队列
 * 队满：(Q.rear+1)%Q.size==Q.front
 * 队空：Q.rear==Q.front
 * 
 */
void InitQueue(Queue&);
void TraverseQueue(Queue);
void DestroyQueue(Queue&);
void EnQueue(Queue&, int);
int DeQueue(Queue&);
int QueueLength(Queue);
bool QueueEmpty(Queue);
void ClearQueue(Queue&);
 
int main(int argc, char* argv[])
{
	Queue Q;
	InitQueue(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	DeQueue(Q);
	EnQueue(Q, 3);
	printf("%d", QueueLength(Q));
	TraverseQueue(Q);
}
void InitQueue(Queue&Q)
{
	
	Q.base = (int*)malloc(100*sizeof(int));
	if (Q.base == NULL)exit(0);
	Q.rear = 0;
	Q.front = 0;
	Q.size = QUEUE_SIZE;
}
void EnQueue(Queue&Q, int e)
{
	if ((Q.rear + 1) % Q.size == Q.front)
	{
		Q.base =(int*)realloc(Q.base, sizeof(int)*(100 + 10));
		Q.size = Q.size + QUEUE_INC;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.size;
}
int DeQueue(Queue&Q)
{
	if (Q.rear == Q.front)exit(0);
	int e;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.size;
	return e;
}
void TraverseQueue(Queue Q)
{
	int p=Q.front;
	while (Q.rear != Q.front)
	{
		printf("%d", DeQueue(Q));
	}
	Q.front = p;
}
int QueueLength(Queue Q)
{
	return (Q.rear - Q.front) % Q.size;
}
bool QueueEmpty(Queue Q)
{
	return Q.front == Q.rear;
}
void ClearQueue(Queue&Q)
{
	while (Q.rear != Q.front)
	{
		Q.front = (Q.front + 1) % Q.size;
	}
}
void DestroyQueu(Queue&Q)
{
	
	free(Q.base);
}

#######################################################################################################################################

队列中时刻记住
循环队列的性质

front=(front+1)%size;出对
rear=(rear+1)%size;
