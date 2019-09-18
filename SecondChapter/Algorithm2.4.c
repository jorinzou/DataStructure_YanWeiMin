/*
 *线性表的插入操作,算法2.4,P23页
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

/*线性表中插入元素*/
int ListInsertSq(SqList *l , int i , ElemType e)
{
	if (i < 1 || i > l->ListSize) {
		return FAILED;
	}

	//增加存储空间
	if (l->length >= l->ListSize) {
		ElemType* NewElemBaseAddr = realloc(l->elem , sizeof(ElemType) * (LIST_INIT_SIZE + LIST_INCREMENT));
		if (NULL == NewElemBaseAddr) {
			return FAILED;
		}
		
		l->elem = NewElemBaseAddr;
		l->ListSize += LIST_INCREMENT;
	}

	ElemType *p = &(l->elem[i-1]);
	ElemType *q = NULL;

	for (q = &(l->elem[l->length - 1]); q >= p; q--) {
		*(q+1) = *q;
	}

	*p = e;
	l->length++;
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

	ListInsertSq(&sl , 10 , 1298);

	for (i = 0; i < sl.ListSize; i++) {
		DEBUG_INFO("%d", sl.elem[i]);
	}
	return 0;
}
