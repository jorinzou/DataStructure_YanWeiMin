#include <stdio.h>

/*二分法查找，递归版本*/
int binary_search(int arr[],int min_index,int max_index,int data)
{
	if(min_index <= max_index){
		int mid = (max_index + min_index)/2;
		
		if (data == arr[mid]){
			return mid;
		}
		else if (data < arr[mid]){
			return binary_search(arr,min_index,mid-1,data);
		}
	    else{
			return binary_search(arr,mid+1,max_index,data);
		}
	}
	return -1;
}

int main(void)
{
	int arr[] = {0,1};
	
	int index = binary_search(arr,0,sizeof(arr)/sizeof(arr[0])-1,1);
	if (index < 0){
		printf("%d\n",index);
	}else{
		printf("%d\n",arr[index]);
	}
	return 0;
}