#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
算法描述：
1.找到一个基准值(一般是尾或者首)
2.把比这个大的元素放在它的右边，比它小的元素放在左边
3.再对左右区间重复第二步，直到各区间只有一个数
*/

/*交换两个数*/
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