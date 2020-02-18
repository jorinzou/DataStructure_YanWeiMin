/*
*2020-2-16
*堆的实现及各种操作
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef bool (*compare)(int left,int right);

/*堆数据结构*/
struct heap{
	int *hp;
	int size;/*堆中的有效元素个数*/
	int capacity;/*堆的容量*/
	compare cmp;
};

/*建立小堆比较函数*/
bool less_heap(int a,int b);

/*建立大堆比较函数*/
bool big_heap(int a,int b);

/*交换*/
void swap(int *p_a,int *p_b);

/*创建堆,数组堆化*/
void create_heap(struct heap *hp,int *p_arr,int size,compare cmp);

/*向下调用，新元素在最上面，就往下重新调整成堆*/
void adjust_down(struct heap *hp,int size,int parent);

/*向上调整，新元素在最下面，就往下重新调整成堆*/
void adjust_up(struct heap *hp,int child);

/*从堆中删除一个元素*/
bool remove_head(struct heap *hp,int *elem);

/*往堆中添加一个元素*/
void insert_head(struct heap *hp,int elem);

/*堆排序*/
void head_sort(struct heap *hp);

int main(void)
{
	struct heap hp;
	int arr[] = {15,1,78};
	create_heap(&hp,arr,sizeof(arr)/sizeof(arr[0]),less_heap);
	
	#if 0
	//int elem;
	//remove_head(&hp,&elem);
	//insert_head(&hp,0);
	printf("%d\n",hp.hp[0]);
	printf("%d\n",hp.hp[1]);
	printf("%d\n",hp.hp[3]);
	printf("%d\n",hp.hp[4]);
	printf("%d\n",hp.hp[2]);
	printf("%d\n",hp.hp[5]);
	#endif
	
	int i = 0;
	for(i=0; i < hp.size; i++){
		printf("%d ",hp.hp[i]);
	}
	printf("\n\n");
	
	head_sort(&hp);
	
	for(i=0; i < hp.size; i++){
		printf("%d ",hp.hp[i]);
	}
	printf("\n");
	
	return 0;
}

/*
向下调整,以下步骤是一个小堆的情况描述
从最后一个非叶子结点开始调整，一直到根节点为止，将每个结点及其子树调整到满足小堆的性质
1.如果parent是一个最小堆，直接返回
2.如果parent的左孩子最小，则把左孩子交换到parent位置
3.如果parent的右孩子最小，则把右孩子交换到parent位置
*/
void adjust_down(struct heap *hp,int size,int parent)
{
	if (hp->hp == NULL){
		return;
	}
	
	/*计算出左孩子结点下标*/
	int child = parent*2 + 1;
	//printf("child0:%d\n",child);
	while(child <size){
		//把当前最小的结点，交换到父节点位置
		//printf("res1:%d\n",hp->cmp(hp->hp[child] ,hp->hp[child+1]));
		if (child + 1 < size/*防止数组越界*/ &&  hp->cmp(hp->hp[child+1] ,hp->hp[child])){
			child++;
			//printf("child:%d\n",child);
		}
		//printf("child:%d\n",child);
		//printf("res2:%d\n",hp->cmp(hp->hp[child] , hp->hp[parent]));
		if (hp->cmp(hp->hp[child] , hp->hp[parent])){
			//把最小的交换到父节点位置
			swap(&(hp->hp[child]),&(hp->hp[parent]));
			//作为while退出的条件 
			parent = child;
			child = parent*2 +1;
		}
		else{
 			//这个非叶子结点是最小堆,不用调整,直接返回
			return;
		}
	}
}

void _adjust_down(struct heap *hp,int size,int parent)
{
	//printf("test1\n");
	if (hp->hp == NULL){
		return;
	}
	
	/*计算出左孩子结点下标*/
	int child = parent*2 + 1;
	//printf("_adjust_down child:%d\n",child);
	while(child <size){
		//把当前最小的结点，交换到父节点位置
		//printf("res1:%d\n",hp->cmp(hp->hp[child] ,hp->hp[child+1]));
		if (child + 1 < size/*防止数组越界*/ &&  hp->cmp(hp->hp[child+1] ,hp->hp[child])){
			child++;
			//printf("child:%d\n",child);
		}
		//sprintf("child:%d\n",child);
		//printf("res2:%d\n",hp->cmp(hp->hp[child] , hp->hp[parent]));
		if (hp->cmp(hp->hp[child] , hp->hp[parent])){
			//把最小的交换到父节点位置
			swap(&(hp->hp[child]),&(hp->hp[parent]));
			//printf("%d\n",hp->hp[0]);
			//printf("%d\n",hp->hp[1]);
			//作为while退出的条件 
			parent = child;
			child = parent*2 +1;
		}
		else{
 			//这个非叶子结点是最小堆,不用调整,直接返回
			return;
		}
	}
}

/*
*堆排序
*/
void head_sort(struct heap *hp)
{
	int size = hp->size;
	while(size){
		swap(&(hp->hp[0]),&(hp->hp[size-1]));
		size--;
		_adjust_down(hp,size,0);
		//return;
	}
}

/*插入的新元素*/
void adjust_up(struct heap *hp,int child)
{
	//求出当前父节点下标,无论child是左孩子下标还是右孩子下标，以下公式计算出来的都是其父节点下标
	int parent = (child-1)/2;
	while(child > 0){
		if (hp->cmp(hp->hp[child] , hp->hp[parent])){
			swap(&hp->hp[child],&hp->hp[parent]);
			child = parent;
			parent = (child-1)/2;
		}
		else{
			return;
		}
	}
}

/*往堆中添加一个元素*/
void insert_head(struct heap *hp,int elem)
{
	if (hp->size == hp->capacity){
		return;
	}
	
	hp->hp[hp->size] = elem;
	adjust_up(hp,hp->size);
	hp->size++;
}

/*元素出队操作*/
bool remove_head(struct heap *hp,int *elem)
{
	if (hp->size == 0){
		return false;
	}
	
	*elem = hp->hp[0];
	 //把数组最后一个元素放到根节点
	 hp->hp[0] = hp->hp[hp->size-1];
	 //堆中的有效元素减1
	 hp->size--;
	 //重新调整
	 adjust_down(hp,hp->size,0);
	 return true;
}

/*创建堆,数组堆化*/
void create_heap(struct heap *hp,int *p_arr,int size,compare cmp)
{
	hp->hp = (int*)malloc(sizeof(int)*(size));
	if (hp->hp == NULL){
		return;
	}
	hp->capacity = size;
	hp->size = 0;
	hp->cmp = cmp;
	int i = 0;
	for(i; i < size; i++){
		hp->hp[i] = p_arr[i];
	}
	hp->size = size;
	
	//找到最后个非叶子结点的下标 
	int root  = (size - 2)/2;
	while(root>=0){
		adjust_down(hp,hp->size,root);
		root--;
	}	
}

/*建立小堆比较函数*/
bool less_heap(int a,int b)
{
	return a<b;
}

/*建立大堆比较函数*/
bool big_heap(int a,int b)
{
	return a>b;
}

/*交换*/
void swap(int *p_a,int *p_b)
{
	int tmp = *p_a;
	*p_a = *p_b;
	*p_b = tmp;
}

