/*实现单链表的逆转*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*单链表数据结构*/
struct node{
	int elem;
	struct node *next;
};

struct node *head = NULL;

struct node* create_node(int elem)
{
		struct node *new = malloc(sizeof(struct node));
		if (new == NULL){
			return NULL;
		}

		new->next = NULL;
		new->elem = elem;
		return new;
}

/*尾插*/
void tail_insert_node(struct node **head,struct node *new)
{
	if (*head == NULL){
		*head = new;
		return;
	}

	struct node *p = *head;
	while(p->next){
		p = p->next;
	}
	p->next = new;
}

/*遍历*/
void traverse_list(struct node *head)
{
		if (head == NULL){
			return;
		}

		struct node *p = head;
		while(p){
			printf("traverse list:%d\n",p->elem);
			p = p->next;
		}
}

/*
单链表逆转方法一:迭代法
假设n是链表的长度，时间复杂度为O(n)
空间复杂度是O(1)
*/
struct node* reverse_list(struct node *head)
{
	struct node *prev = NULL;
	struct node *curr = head;
	while(curr != NULL){
		//把第一个节点分离出来
		struct node *next_tmp = curr->next;
		curr->next =  prev;
		//分离的第一个节点保存
		prev = curr;
		//指向第二个节点之后的链表段
		curr = next_tmp;
		
	}
	return prev;
}

/*
单链表逆转方法一:递归
假设n是链表的长度，时间复杂度为O(n)
空间复杂度是O(1)
*/
struct node* recur_reverse_list(struct node *head)
{
	//没有节点和只有一个节点的情况
	if (head ==NULL || head->next == NULL){
		return head;
	}
	
	struct node *p = reverse_list(head->next);
	head->next->next = head;
	head->next = NULL;
	return p;
}

int main(void)
{
	//tail_insert_node(&head,create_node(11));
	//tail_insert_node(&head,create_node(12));
	//tail_insert_node(&head,create_node(13));
	traverse_list(head);
	head = recur_reverse_list(head);
	printf("\n\n");
	traverse_list(head);
	return 0;
}
