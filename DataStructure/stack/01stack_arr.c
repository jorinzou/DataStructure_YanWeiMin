/*
 *数据结构栈的各种操作
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ELEM_TYPE;

struct stack {
	int len;//栈的大小
	int pos;//数组下标
	ELEM_TYPE *arr;
};

/*创建栈*/
struct stack *create_stack(int size)
{
	if (size == 0){
		return NULL;
	}

	struct stack *s = (struct stack*)malloc(sizeof(struct stack));
	ELEM_TYPE *e = (ELEM_TYPE*)malloc(sizeof(ELEM_TYPE)*size);
	if (e == NULL){
		free(s);
		return NULL;
	}

	s->len = size;
	s->pos = 0;
	s->arr =  e;

	return s;
}

/*销毁栈*/
void destroy_stack(struct stack *s)
{
	if (s->arr != NULL){
		free(s->arr);
		s->arr = NULL;
	}
	
	if (s != NULL){
		free(s);
		s = NULL;
	}
}

/*判断栈是否满*/
bool stack_full(struct stack *s)
{
		return s->len == s->pos;
}

/*入栈操作*/
ELEM_TYPE push_stack(struct stack *s,ELEM_TYPE elem)
{
	if (s->len == s->pos){
		return -1;
	}
	return s->arr[s->pos++] = elem;
}

/*元素出栈*/
ELEM_TYPE pop_stack(struct stack *s)
{
	ELEM_TYPE elem = s->arr[--(s->pos)];
	s->arr[s->pos] = 0;
	return elem;
}

/*打印栈元素*/
void print_stack(struct stack *s)
{
	if (s == NULL)
		return;

	int i = 0;
	for(i; i < s->len; ++i){
		printf("elem=%d\n",s->arr[i]);
	}
}

int main(void)
{
	struct stack *s = create_stack(5);
	if (s == NULL){
		return -1;
	}
	
	if (!stack_full(s)){
			int i = 0;
			for(i=0; i < s->len; ++i){
				push_stack(s,i+1000);
			}
	}

	print_stack(s);
	ELEM_TYPE elem = pop_stack(s);
	printf("pop elem=%d\n",elem);
	print_stack(s);
	destroy_stack(s);
	return 0;
}
