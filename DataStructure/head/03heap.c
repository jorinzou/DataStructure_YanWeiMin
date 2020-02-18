/*
*2020-2-18
*判断是否为小堆
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

/*判断是否为大堆*/
void is_big_heap(struct heap *hp);

int main(void)
{
	struct heap hp;
	int arr[] = {9,6,8,5,4};
	//create_heap(&hp,arr,sizeof(arr)/sizeof(arr[0]));
	
	#if 0
	printf("%d\n",hp.hp[0]);
	printf("%d\n",hp.hp[1]);
	printf("%d\n",hp.hp[3]);
	printf("%d\n",hp.hp[2]);
	printf("%d\n",hp.hp[4]);
	#endif
	
	return 0;
}

bool is_big_heap(int *p_arr,int size)
{
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

