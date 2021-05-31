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
//合并
void merge(int arr[], int temp[], int left, int mid, int right)
{
	//标记左半区的
	int l_pos = left;
	//标记右边的
	int r_pos = mid;
	//记录temp数组下标
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
//划分
void msort(int arr[], int temp[], int left, int right)
{
	if (right - left <= 1)
	{
		return;
	}
	if (left < right)
	{
		//找中间点
		int mid = (left + right) / 2;
		//递归划分左边的
		msort(arr, temp, left, mid);
		//递归划分右边的
		msort(arr, temp, mid , right);
		//对划分的区间进行合并
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
