#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
插入排序
算法描述：
取出下标为n的元素，n-1与之比较，如果n-1大，则n-1覆盖n
依次循环
*/
void insert_sort(int *p_arr,int len)
{
	int i = 0,j = 0;
	//1.使用外层循环依次取出每个元素,从第二个元素起
	for(i = 1; i < len; i++)
	{
		//将每个取出的元素单独保存起来
		int temp = p_arr[i];
		//2.使用内层循环让取出的元素与左边的所有元素依次进行比较
		for(j = i;  j >= 1  && p_arr[j-1] > temp ; j--)
		{
			if(i == 4){
				printf("test\n");
			}
			p_arr[j] = p_arr[j-1];
		}
		//3.直到左边元素小于等于取出的元素时，将取出的元素插入到左边元素的右边
		if(j != i)
		{
			p_arr[j] = temp;
		}
	}
}

int main(void)
{
	int arr[] = {5,4,3,2,1};
	insert_sort(arr,sizeof(arr)/sizeof(arr[0]));
	
	int i = 0;
	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
