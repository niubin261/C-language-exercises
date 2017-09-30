#include<stdio.h>
#include<stdlib.h>
typedef struct personnode{
	int no;
	float salary;
	struct personnode*next;
}node;
node*CreateList();//头插法建立链表
node*CreateList2();//尾巴插入
void PrintList(node*);//打印链表
node*DeleteList(node*,int);//删除指定的节点
node*InsertList(node*,int idx,int no,float salary);//在特定的节点之后添加,如果特定的节点没有找到那就直接在链表的最后添加
node*SortList(node*);//给链表排序，不要打我，我就是换一下链表内的值
node*MergeList(node*,node*);
node*listReserve(node*head);
int main(){
	node*phead1=NULL;
	node*phead2 = NULL;
	node*phead = NULL;
	phead1 = CreateList();
	//PrintList(phead1);
	phead2 = CreateList();
	phead = MergeList(phead1, phead2);
	PrintList(phead);

	phead1 = SortList(phead1);
	PrintList(phead1);
	phead1 = InsertList(phead1, 1001, 1003, 2);
	phead1 = DeleteList(phead1, 1004);
	PrintList(phead1);

}
node*CreateList(){//头插法建立链表就是反人类
	int no;
	float salary;
	node*p = NULL;
	node*phead = NULL;
	while (true){
		
		scanf("%d", &no);
		scanf("%f", &salary);
		
		if ((no == 0) && (salary == 0)){

			return phead;
		}else{
			p = (node*)malloc(sizeof(node));
			p->no = no;
			p->salary = salary;
			p->next = phead;
			phead = p;
		}
	}
}
node*CreateList2(){//VS为什么默认大括号好难受尾巴	
//插入发
	int no;
	float salary;
	node*p = NULL;
	node*phead = NULL;
	node*prear = NULL;
	while (true){
		scanf("%d", &no);
		scanf("%f", &salary);

		if ((no == 0) && (salary == 0)){

			return phead;
		}
		else{
			p = (node*)malloc(sizeof(node));
			p->no = no;
			p->salary = salary;
			if (phead == NULL){
				phead = p;
				prear = phead;
			}
			else{
				prear->next = p;
				prear = p;
			}
		}


	}
}
void PrintList(node*phead){
	node*p = phead;
	while (p != NULL){
		printf("%d", p->no);
		printf("XX");
		p = p->next;

	}
}
node*SearchList(node*phead,int no){
	node*p=phead;
	node*q=NULL;
	if(p==NULL){
		return NULL;
	}
	while(p!=NULL){
		if(p->no==no)return p;
		p=p->next;
	}
	return NULL;

}
node*InsertList(node*phead,int idx,int no,float salary){
	node*p = phead;
	node*q = NULL;
	while (p != NULL){
		if (p->no == idx)break;
		else
			p = p->next;
	}
	if (p == NULL){
		q = (node*)malloc(sizeof(node));
		q->no = no;
		q->salary = salary;
		p->next = q;
		q->next = NULL;
	}
	else{
		q = (node*)malloc(sizeof(node));
		q->no = no;
		q->salary = salary;
		q->next = p->next;
		p->next = q;
	}
	return phead;
}

node*DeleteList(node*phead, int idxno){
	node*p = phead;
	node*q=phead;
	while (p!=NULL){
		if (p->no == idxno){
			if (p == phead){
				phead = phead->next;
				free(p);
				return phead;
			}
			else{
				q->next = p->next;
				free(p);
				return phead;
			}

		}
		q = p;
		p = p->next;
	}
	printf("哈哈，没有找到！");//嘻嘻
	return phead;
}

node*SortList(node*phead){//使用交换排序法
	int tmpno;
	float tmpsalary;
	node*p = phead;
	node*q = phead;
	for (; p != NULL; p = p->next){
		for (q = p->next; q != NULL; q = q->next){
			if (q->salary > p->salary){
				tmpno = q->no;
				tmpsalary = q->salary;
				q->no = p->no;
				q->salary = p->salary;
				p->no = tmpno;
				p->salary = tmpsalary;
			}
		}
	}
	return phead;
}
node*MergeList(node*phead1, node*phead2){//最简单的merge就是把两个链表连接起来之后调用sort函数哈哈复杂度高
	node*p1 = phead1;
	node*p2 = phead2;
	node*phead=NULL;
	node*q1 = NULL;
	node*q2 = NULL;
	if (phead1 == NULL)return phead2;
	if (phead2 == NULL)return phead1;
	//最重要的是不要把链表的头搞没了，要不然返回就呵呵了！！！！！！！！！
	if (p1->salary < p2->salary)
		phead = phead1;
	else
		phead = phead2;
	while (p1 != NULL&&p2!=NULL){
		if (p1->salary > p2->salary){
			q2 = p2->next;
			p2->next = p1;
			p2 = q2;
		}
		else{
		
			q1 = p1->next;
			p1->next = p2;
			p1 = q1;
		}


	}
	return phead;
}
void  DestroyList(node*phead){
	node*p = phead;
	node*q = phead;
	while (p != NULL){
		q = p->next;
		free(p);
		p = q;
	}
}
node*listReserve(node*head) {
  node*p=NULL;
  node*pre=NULL;
  node*next=NULL;
  if(head==NULL)return ;
  pre=head;
  p=pre->next;
  while (p!=NULL) {
    /* code */
    next=p->next;//将next指针的移位放在这

    p->next=pre;
    if(pre=head){
      pre->next=NULL;
    }
    pre=p;
    p=next;  
  }
  return pre;
}

