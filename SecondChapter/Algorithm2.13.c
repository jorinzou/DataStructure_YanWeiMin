/*
 *
 *循环链表 
 *结束条件，是否等于头指针
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
    if(NULL == new)
		return;
	
	//只是有头节点的时候
	LNode *p = h->next;
	if (p == h) {
		h->next = new;
		new->next = h;
		return;
	}
	
	LNode *pre =NULL;
	while(p != h) {
		pre = p;
		p = p->next;
	}
	pre->next = new;
	new->next = h;//最后一个结节指向头节点
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
	while(p != h)
	{
		DEBUG_INFO("%d",p->data);
		p = p->next;
	}
}

//删除节点
ElemType DeleteElem(LNode *h,ElemType e)
{
	LNode *pre = h;
	LNode *p = h->next;
	while(p != h){
		if (p->data == e){
			pre->next = p->next;
			free(p);
			return e;
		}
		pre = p;
		p = p->next;
	}
}

int main(void)
{
	//链表la
	LNode la;
	la.data = 0;
	la.next = &la;

	InsertTailElem(&la, CreateElem(100));
	InsertTailElem(&la, CreateElem(101));
	InsertTailElem(&la, CreateElem(102));
	InsertTailElem(&la, CreateElem(103));
	TraverseList(&la);
	
	printf("\n");
	DeleteElem(&la,102);
	TraverseList(&la);
	
	return 0;
}













