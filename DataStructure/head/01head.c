/*
*2020-2-16
*�ѵ�ʵ�ּ����ֲ���
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef bool (*compare)(int left,int right);

/*�����ݽṹ*/
struct heap{
	int *hp;
	int size;/*���е���ЧԪ�ظ���*/
	int capacity;/*�ѵ�����*/
	compare cmp;
};

/*����С�ѱȽϺ���*/
bool less_heap(int a,int b);

/*������ѱȽϺ���*/
bool big_heap(int a,int b);

/*����*/
void swap(int *p_a,int *p_b);

/*������,����ѻ�*/
void create_heap(struct heap *hp,int *p_arr,int size,compare cmp);

/*���µ��ã���Ԫ���������棬���������µ����ɶ�*/
void adjust_down(struct heap *hp,int size,int parent);

/*���ϵ�������Ԫ���������棬���������µ����ɶ�*/
void adjust_up(struct heap *hp,int child);

/*�Ӷ���ɾ��һ��Ԫ��*/
bool remove_head(struct heap *hp,int *elem);

/*���������һ��Ԫ��*/
void insert_head(struct heap *hp,int elem);

/*������*/
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
���µ���,���²�����һ��С�ѵ��������
�����һ����Ҷ�ӽ�㿪ʼ������һֱ�����ڵ�Ϊֹ����ÿ����㼰����������������С�ѵ�����
1.���parent��һ����С�ѣ�ֱ�ӷ���
2.���parent��������С��������ӽ�����parentλ��
3.���parent���Һ�����С������Һ��ӽ�����parentλ��
*/
void adjust_down(struct heap *hp,int size,int parent)
{
	if (hp->hp == NULL){
		return;
	}
	
	/*��������ӽ���±�*/
	int child = parent*2 + 1;
	//printf("child0:%d\n",child);
	while(child <size){
		//�ѵ�ǰ��С�Ľ�㣬���������ڵ�λ��
		//printf("res1:%d\n",hp->cmp(hp->hp[child] ,hp->hp[child+1]));
		if (child + 1 < size/*��ֹ����Խ��*/ &&  hp->cmp(hp->hp[child+1] ,hp->hp[child])){
			child++;
			//printf("child:%d\n",child);
		}
		//printf("child:%d\n",child);
		//printf("res2:%d\n",hp->cmp(hp->hp[child] , hp->hp[parent]));
		if (hp->cmp(hp->hp[child] , hp->hp[parent])){
			//����С�Ľ��������ڵ�λ��
			swap(&(hp->hp[child]),&(hp->hp[parent]));
			//��Ϊwhile�˳������� 
			parent = child;
			child = parent*2 +1;
		}
		else{
 			//�����Ҷ�ӽ������С��,���õ���,ֱ�ӷ���
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
	
	/*��������ӽ���±�*/
	int child = parent*2 + 1;
	//printf("_adjust_down child:%d\n",child);
	while(child <size){
		//�ѵ�ǰ��С�Ľ�㣬���������ڵ�λ��
		//printf("res1:%d\n",hp->cmp(hp->hp[child] ,hp->hp[child+1]));
		if (child + 1 < size/*��ֹ����Խ��*/ &&  hp->cmp(hp->hp[child+1] ,hp->hp[child])){
			child++;
			//printf("child:%d\n",child);
		}
		//sprintf("child:%d\n",child);
		//printf("res2:%d\n",hp->cmp(hp->hp[child] , hp->hp[parent]));
		if (hp->cmp(hp->hp[child] , hp->hp[parent])){
			//����С�Ľ��������ڵ�λ��
			swap(&(hp->hp[child]),&(hp->hp[parent]));
			//printf("%d\n",hp->hp[0]);
			//printf("%d\n",hp->hp[1]);
			//��Ϊwhile�˳������� 
			parent = child;
			child = parent*2 +1;
		}
		else{
 			//�����Ҷ�ӽ������С��,���õ���,ֱ�ӷ���
			return;
		}
	}
}

/*
*������
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

/*�������Ԫ��*/
void adjust_up(struct heap *hp,int child)
{
	//�����ǰ���ڵ��±�,����child�������±껹���Һ����±꣬���¹�ʽ��������Ķ����丸�ڵ��±�
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

/*���������һ��Ԫ��*/
void insert_head(struct heap *hp,int elem)
{
	if (hp->size == hp->capacity){
		return;
	}
	
	hp->hp[hp->size] = elem;
	adjust_up(hp,hp->size);
	hp->size++;
}

/*Ԫ�س��Ӳ���*/
bool remove_head(struct heap *hp,int *elem)
{
	if (hp->size == 0){
		return false;
	}
	
	*elem = hp->hp[0];
	 //���������һ��Ԫ�طŵ����ڵ�
	 hp->hp[0] = hp->hp[hp->size-1];
	 //���е���ЧԪ�ؼ�1
	 hp->size--;
	 //���µ���
	 adjust_down(hp,hp->size,0);
	 return true;
}

/*������,����ѻ�*/
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
	
	//�ҵ�������Ҷ�ӽ����±� 
	int root  = (size - 2)/2;
	while(root>=0){
		adjust_down(hp,hp->size,root);
		root--;
	}	
}

/*����С�ѱȽϺ���*/
bool less_heap(int a,int b)
{
	return a<b;
}

/*������ѱȽϺ���*/
bool big_heap(int a,int b)
{
	return a>b;
}

/*����*/
void swap(int *p_a,int *p_b)
{
	int tmp = *p_a;
	*p_a = *p_b;
	*p_b = tmp;
}

