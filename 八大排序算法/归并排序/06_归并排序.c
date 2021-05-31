#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
void print(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%3d", arr[i]);
	}
	printf("\n");
}
//�ϲ�
void merge(int arr[], int temp[], int left, int mid, int right)
{
	//����������
	int l_pos = left;
	//����ұߵ�
	int r_pos = mid;
	//��¼temp�����±�
	int pos = left;
	while (l_pos < mid && r_pos < right)
	{
		if (arr[l_pos] > arr[r_pos])
		{
			temp[pos++] = arr[l_pos++];
		}
		else
		{
			temp[pos++] = arr[r_pos++];
		}
	}
	while (r_pos < right)
	{
		temp[pos++] = arr[r_pos++];
	}
	while (l_pos < mid )
	{
		temp[pos++] = arr[l_pos++];
	}
	while (left < right)
	{
		arr[left] = temp[left];
		left++;
	}
}
//����
void msort(int arr[], int temp[], int left, int right)
{
	if (right - left <= 1)
	{
		return;
	}
	if (left < right)
	{
		//���м��
		int mid = (left + right) / 2;
		//�ݹ黮����ߵ�
		msort(arr, temp, left, mid);
		//�ݹ黮���ұߵ�
		msort(arr, temp, mid , right);
		//�Ի��ֵ�������кϲ�
		merge(arr, temp, left, mid, right);
	}
}
void mergesort(int arr[],int  len,int temp[])
{
		msort(arr, temp, 0, len );	
}
void test01()
{
	int arr[] = { 1,3,4,5,2,3,0,9,10 ,11, 7,20 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* temp = (int*)malloc(sizeof(int) * len);
	mergesort(arr, len,temp);
	/*print(temp, 13);*/
	free(temp);
	print(arr, len);
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
