/*
 *队列的顺序存储
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct queue
{
	int *arr;
	int len;//最多存储元素个数
	int front;//首元素下标
	int cnt;//有效元素个数
};

/*创建队列*/
struct queue *queue_create(int len)
{
		struct queue *q = malloc(sizeof(struct queue));
		q->arr = malloc(sizeof(int)*len);
		q->len = len;
		q->front = 0;
		q->cnt = 0;
}

/*入队*/
void queue_push(int elem,struct queue *q)
{
	if (q == NULL){
		return;
	}

	q->arr[(q->front+q->cnt)%q->len] = elem;
	q->cnt++;
	printf("%d\n",q->cnt);
}

/*遍历队列*/
void queue_traverse(const struct queue *q)
{
	int i = q->front;
	for(i; i < q->front + q->cnt; ++i){
		printf("%d\n",q->arr[i]);
	}
}

/*出队*/
int queue_pop(struct queue *q)
{
	int temp = q->arr[q->front++];
	q->cnt--;
	return temp;
}

/*判断队列是否为空*/
bool queue_empty(const struct queue *q)
{
		return q->cnt == 0;
}

/*判断队列是否为满*/
bool queue_full(const struct queue *q)
{
		return q->cnt == q->len;
}

int main(void)
{
	struct queue *q = queue_create(5);
	int i = 0;
	for(i; i < 5; i++){
		queue_push(i+1000,q);
	}
	queue_pop(q);
	queue_traverse(q);
	free(q);
	free(q->arr);
	return 0;
}
