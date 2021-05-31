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
	while (l_pos < mid)
	{
		temp[pos++] = arr[l_pos++];
	}
	while (left < right)
	{
		arr[left] = temp[left];
		left++;
	}
}
void merge_sortno(int arr[], int temp[], int len)
{
	int gap = 1;
	while (gap < len)
	{
		for (int i = 0; i <len; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid > len)
			{
				mid = len;
			}
			if (right > len)
			{
				right = len;
			}
			merge(arr, temp, left, mid, right);

		}
		gap = gap * 2;
	}
}
void test01()
{
	int arr[] = { 1,3,4,5,2,3,0,9,10 ,11, 7,20 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* temp = (int*)malloc(sizeof(int) * len);
	merge_sortno(arr, temp, len);
	free(temp);
	print(arr, len);
	
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
