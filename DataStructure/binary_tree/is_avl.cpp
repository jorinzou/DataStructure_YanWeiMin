#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

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

//插入新节点的递归函数
void insert(Node **pRoot,Node *pn);

/*判断是否为平衡二叉树*/
int is_avl(Node *pn, int &height);

int fun_cnt = 0;

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
	//insert(&(t->root),create_tree_node(30));
	//insert(&(t->root),create_tree_node(40));
	//insert(&(t->root),create_tree_node(5));
	//insert(&(t->root),create_tree_node(4));
	//insert(&(t->root),create_tree_node(6));
	//insert(&(t->root),create_tree_node(20));
	
	//右子树
	#if 1
	//insert(&(t->root),create_tree_node(80));
	//insert(&(t->root),create_tree_node(60));
	//insert(&(t->root),create_tree_node(55));
	//insert(&(t->root),create_tree_node(65));
	//insert(&(t->root),create_tree_node(90));
	//insert(&(t->root),create_tree_node(85));
	//insert(&(t->root),create_tree_node(100));
	#endif
	
	int height;
	int ret = is_avl(t->root,height);
	printf("ret=%d,fun_cnt=%d,height=%d\n",ret,fun_cnt,height);
	
	return 0;
}

/*
判断是否为平衡二叉树
递归解法：
(1)如果二叉树为空，返回真
(2)如果二叉树不为空，如果左子树和右子树都是AVL树并且左子树和右子树高度相差不大于1，返回1，其他返回0
*/
int is_avl(Node *pn, int &height)
{
	fun_cnt++;
	if (pn == NULL){
		height = 0;
		return 1;
	}
	int hleft;
	int rleft = is_avl(pn->left,hleft);
	
	int hright;
	int rright = is_avl(pn->right,hright);
	
	if (rleft && rright && abs(hleft-hright) <= 1){
		height = max(hleft,hright) +1;
		return 1;
	}
	else {
		height = max(hleft,hright) +1;
		return 0;
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

