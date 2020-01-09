/*
 *有序二叉树
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct binary_tree{
	struct node *root;/*根节点*/
	int cnt;
};

/*创建根节点*/
struct binary_tree *create_root_node(void)
{
	struct binary_tree *bt = malloc(sizeof(struct binary_tree));
	if (bt == NULL){
		return NULL;
	}
	bt->root = NULL;
	bt->cnt = 0;
	return bt;
}

/*创建树节点*/
struct node *create_tree_node(int data)
{
	struct node *tn = malloc(sizeof(struct node));
	if(tn == NULL){
		return NULL;
	}

	tn->left = NULL;
	tn->right = NULL;
	tn->data = data;
	return tn;
}

/*插入节点*/
void insert_node(struct node **root,struct node *new)
{
	if (*root == NULL){
		*root = new;		
		return;
	}

	if (new->data < (*root)->data){
		insert_node(&(*root)->left,new);
	}
	else{
		insert_node(&(*root)->right,new);
	}
}

/*遍历节点*/
void traverse_node(struct node *root)
{
	if (root != NULL){
		//traverse_node(root->left);
		traverse_node(root->right);
		printf("%d\n",root->data);
		traverse_node(root->left);
		//traverse_node(root->right);
	}
}

int main(void)
{
	int i = 0;
	struct binary_tree *bt = create_root_node();
	if (bt == NULL){
		return;
	}
	
	insert_node(&(bt->root),create_tree_node(5000));
	insert_node(&(bt->root),create_tree_node(4000));
	insert_node(&(bt->root),create_tree_node(3000));
	insert_node(&(bt->root),create_tree_node(2000));
	insert_node(&(bt->root),create_tree_node(1000));
	insert_node(&(bt->root),create_tree_node(6000));

	traverse_node(bt->root);
	return 0;
}
