/*
 *算法2.8
 *p29页
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

void InsertElem(LNode *h, LNode *new)
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

LNode* CreateElem(ElemType e)
{
	LNode *n = malloc(sizeof(LNode));
	if (NULL == n)
		return NULL;

	n->next = NULL;
	n->data = e;
	return n;
}

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

int main(void)
{
	LNode head;
	head.data = 0;
	head.next = NULL;

	int i = 0;	
	for (i = 0; i < 6; i++) {
		InsertElem(&head, CreateElem(i+101));
	}

	ElemType e = -1;
	GetElem(&head, 3, &e);
	DEBUG_INFO("%d",e);
  
	return 0;
}
