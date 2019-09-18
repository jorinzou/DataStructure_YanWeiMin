/*
 *线性表的合并操作,算法2.1,P20页
 *a[1,2,3] b[3,4,5] 
 *c[1,2,3,4,5]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG_INFO(fmt, args...) printf("\033[33m[%s:%s:%d]\033[0m "#fmt"\r\n", __FILE__,__FUNCTION__, __LINE__, ##args)

#define LIST_INIT_SIZE 10
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
}

/*获取线性表中的元素*/
void GetElem(const SqList *l, ElemType *e, int i)
{
	if (l == NULL)
		return;

	*e = l->elem[i];
}

//判断某元素是否在线性表中
bool ElemIsLocateSq(const SqList *l, ElemType *e)
{
	int i = 0;
	for(i; i < l->length; i++)
	{
		if (*e == l->elem[i])
			return true;
	}

	return false;
}

//从线性表尾部插入元素
void TailInsertSq(SqList *l, ElemType e)
{
	if (NULL == l)
		return;

  //空间不足，增加线性表l的存储空间
	if (l->length >= l->ListSize) {
		ElemType * NewBaseAddr = realloc(l->elem, sizeof(ElemType)*(l->ListSize*2));
		l->elem = NewBaseAddr;
		l->ListSize = l->ListSize*2;
	}

	l->elem[l->length++] = e;
}

/*合并线性表l1,l2*/
void MergeSq(SqList *l1, const SqList *l2)
{
	ElemType e;
	int i = 0;
	for (i = 0; i < l2->length; i++) {
		GetElem(l2, &e, i);
		if (ElemIsLocateSq(l1, &e) == false) {
			TailInsertSq(l1, e);
		}
	}
}

int main(void)
{
	SqList l1;
	InitListSq(&l1);
	SqList l2;
	InitListSq(&l2);
	
	//初始化线性表l1
	int i = 0;
	for (i = 0; i < l1.ListSize; i++) {
		l1.elem[i] = i+1;
		l1.length++;
	}

  //初始化线性表l2
	for (i = 0; i < l2.ListSize; i++) {
		l2.elem[i] = i;
		l2.length++;
	}
	l2.elem[2] = 111;
	l2.elem[5] = 1;

	MergeSq(&l1, &l2);
	//合并之后的线性表l1
	for (i = 0; i < l1.length; i++) {
		DEBUG_INFO("%d", l1.elem[i]);
	}
	return 0;
}
