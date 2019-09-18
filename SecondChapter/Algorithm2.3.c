/*
 * 构造一个线性表
 *p23页
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

int main(void)
{
	SqList l;
	InitListSq(&l);
	
	l.elem[0] = 6;
	l.elem[1] = 7;
	l.elem[2] = 9;
	l.length = 3;

	int i = 0;
	for (i = 0; i < l.ListSize; i++) {
		DEBUG_INFO("%d", l.elem[i]);
	}
	return 0;
}
