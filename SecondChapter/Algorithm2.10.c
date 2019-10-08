/*
 *算法2.10
 *单链表中删除元素
 *p30页
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG_INFO(fmt, args...) printf("\033[33m[%s:%s:%d]\033[0m "#fmt"\r\n", __FILE__,__FUNCTION__, __LINE__, ##args)

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode;

//尾部插入
void InsertTailElem(LNode *h, LNode *new)
{
  if (NULL == new)
		return;

	LNode *p = h->next;
	if (NULL == p) {
		h->next = new;
		return;
	}

	LNode *pre = NULL;
	while(p) {
		pre = p;
		p = p->next;
	}
	pre->next = new;
}

//构造一个节点
LNode* CreateElem(ElemType e)
{
	LNode *n = malloc(sizeof(LNode));
	if (NULL == n)
		return NULL;

	n->next = NULL;
	n->data = e;
	return n;
}

//获取第i个节点
int GetElem(LNode *h, int i, ElemType *e)
{
	LNode *p = h->next;
	int j = 0;
	while(p && j < i) {
		p = p->next;
		j++;
	}

	if(p && j > i)
		return -1;

	*e = p->data;
}

//在某个元素之前插入一个节点
int InsertBeforeElem(LNode *h, int i, ElemType e)
{
	int j = 0;
	LNode *p = h;
	while(p && j < i -1) {
		p = p->next;
		j++;
	}

	if (!p && j > i - 1)
		return -1;

	LNode *n = CreateElem(e);
	if (NULL == n)
		return -1;

	n->next = p->next;
	p->next = n;

	return 0;
}

void TraverseList(LNode *h)
{
	LNode *p = h->next;
	while(p)
	{
		DEBUG_INFO("%d",p->data);
		p = p->next;
	}
}

//删除一个元素
int DeleteListElem(LNode *h, int i, ElemType *e)
{
	LNode *p = h;
	
	int j = 0;
	while(p->next && j < i - 1) {
		p = p->next;
		j++;
	}
	
	if (!p || j > i)
		return -1;
	
	LNode *q = NULL;
	q = p->next;
	*e = p->data;
	
	p->next = p->next->next;
	free(q);
	
	return 0;
}

int main(void)
{
	//头节点
	LNode head;
	head.data = 0;
	head.next = NULL;

	int i = 0;	
	for (i = 0; i < 6; i++) {
		InsertTailElem(&head, CreateElem(i+101));
	}

  TraverseList(&head);

  ElemType e;
  DeleteListElem(&head, 6, &e);
  printf("+++++++++++++++++++++++++++++++++++++++++++++++\n");
  TraverseList(&head);
	return 0;
}