/*
 *线性表的删除操作,算法2.5,P24页
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG_INFO(fmt, args...) printf("\033[33m[%s:%s:%d]\033[0m "#fmt"\r\n", __FILE__,__FUNCTION__, __LINE__, ##args)

#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 1

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

/*线性表中删除元素*/
int ListDeleteSq(SqList *l , int i , ElemType *e)
{
	if (i < 1 || i > l->ListSize) {
		return FAILED;
	}

	ElemType *p = &(l->elem[i-1]);
	*e = *p;
	for (p; p < &(l->elem[l->length-1]); p++) {
		*p = *(p+1);
	}
	*p = 0;
	l->length--;
	return OK;
}

int main(void)
{
	SqList sl;
	InitListSq(&sl);
	
	int i = 0;
	for (i = 0; i < sl.ListSize; i++) {
		sl.elem[i] = i+1;
		sl.length++;
	}

	ElemType e;
	ListDeleteSq(&sl , 4 , &e);

	DEBUG_INFO("delete %d",e);
	for (i = 0; i < sl.ListSize; i++) {
		DEBUG_INFO("%d", sl.elem[i]);
	}
	return 0;
}
