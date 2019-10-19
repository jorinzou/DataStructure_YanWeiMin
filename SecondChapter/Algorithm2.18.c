/*
 *双向循环链表
 *增删改查
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

//尾部插入
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

//构造一个节点
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

//正向遍历链表
void OrderTraverseList(DuLNode *h)
{
	DuLNode *p = h->next;
	while(p != h){
		DEBUG_INFO("%d",p->data);
		p = p->next;
	}
}

//逆向遍历链表
void ReverseTraverseList(DuLNode *h)
{
	DuLNode *p = h->pre;
	while(p != h){
		DEBUG_INFO("%d",p->data);
		p = p->pre;
	}
}

//删除节点
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
	printf("顺序遍历\n");
	OrderTraverseList(&head);
	
	printf("逆序遍历\n");
	ReverseTraverseList(&head);
	
	printf("删除节点遍历\n");
	DeleteElem(&head,102);
	ReverseTraverseList(&head);
	
	return 0;
}













