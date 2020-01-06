/*
 *
 *栈的链式实现
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//栈元素
struct node{
	int elem;
	struct node *next;
};

struct stack{
	int cnt;//当前栈中有效元素个数
	struct node *top;//栈顶元素
};

/*创建栈*/
struct node* create_stack_node(int elem)
{
		struct node *p = malloc(sizeof(struct node));
		if (p == NULL){
			return;
		}

		p->elem = elem;
		p->next = NULL;
		return p;
}	

//入栈
void push_stack(struct node *new,struct stack *s)
{
	struct node *p= s->top;
	if (p == NULL){
		s->top = new;
		s->cnt++;
		return;
	}
	while(p->next){
		p = p->next;
	}
	p->next = new;
	s->cnt++;
}

//遍历
void traverse_stack(struct stack *s)
{
	struct node *p = s->top;
	while(p){
		printf("%s:stack node is:%d\n",__FUNCTION__,p->elem);
		p = p->next;
	}
}

//出栈
void pop_stack(struct stack *s,int *elem)
{
	if (s->top == NULL){
		return;
	}

	struct node *p = s->top;
	s->top = p->next;
	*elem = p->elem;
	free(p);
	s->cnt--;
}

void get_stack_top(struct stack *s,int *elem)
{
	if (s->top == NULL)
		return;

	*elem = s->top->elem;
}

int main(void)
{
	struct stack s;
	s.cnt = 1;
	s.top = create_stack_node(111);
	int i = 1;
	for(i; i < 1; ++i){
		push_stack(create_stack_node(111+i),&s);
	}
	traverse_stack(&s);
	int elem = -1;
	#if 0
	pop_stack(&s,&elem);
	printf("pop elem=%d\n",elem);
	traverse_stack(&s);
	#endif

	get_stack_top(&s,&elem);
	printf("top elem=%d\n",elem);

	return 0;
}

