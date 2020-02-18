#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdbool.h>
#include <queue>

using namespace std;

typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}Node;

typedef struct{
	Node *root;//根节点地址
	int cnt;//节点元素个数
}Tree;

//插入新元素到有序二叉树中
Node*  create_tree_node(int data);

/*水平层遍历二叉树，从上到下，从左到右*/
void level_travel_2xtree(Node *root);

//插入新节点的递归函数
void insert(Node **pRoot,Node *pn);

int main(void)
{
	Tree *t = (Tree *)malloc(sizeof(Tree));
	if (NULL == t){
		return -1;
	}
	
	t->cnt = 0;
	t->root = NULL;
	
	//根节点
	insert(&(t->root),create_tree_node(50));
	
	//左子树
	insert(&(t->root),create_tree_node(10));
	insert(&(t->root),create_tree_node(30));
	insert(&(t->root),create_tree_node(40));
	insert(&(t->root),create_tree_node(5));
	insert(&(t->root),create_tree_node(4));
	insert(&(t->root),create_tree_node(6));
	insert(&(t->root),create_tree_node(20));
	
	//右子树
	#if 1
	insert(&(t->root),create_tree_node(80));
	insert(&(t->root),create_tree_node(60));
	insert(&(t->root),create_tree_node(55));
	insert(&(t->root),create_tree_node(65));
	insert(&(t->root),create_tree_node(90));
	insert(&(t->root),create_tree_node(85));
	insert(&(t->root),create_tree_node(100));
	#endif
	
	level_travel_2xtree(t->root);
	printf("\n");
	
	return 0;
}

/*分层遍历二叉树*/
void level_travel_2xtree(Node *root)
{
	queue<Node *>q;
	
	if(root == NULL){
		return;
	}
	
	q.push(root);
	
	while(!q.empty()){
		Node *pn = q.front();
		printf("%d |",pn->data);
		if (pn->left != NULL){
			q.push(pn->left);
		}
		if (pn->right != NULL){
			q.push(pn->right);
		}
		q.pop();
	}
	
}

//插入新元素到有序二叉树中
Node*  create_tree_node(int data)
{
	Node* pt = (Node*)malloc(sizeof(Node));
	if (NULL == pt){
		return NULL;
	}
	
	pt->data = data;
	pt->left = NULL;
	pt->right = NULL;
	
	return pt;
}

//插入新节点的递归函数
void insert(Node **pRoot,Node *pn)
{
	if (NULL == *pRoot){
		*pRoot = pn;
		return;
	}
	
	if (pn->data < (*pRoot)->data){
		insert(&((*pRoot)->left),pn);
	}
	else{
		insert(&((*pRoot)->right),pn);
	}
}

