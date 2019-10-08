/*
 *�㷨2.12
 * ��������������ϲ���һ����������
 *p31ҳ
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

//��������
void TraverseList(LNode *h)
{
	LNode *p = h->next;
	while(p)
	{
		DEBUG_INFO("%d",p->data);
		p = p->next;
	}
}

//�ϲ�����
void MergeList(LNode *la,LNode *lb, LNode *lc)
{
	/*��֪������la,lb��Ԫ�ذ�ֵ���ǵݼ�����,
	  �鲢la,lb���µ�����lc,lc��Ԫ��Ҳ��ֵ�ǵݼ�����
	*/
	LNode *pa = la->next;
	LNode *pb = lb->next;
	 
	while(pa && pb){
		if (pa->data < pb->data) {
			InsertTailElem(lc, CreateElem(pa->data));
			pa = pa->next;
		}
		else {
			InsertTailElem(lc, CreateElem(pb->data));
			pb = pb->next;
		}
	}
	
	while(pa){
		InsertTailElem(lc, CreateElem(pa->data));
		pa = pa->next;
	}
	
	while(pb){
		InsertTailElem(lc, CreateElem(pb->data));
		pb = pb->next;
	}
}

int main(void)
{
	//����la
	LNode la;
	la.data = 0;
	la.next = NULL;

	InsertTailElem(&la, CreateElem(100));
	InsertTailElem(&la, CreateElem(101));
	TraverseList(&la);
	
	printf("+++++++++++++++++++++++++++++++++++++++\n");
	
	//����lb
	LNode lb;
	lb.data = 0;
	lb.next = NULL;

	InsertTailElem(&lb, CreateElem(102));
	InsertTailElem(&lb, CreateElem(106));
	TraverseList(&lb);
	printf("+++++++++++++++++++++++++++++++++++++++\n");
	
	//����lc
	LNode lc;
	lc.data = 0;
	lc.next = NULL;
	
	MergeList(&la, &lb, &lc);
	TraverseList(&lc);
	return 0;
}













