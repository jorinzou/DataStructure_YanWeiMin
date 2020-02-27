#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
选择排序
算法描述：
1.n个元素，假设第一个是最小的，和剩余的n-1个比较，找到比这个小的排到最前面来
2.剩余n-1个元素,假设第一个是最小的，依次比较，把最小的交换到前面来
循环到结束
*/
void select_sort(int *p_arr,int len)
{
	int i = 0, j = 0;
	int min  = i;
	for(i = 0; i < len -1; ++i){//这里如果不-1,当i 是最后一个元素时，会导致数据越界
		min = i;
		for(j = i + 1; j < len/*这里如果-1只会比较交换前两个元素*/; ++j){
			printf("test\n");
			if (p_arr[j] > p_arr[min]){
				min = j;
			}
		}
		
		if (min != i){
			int temp = p_arr[i];
			p_arr[i] = p_arr[min];
			p_arr[min] = temp;
		}
	}
}

int main(void)
{
	int arr[] = {5,4,3,100};
	select_sort(arr,sizeof(arr)/sizeof(arr[0]));
	
	int i = 0;
	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	return 0;
}