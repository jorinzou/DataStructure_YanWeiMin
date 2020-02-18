#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

//前序遍历
void pre_travel(Node *pn);

//中序遍历
void mid_travel(Node *pn);

//后序遍历
void last_travel(Node *pn);

//判断有序二叉树是否为空
int empty(Tree *pt);

//获取根节点元素值
int get_root_data(Node *pn);

//计算二叉树节点数量
int calc_node_sum(Node *pn);

//求二叉树的节点个数方法二
int get_node_num(Node *pn);

//清空销毁二叉树
void destroy_tree(Node **pn);

//二叉树查找,二级指针
Node** find(Node** pRoot,int data);

//一级指针
Node* find1(Node* pn,int data);

//删除节点
void delete_tree_node(Tree *pt,int data);

//求二叉树的深度
int get_tree_depth(Node* pn);

//求二叉树的叶子节点数量
int get_tree_leaf_num(Node* pn);

//求二叉树的镜像
Node *tree_mirror(Node *pn);

//判断是否为满二叉树
int is_full_tree(Node *pn);

int fun_cnt = 0;

int main(void)
{
	Tree *t = malloc(sizeof(Tree));
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
	//insert(&(t->root),create_tree_node(100));
	#endif
	
	int ret = is_avl(t->root);
	printf("ret=%d,fun_cnt=%d\n",ret,fun_cnt);
	
	return 0;
}

/*
判断是否为满二叉树
(1)空树，满
(2)左满右满，且左右深度相等，满
(3)否则，非满
*/
int is_full_tree(Node *pn)
{
	fun_cnt++;
	if(pn == NULL){
		return 1;
	}
	int left_depth = get_tree_depth(pn->left);
	int right_depth = get_tree_depth(pn->right);
	
	int left_true = is_full_tree(pn->left);
	int right_true = is_full_tree(pn->right);
	
	if(left_true && right_true && (left_depth == right_depth)){
		return 1;
	}
	else{
		return 0;
	}
}

/*
  求二叉树的镜像 
（1）如果二叉树为空，返回空
（2）如果二叉树不为空，求左子树和右子树的镜像，然后交换左子树和右子树
*/
Node *tree_mirror(Node *pn)
{
	if (NULL == pn){
		return NULL;
	}
	
	//求左子树镜像
	Node *pleft = tree_mirror(pn->left);
	//求右子树镜像
	Node * pright = tree_mirror(pn->right);
	
	//交换左子树和右子树
	pn->left = pright;
	pn->right = pleft;
	return pn;
}

/*
 求二叉树的叶子节点数量
（1）如果二叉树为空，返回0
（2）如果二叉树不为空且左右子树为空，返回1
（3）如果二叉树不为空，且左右子树不同时为空，返回左子树中叶子节点个数加上右子树中叶子节点个数
*/
int get_tree_leaf_num(Node* pn)
{
	if (pn == NULL){
		return 0;
	}
	
	if (pn->left == NULL && pn->right == NULL){
		return 1;
	}
	
	int left_leaf_num = get_tree_leaf_num(pn->left);
	int right_leaf_num = get_tree_leaf_num(pn->right);
	return (left_leaf_num+right_leaf_num);
}

/*
  求二叉树的深度
（1）如果二叉树为空，二叉树的深度为0
（2）如果二叉树不为空，二叉树的深度 = max(左子树深度， 右子树深度) + 1
*/
int get_tree_depth(Node* pn)
{
	if (pn == NULL){
		return 0;
	}
	
	int left_num = get_tree_depth(pn->left);
	int right_num = get_tree_depth(pn->right);
	return right_num > left_num?right_num+1:left_num+1;
}

//删除节点
void delete_tree_node(Tree *pt,int data)
{
	Node **ppn = find (&(pt->root),data);
	if (*ppn == NULL){
		return;
	}
	
	//将左子树，转移到右子树
	//1.如果右子树为NULL，则将左子树插入到(*ppn)->right
	//2.如果右子树不为NULL，则将左子树插入到右子树(*ppn)->right->left
	if ((*ppn)->left != NULL){
		insert(&((*ppn)->right),(*ppn)->left);
	}
	
	Node *pn = *ppn;
	*ppn = (*ppn)->right;
	free(pn);
	pn = NULL;
}

//二叉树查找，一级指针
Node* find1(Node* pn,int data)  
{
	 if (pn == NULL){
		 return pn;
	 }
	 if (pn->data == data){
		 return pn;
	 }
	 else if (data < pn->data){
		return  find1(pn->left,data);
	 }
	 else{
		 return find1(pn->right,data);
	 }
}

//二叉树查找,二级指针
Node** find(Node** pn,int data)
{
	 if (*pn == NULL){
		 return pn;
	 }
	 if ((*pn)->data == data){
		 return pn;
	 }
	 else if (data < (*pn)->data){
		 return find (&((*pn)->left),data);
	 }
	 else{
		 return find (&((*pn)->right),data);
	 }
}

//清空销毁二叉树
void destroy_tree(Node **pn)
{
	if (*pn != NULL){
		destroy_tree(&((*pn)->left));
		destroy_tree(&((*pn)->right));
		free(*pn);
		*pn = NULL;
	}
}

//计算二叉树节点数量
int calc_node_sum(Node *pn)
{
	static int cnt = 0;
	if (pn != NULL){
		calc_node_sum(pn->left);
		cnt++;
		calc_node_sum(pn->right);
	}
	return cnt;
}

//求二叉树节点个数
int get_node_num(Node *pn)
{
	if (pn == NULL){
		return 0;
	}
	
	return get_node_num(pn->right) + get_node_num(pn->left) + 1;
}

//获取根节点元素值
int get_root_data(Node *root)
{
	return root==NULL?-1:root->data;
}

//判断有序二叉树是否为空
int empty(Tree *pt)
{
	return pt == NULL?1:(NULL == pt->root);
}

//前序遍历
void pre_travel(Node *pn)
{
	if (pn != NULL){
		printf("%d |",pn->data);
		pre_travel(pn->left);
		pre_travel(pn->right);
	}
	return;
}

//中序遍历
void mid_travel(Node *pn)
{
	if (pn != NULL){
		mid_travel(pn->left);
		printf("%d |",pn->data);
		mid_travel(pn->right);
	}
	return;
}

//后序遍历
void last_travel(Node *pn)
{
	if (pn != NULL){
		last_travel(pn->left);
		last_travel(pn->right);
		printf("%d |",pn->data);
	}
	return;
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

