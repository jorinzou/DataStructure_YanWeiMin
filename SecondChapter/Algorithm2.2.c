/*
 *已知线性表La和Lb中的数据元素按值非递减有序排列
 *归并La和Lb得到新的线性表Lc,Lc的数据元素也按非递减有序排列
 *p21页
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG_INFO(fmt, args...) printf("\033[33m[%s:%s:%d]\033[0m "#fmt"\r\n", __FILE__,__FUNCTION__, __LINE__, ##args)

#define LIST_INIT_SIZE 3
#define LIST_INCREMENT 10

typedef int ElemType;

typedef struct {
	ElemType *elem;
	int length;
	int ListSize;
}SqList;

enum status {OK=0 , FAILED=1};

/*构造一个线性表l*/
int InitListSq(SqList *l)
{
	if (NULL == l)
		return FAILED;

	l->elem = malloc(sizeof(ElemType) * LIST_INIT_SIZE);
	if (NULL == l->elem) {
		return FAILED;	
	}
	memset(l->elem , 0, sizeof(ElemType) * LIST_INIT_SIZE);
	l->length = 0;
	l->ListSize = LIST_INIT_SIZE;
	return OK;
}

/*获取线性表中的元素*/
void GetElem(const SqList *l, ElemType *e, int i)
{
	if (l == NULL)
		return;
	if (i >= l->ListSize)
		return;

	*e = l->elem[i];
	return;
}

//从线性表尾部插入元素
void TailInsertSq(SqList *l, ElemType e)
{
	if (NULL == l)
		return;
	
	if (l->length >= l->ListSize) {
		l->elem[l->length-1] = e;
		return;
	}
		
	l->elem[l->length++] = e;
}

void InsertList(SqList *l, ElemType e)
{
	ElemType *p = NULL;
}

/*合并线性表l1,l2 到l3*/
void MergeList(const SqList *l1, const SqList *l2, SqList *l3)
{
	if (NULL == l1 || NULL == l2 || NULL == l3)
	  return;

  //扩展l3存储空间
	if (l1->ListSize + l2->ListSize >= l3->ListSize) {
		ElemType *NewBaseAddr = realloc(l3->elem, sizeof(ElemType) * l3->ListSize*2);
		l3->elem = NewBaseAddr;
		l3->ListSize = l3->ListSize*2;
	}
 
  int i = 0, j = 0;
	ElemType e1;
	ElemType e2;

	while(i <= l1->length && j <= l2->length) {
			GetElem(l1, &e1, i);
			GetElem(l2, &e2, j);

			if (i >= l1->length) {
				  i++;
				 	break;
			}

			if (j >= l2->length) {
				 	j++;
				 	break;
			}

			if (e1 <= e2) {
			   TailInsertSq(l3, e1);
				 i++;
			}
			else {
			   TailInsertSq(l3, e2);
				 j++;
			}
			DEBUG_INFO("e1=%d,i=%d,e2=%d,j=%d",e1,i,e2,j);
	}

 DEBUG_INFO("i=%d,j=%d",i,j);
 for (i; i <= l1->length; i++) {
	GetElem(l1, &e1, i);
	TailInsertSq(l3, e1);
 }

 for (j; j <= l2->length; j++) {
	GetElem(l2, &e2, j);
	TailInsertSq(l3, e2);
 }
}

int main(void)
{
	SqList l1;
	InitListSq(&l1);
	SqList l2;
	InitListSq(&l2);
	SqList l3;
	InitListSq(&l3);
	
	//初始化线性表l1,非递减有序
	l1.elem[0] = 1;
	l1.elem[1] = 4;
	l1.elem[2] = 8;
	l1.length = 3;

  //初始化线性表l2,非递减有序
	l2.elem[0] = 6;
	l2.elem[1] = 7;
	l2.elem[2] = 9;
	l2.length = 3;

	MergeList(&l1, &l2, &l3);
	//合并之后的线性表l3
	int i = 0;
	for (i = 0; i < l3.length; i++) {
		DEBUG_INFO("%d", l3.elem[i]);
	}
	return 0;
}
