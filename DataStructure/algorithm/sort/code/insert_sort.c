#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
��������
�㷨������
ȡ���±�Ϊn��Ԫ�أ�n-1��֮�Ƚϣ����n-1����n-1����n
����ѭ��
*/
void insert_sort(int *p_arr,int len)
{
	int i = 0,j = 0;
	//1.ʹ�����ѭ������ȡ��ÿ��Ԫ��,�ӵڶ���Ԫ����
	for(i = 1; i < len; i++)
	{
		//��ÿ��ȡ����Ԫ�ص�����������
		int temp = p_arr[i];
		//2.ʹ���ڲ�ѭ����ȡ����Ԫ������ߵ�����Ԫ�����ν��бȽ�
		for(j = i;  j >= 1  && p_arr[j-1] > temp ; j--)
		{
			if(i == 4){
				printf("test\n");
			}
			p_arr[j] = p_arr[j-1];
		}
		//3.ֱ�����Ԫ��С�ڵ���ȡ����Ԫ��ʱ����ȡ����Ԫ�ز��뵽���Ԫ�ص��ұ�
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
