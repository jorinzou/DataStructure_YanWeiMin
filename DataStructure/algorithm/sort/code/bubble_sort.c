#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*冒泡排序*/
void bubble_sort_1(int *p_arr, int len)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < len - 1; ++i){//所有元素与其它元素都要比较一次
	   //len = 5,第二个for循环，其中一个元素与其它元素都要比较一次,减i是因为前一次比较中与下一次要比较的元素已经比较过一次了
		for(j = 0; j < len - 1 - i ; ++j){
			if (p_arr[j] > p_arr[j+1]){
				int tmp = p_arr[j+1];
				p_arr[j+1] = p_arr[j];/*大的放到后面*/
				p_arr[j] = tmp;/*小的放到前面*/
			}
		}
	}
}

/*冒泡排序，当原有数据是有序的时候，时间复杂度是O(n),只要扫描一次就可以了*/
void bubble_sort_2(int *p_arr, int len)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	int for_1 = 0;
	int for_2 = 0;
	
	for(i = 0; i < len - 1; ++i){//所有元素与其它元素都要比较一次，i < len -1 ,不等于的原因，下面出现负数
	   //len = 5,第二个for循环，其中一个元素与其它元素都要比较一次,减i是因为前一次比较中与下一次要比较的元素已经比较过一次了
	   //j < len - 1 1.不等于的原因,防止数组越界
	   for_1++;
	   flag = 1;
		for(j = 0; j < len - 1 - i ; ++j){
			for_2++;
			if (p_arr[j] > p_arr[j+1]){
				int tmp = p_arr[j+1];
				p_arr[j+1] = p_arr[j];/*大的放到后面*/
				p_arr[j] = tmp;/*小的放到前面*/
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
	//int arr[] = {2,3,4,5,7};时间复杂度最好
	int arr[] = {7,5,4,3,2};//时间复杂度最差的情况
	bubble_sort_2(arr,sizeof(arr)/sizeof(arr[0]));
	int i = 0;
	for(i; i < sizeof(arr)/sizeof(arr[0]); ++i){
		printf("%d  ",arr[i]);
	}
	printf("bubble\n");
	return 0;
}