/*
 *算法2.12
 * 将两个有序链表合并成一个有序链表
 *p31页
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

//遍历链表
void TraverseList(LNode *h)
{
	LNode *p = h->next;
	while(p)
	{
		DEBUG_INFO("%d",p->data);
		p = p->next;
	}
}

//合并链表
void MergeList(LNode *la,LNode *lb, LNode *lc)
{
	/*已知单链表，la,lb的元素按值，非递减排列,
	  归并la,lb到新的链表lc,lc的元素也按值非递减排列
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
	//链表la
	LNode la;
	la.data = 0;
	la.next = NULL;

	InsertTailElem(&la, CreateElem(100));
	InsertTailElem(&la, CreateElem(101));
	TraverseList(&la);
	
	printf("+++++++++++++++++++++++++++++++++++++++\n");
	
	//链表lb
	LNode lb;
	lb.data = 0;
	lb.next = NULL;

	InsertTailElem(&lb, CreateElem(102));
	InsertTailElem(&lb, CreateElem(106));
	TraverseList(&lb);
	printf("+++++++++++++++++++++++++++++++++++++++\n");
	
	//链表lc
	LNode lc;
	lc.data = 0;
	lc.next = NULL;
	
	MergeList(&la, &lb, &lc);
	TraverseList(&lc);
	return 0;
}













