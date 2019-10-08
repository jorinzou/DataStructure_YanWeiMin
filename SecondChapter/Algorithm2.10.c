/*
 *�㷨2.10
 *��������ɾ��Ԫ��
 *p30ҳ
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

//β������
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

//����һ���ڵ�
LNode* CreateElem(ElemType e)
{
	LNode *n = malloc(sizeof(LNode));
	if (NULL == n)
		return NULL;

	n->next = NULL;
	n->data = e;
	return n;
}

//��ȡ��i���ڵ�
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

//��ĳ��Ԫ��֮ǰ����һ���ڵ�
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

//ɾ��һ��Ԫ��
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
	//ͷ�ڵ�
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