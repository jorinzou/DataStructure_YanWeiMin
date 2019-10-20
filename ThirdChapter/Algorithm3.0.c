/*
 *
 *栈的各种基本操作,顺序实现,p47
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG_INFO(fmt, args...) printf("\033[33m[%s:%s:%d]\033[0m "#fmt"\r\n", __FILE__,__FUNCTION__, __LINE__, ##args)

/*栈初始大小*/
#define STACK_INIT_SIZE 4 
/*栈扩展大小*/
#define STACK_INCREMENT 4

typedef int SElemType;

/*栈数据结构*/
typedef struct {
	SElemType *base;
	SElemType *top;
	int StackSize;
}SqStack;

/*初始化栈大小*/
int InitStack(SqStack *s)
{
	s->base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (NULL == s->base){
		return -1;
	}
	
	s->top = s->base;
	s->StackSize = STACK_INIT_SIZE;
}

/*入栈*/
int PushStack(SqStack *s,SElemType e)
{
	/*栈满,扩展存储空间*/
	if(s->top - s->base == s->StackSize){
		s->base = realloc(s->base,(s->StackSize + STACK_INCREMENT)*sizeof(SElemType));
		if(NULL == s->base){
			return -1;
		}
		s->top = s->base + s->StackSize;
		s->StackSize += STACK_INCREMENT;
	}
	
	*s->top++ = e;
	return 0;
}

/*遍历栈操作*/
void StackTraverse(SqStack *s)
{
	int i = 0;
	///DEBUG_INFO("%d",s->top - s->base);
	for(i; i < s->top - s->base; i++){
		DEBUG_INFO("%d",*(s->base+i));
	}
}

/*出栈操作*/
int PopStack(SqStack *s,SElemType *e)
{
	if(s->top == s->base)
		return -1;
	
	*e = *(--s->top);
	return 0;
}

/*获取栈顶元素*/
int GetTop(SqStack *s,SElemType *e)
{
	if(s->top == s->base)
		return -1;
	
	*e = *(--s->top);
}

int main(void)
{
	SqStack s;
	memset(&s,0,sizeof(s));
	InitStack(&s);
	
	PushStack(&s,10);
	PushStack(&s,11);
	PushStack(&s,12);
	PushStack(&s,13);
	//DEBUG_INFO("%d",s.StackSize);
	StackTraverse(&s);
	printf("\n");
	SElemType e;
	PopStack(&s,&e);
	PopStack(&s,&e);
	StackTraverse(&s);
	
	printf("\n");
	GetTop(&s,&e);
	DEBUG_INFO("%d",e);
	
	return 0;
}






















