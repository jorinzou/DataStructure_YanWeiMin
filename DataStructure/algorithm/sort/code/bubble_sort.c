#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*ð������*/
void bubble_sort_1(int *p_arr, int len)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < len - 1; ++i){//����Ԫ��������Ԫ�ض�Ҫ�Ƚ�һ��
	   //len = 5,�ڶ���forѭ��������һ��Ԫ��������Ԫ�ض�Ҫ�Ƚ�һ��,��i����Ϊǰһ�αȽ�������һ��Ҫ�Ƚϵ�Ԫ���Ѿ��ȽϹ�һ����
		for(j = 0; j < len - 1 - i ; ++j){
			if (p_arr[j] > p_arr[j+1]){
				int tmp = p_arr[j+1];
				p_arr[j+1] = p_arr[j];/*��ķŵ�����*/
				p_arr[j] = tmp;/*С�ķŵ�ǰ��*/
			}
		}
	}
}

/*ð�����򣬵�ԭ�������������ʱ��ʱ�临�Ӷ���O(n),ֻҪɨ��һ�ξͿ�����*/
void bubble_sort_2(int *p_arr, int len)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	int for_1 = 0;
	int for_2 = 0;
	
	for(i = 0; i < len - 1; ++i){//����Ԫ��������Ԫ�ض�Ҫ�Ƚ�һ�Σ�i < len -1 ,�����ڵ�ԭ��������ָ���
	   //len = 5,�ڶ���forѭ��������һ��Ԫ��������Ԫ�ض�Ҫ�Ƚ�һ��,��i����Ϊǰһ�αȽ�������һ��Ҫ�Ƚϵ�Ԫ���Ѿ��ȽϹ�һ����
	   //j < len - 1 1.�����ڵ�ԭ��,��ֹ����Խ��
	   for_1++;
	   flag = 1;
		for(j = 0; j < len - 1 - i ; ++j){
			for_2++;
			if (p_arr[j] > p_arr[j+1]){
				int tmp = p_arr[j+1];
				p_arr[j+1] = p_arr[j];/*��ķŵ�����*/
				p_arr[j] = tmp;/*С�ķŵ�ǰ��*/
				flag = 0;
			}
		}
		if(flag){
			break;
		}
	}
	
	printf("%d,%d\n",for_1,for_2);
}

int main(void)
{
	//int arr[] = {2,3,4,5,7};ʱ�临�Ӷ����
	int arr[] = {7,5,4,3,2};//ʱ�临�Ӷ��������
	bubble_sort_2(arr,sizeof(arr)/sizeof(arr[0]));
	int i = 0;
	for(i; i < sizeof(arr)/sizeof(arr[0]); ++i){
		printf("%d  ",arr[i]);
	}
	printf("bubble\n");
	return 0;
}