/*
*2020-2-18
*堆排序
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*堆数据结构*/
struct heap{
	int *hp;
	int size;/*堆中的有效元素个数*/
	int capacity;/*堆的容量*/
};

/*交换*/
void swap(int *p_a,int *p_b);

/*创建堆,数组堆化*/
void create_heap(struct heap *hp,int *p_arr,int size);

/*向下调用，新元素在最上面，就往下重新调整成堆*/
void adjust_down(struct heap *hp,int size,int parent);

/*堆排序*/
void head_sort(struct heap *hp);

int main(void)
{
	struct heap hp;
	int arr[] = {9,6,8,5,4};
	create_heap(&hp,arr,sizeof(arr)/sizeof(arr[0]));
	
	#if 0
	printf("%d\n",hp.hp[0]);
	printf("%d\n",hp.hp[1]);
	printf("%d\n",hp.hp[3]);
	printf("%d\n",hp.hp[2]);
	printf("%d\n",hp.hp[4]);
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
	
	printf("\n\n");
	
	
	return 0;
}

/*
向下调整
*/
void adjust_down(struct heap *hp,int size,int parent)
{
	if (hp->hp  == NULL){
		return;
	}
	int child = parent*2 +1;
	while (child < size){
		if ((child+1 < size) && hp->hp[child+1] > hp->hp[child]){
			child++;
		}
		if (hp->hp[child] >  hp->hp[parent]){
			swap(&(hp->hp[child]),&(hp->hp[parent]));
			parent = child;
			child = parent*2 +1;
		}
		else{
			return;
		}
	}
}

/*
*堆排序
a.将无需序列构建成一个堆，根据升序降序需求选择大顶堆或小顶堆;
b.将堆顶元素与末尾元素交换，将最大元素"沉"到数组末端;
c.重新调整结构，使其满足堆定义，然后继续交换堆顶元素与当前末尾元素，反复执行调整+交换步骤，直到整个序列有序。
*/
void head_sort(struct heap *hp)
{
	int size = hp->size;
	while(size > 0){
		swap(&(hp->hp[0]) , &(hp->hp[size-1]));
		size--;
		adjust_down(hp,size,0);
	}
}

/*创建堆,数组堆化*/
void create_heap(struct heap *hp,int *p_arr,int size)
{
	hp->hp = (int*)malloc(sizeof(int)*(size));
	if (hp->hp == NULL){
		return;
	}
	hp->capacity = size;
	hp->size = 0;
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

/*交换*/
void swap(int *p_a,int *p_b)
{
	int tmp = *p_a;
	*p_a = *p_b;
	*p_b = tmp;
}

