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

/*头插*/
void head_insert_node(struct node **head,struct node *new)
{
		if (*head == NULL){
			*head = new;
			return;
		}

		struct node *p = *head;
		*head = new;
		new->next = p;
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

/*删除节点*/
int delete_node(struct node **head,int elem)
{
		struct node *p = *head;
		struct node *prev = *head;
		int temp = 0;
		while(p){
			if (p->elem == elem){
				 		if (prev == *head){
							*head = p->next;
							temp = p->elem;
							free(p);
							return temp; 
						}
						else{
							prev->next = p->next;
							temp = p->elem;
							free(p);
							return temp;
						}
			}
			prev = p;
			p = p->next;
		}
}

int main(void)
{
	int i;
	for(i = 0; i < 0; ++i){
		tail_insert_node(&head,create_node(i+1));
		//head_insert_node(&head,create_node(i+1));
	}
	traverse_list(head);
	delete_node(&head,0);
	printf("\n\n");
	traverse_list(head);
	return 0;
}
