/*
*合并两个线性表la,lb到lc,有序递增              
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG_INFO(fmt, args...) printf("\033[33m[%s:%s:%d]\033[0m "#fmt"\r\n", __FILE__,__FUNCTION__, __LINE__, ##args)

#define LISTINITSIZE  2
#define LISTINCREMENT 2
typedef int ElemType;

typedef struct {
	ElemType *elem;  
	int length;     
	int ListSize;    
}SqList;

void InitSqList(SqList *l)
{
	if (NULL == l) {
		return;
	}
	
	l->elem = malloc(sizeof(ElemType) * (LISTINITSIZE));
	if (NULL == l->elem)
		return;
	
	memset(l->elem, 0, LISTINITSIZE);
	
	l->length = 0;
	l->ListSize = LISTINITSIZE;
}

SqList * MergeSqList(SqList *l1, SqList  *l2)
{
	if (NULL == l1 || NULL == l2)
		return NULL;
	
	ElemType *NewBaseAddr = malloc(sizeof(ElemType) * (l1->ListSize + l2->ListSize));
	if (NULL == NewBaseAddr)
		return NULL;
	
	static SqList l3;
	l3.ListSize = l1->ListSize + l2->ListSize;
	l3.elem = NewBaseAddr;
	l3.length = 0;
	memset(l3.elem, 0, l3.ListSize*sizeof(ElemType));
	
	ElemType *PaLastElem = &(l1->elem[l1->length - 1]);
	ElemType *PbLastElem = &(l2->elem[l2->length - 1]);
	
	ElemType *PaElem = &(l1->elem[0]);
	ElemType *PbElem = &(l2->elem[0]);
	ElemType *PcElem = &(l3.elem[0]);

	while(PaElem <= PaLastElem && PbElem <= PbLastElem) {
		if (*PaElem < *PbElem) {
			*PcElem++ = *PaElem++;
			l3.length++;
		}
		else {
			if (*PaElem == *PbElem) {
				PbElem++;
			}
			else {
				*PcElem++ = *PbElem++;
				l3.length++;
			}
		}
	}

	while (PaElem <= PaLastElem) {
		*PcElem++ = *PaElem++;
		l3.length++;
	}
	
	while (PbElem <= PbLastElem) {
		*PcElem++ = *PbElem++;
		l3.length++;
	}
	
	return &l3;
}

int main(void)
{
	SqList la;
	InitSqList(&la);
	la.elem[0] = 12;
	la.elem[1] = 14;
	la.length = 2;
	
	SqList lb;
	InitSqList(&lb);
	lb.elem[0] = 12;
	lb.elem[1] = 81;
	lb.length = 2;
	
	SqList *lc = MergeSqList(&la, &lb);
	if (lc != NULL) {
		int i = 0;
		for (i; i < lc->length; i++) {
				DEBUG_INFO("%d", lc->elem[i]);	
		}
	}
	return 0;
}
