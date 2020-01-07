#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue{
		int elem;
		struct queue *next;
};

struct queue *head = NULL;

/*新建队列节点*/
struct queue *queue_create(int elem)
{
	struct queue *q = malloc(sizeof(struct queue));
	if (q == NULL)
		return NULL;

	q->elem = elem;
	q->next = NULL;
	return q;
}

/*入队*/
void queue_push(struct queue **head,struct queue *new)
{
	if (*head == NULL){
		*head = new;
		return;
	}

	struct queue *q = *head;
	while(q->next){
		q = q->next;
	}
	q->next = new;
}

/*遍历队列*/
void traverse_queue(const struct queue *head)
{
		const struct queue *q = head;
		while(q){
				printf("%d\n",q->elem);
				q = q->next;
		}
}

/*出队*/
void queue_pop(struct queue **head,int *elem)
{
	if (*head == NULL){
		return;
	}
	struct queue *q = *head;
	*head = q->next;
	*elem = q->elem;
	free(q);
}

int main(void)
{
	int i = 0;
	for(i; i < 2; ++i){
		queue_push(&head,queue_create(i+1));
	}
	int elem = 0;
	queue_pop(&head,&elem);
	printf("pop:%d\n",elem);
	traverse_queue(head);
	return 0;
}
