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

//插入新节点的递归函数
void insert(Node **pRoot,Node *pn);

//判断是否为平衡二叉树
bool is_complete_2xtree(Node *pn);

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
	insert(&(t->root),create_tree_node(80));
	insert(&(t->root),create_tree_node(60));
	//insert(&(t->root),create_tree_node(55));
	//insert(&(t->root),create_tree_node(65));
	//insert(&(t->root),create_tree_node(90));
	//insert(&(t->root),create_tree_node(85));
	insert(&(t->root),create_tree_node(100));
	#endif
	
	int res = is_complete_2xtree(t->root);
	printf("res=%d\n",res);
	
	return 0;
}

/*
判断是否为完全二叉树
算法描述
1.1 如果树为空，则直接返回错
1.2 如果树不为空，层序遍历二叉树
1.3 如果一个节点的左右孩子都不为空，则pop该节点,将其左右孩子入队
1.4 如果遇到一个结点，左孩子为空，在右孩子不为空，则该树一定不是完全二叉树
1.5 如果遇到一个节点，左孩子不为空,右孩子为空，或者左右孩子都为空，则该节点之后的队列所有结点都为叶子节点；该树才是完全二叉树，否则不是完全二叉树
*/
bool is_complete_2xtree(Node *root)
{
	//为空，非二叉树
	if (root == NULL){
		printf("test1\n");
		return false;
	}
	
	//入队
	queue <Node *>q;
	q.push(root);
	
	while(!q.empty()){
		Node *top = q.front();
		//如果一个节点的左右孩子都不为空，则pop该节点,将其左右孩子入队
		if (top->left  && top->right){
			q.pop();
			q.push(top->left);
			q.push(top->right);
		}
		
		//非二叉树
		if (top->left == NULL && top->right){
			printf("test2\n");
			return false;
		}
		
		//左孩子不为空,右孩子为空，或者左右孩子都为空，
		//则该节点之后的队列所有结点都为叶子节点；该树才是完全二叉树，否则不是完全二叉树
		if ((top->left && top->right == NULL) || (top->left == NULL && top->right == NULL)){
			if (top->left && top->right == NULL){
				q.push(top->left);
			}
			//该节点之后的所有节点都是叶子节点才是完全二叉树
			q.pop();
			
			while(!q.empty()){
				top = q.front();
				if (top->left  == NULL  && top->right == NULL){
					q.pop();
				}
				else{
					printf("test3\n");
					return false;
				}
			}
			return true;
		}
	}
	return true;
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

