/*
*2020-2-18
*������
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*�����ݽṹ*/
struct heap{
	int *hp;
	int size;/*���е���ЧԪ�ظ���*/
	int capacity;/*�ѵ�����*/
};

/*����*/
void swap(int *p_a,int *p_b);

/*������,����ѻ�*/
void create_heap(struct heap *hp,int *p_arr,int size);

/*���µ��ã���Ԫ���������棬���������µ����ɶ�*/
void adjust_down(struct heap *hp,int size,int parent);

/*������*/
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
���µ���
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
*������
a.���������й�����һ���ѣ���������������ѡ��󶥶ѻ�С����;
b.���Ѷ�Ԫ����ĩβԪ�ؽ����������Ԫ��"��"������ĩ��;
c.���µ����ṹ��ʹ������Ѷ��壬Ȼ����������Ѷ�Ԫ���뵱ǰĩβԪ�أ�����ִ�е���+�������裬ֱ��������������
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

/*������,����ѻ�*/
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
	
	//�ҵ�������Ҷ�ӽ����±� 
	int root  = (size - 2)/2;
	while(root>=0){
		adjust_down(hp,hp->size,root);
		root--;
	}	
}

/*����*/
void swap(int *p_a,int *p_b)
{
	int tmp = *p_a;
	*p_a = *p_b;
	*p_b = tmp;
}

