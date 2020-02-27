#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
�㷨������
1.�ҵ�һ����׼ֵ(һ����β������)
2.�ѱ�������Ԫ�ط��������ұߣ�����С��Ԫ�ط������
3.�ٶ����������ظ��ڶ�����ֱ��������ֻ��һ����
*/

/*����������*/
void swap(int *p_low,int *p_high)
{
	printf("%d,%d\n",*p_low,*p_high);
	int temp = *p_low;
	*p_low = *p_high;
	*p_high = temp;
}

int partition(int *arr,int low,int high)
{
	int base = arr[low];
	while(low < high){
		
		while(low < high && arr[high] >= base){
			--high;
		}
		
		swap(&arr[low],&arr[high]);
		
		while(low < high && arr[low] <= base){
			++low;
		}
		
		swap(&arr[low],&arr[high]);
	}
	return low;
}

void quick_sort(int *arr,int low, int high)
{
	if (low < high){
		int base = partition(arr,low,high);
		printf("base=%d\n",base);
		return;
		quick_sort(arr,low,base-1);
		quick_sort(arr,base+1,high);
	}
	else{
		return;
	}
}

int main(void)
{
	int arr[] = {5,4,3,2,1};
	quick_sort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	return;
	int i = 0;
	for(i; i < sizeof(arr)/sizeof(arr[0]); ++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}