/*
 *
 *算法3.1 ,进制转换
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG_INFO(fmt, args...) printf("\033[33m[%s:%s:%d]\033[0m "#fmt"\r\n", __FILE__,__FUNCTION__, __LINE__, ##args)

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 50

typedef int SElemType;

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
		printf("%d",*(s->top-1-i));
	}
	printf("\n");
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

int StackEmpty(SqStack *s)
{
	if (s->top == s->base)
		return 0;
	
	return 1;
}

#define NUM  90

/*十进制用八进制表示*/
int DecToOct(SqStack *s)
{
	int num = NUM;
	while(num){
		PushStack(s,num%8);
		num = num/8;
	}
	
	if(StackEmpty(s)){
		StackTraverse(s);
	}
}

/*十进制用二进制表示*/
int DecToBin(SqStack *s)
{
	int num = NUM;
	while(num){
		PushStack(s,num%2);
		num = num/2;
	}	
	if(StackEmpty(s)){
		StackTraverse(s);
	}
}

int main(void)
{
	SqStack s;
	memset(&s,0,sizeof(s));
	InitStack(&s);
	DecToBin(&s);
	
	return 0;
}






















