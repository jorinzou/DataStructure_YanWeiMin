/*
 *˫��ѭ������
 *��ɾ�Ĳ�
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG_INFO(fmt, args...) printf("\033[33m[%s:%s:%d]\033[0m "#fmt"\r\n", __FILE__,__FUNCTION__, __LINE__, ##args)

typedef int ElemType;

typedef struct DuLNode{
	ElemType data;
	struct DuLNode *next;
	struct DuLNode *pre;
}DuLNode;

//β������
void InsertTailElem(DuLNode *h, DuLNode *new)
{
	if(h->next == NULL){
		h->next = new;
		h->pre = new;
		new->pre = h;
		new->next = h;
		return;
	}
	
	h->pre->next = new;
	new->pre = h->pre;
	new->next = h;
	h->pre = new;
}

//����һ���ڵ�
DuLNode* CreateElem(ElemType e)
{
	DuLNode *new = malloc(sizeof(DuLNode));
	if (new == NULL)
		return NULL;
	
	new->pre = NULL;
	new->next = NULL;
	new->data = e;
	return new;
}

//�����������
void OrderTraverseList(DuLNode *h)
{
	DuLNode *p = h->next;
	while(p != h){
		DEBUG_INFO("%d",p->data);
		p = p->next;
	}
}

//�����������
void ReverseTraverseList(DuLNode *h)
{
	DuLNode *p = h->pre;
	while(p != h){
		DEBUG_INFO("%d",p->data);
		p = p->pre;
	}
}

//ɾ���ڵ�
ElemType DeleteElem(DuLNode *h,ElemType e)
{
	DuLNode *p = h->next;
	while(p != h){
		if (p->data == e){
			p->pre->next = p->next;
			p->next->pre = p->pre;
			free(p);
			return e;
		}
		p = p->next;
	}
}

int main(void)
{
	DuLNode head;
	head.next = &head;
	head.pre = &head;
	head.data = 0;
	
	InsertTailElem(&head,CreateElem(100));
	InsertTailElem(&head,CreateElem(101));
	InsertTailElem(&head,CreateElem(102));
	InsertTailElem(&head,CreateElem(103));
	printf("˳�����\n");
	OrderTraverseList(&head);
	
	printf("�������\n");
	ReverseTraverseList(&head);
	
	printf("ɾ���ڵ����\n");
	DeleteElem(&head,102);
	ReverseTraverseList(&head);
	
	return 0;
}













