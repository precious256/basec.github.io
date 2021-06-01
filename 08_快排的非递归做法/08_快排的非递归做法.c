#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include"stack.h"
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void print(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%3d", arr[i]);
	}
	printf("\n");
}
int getMId(int arr[], int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (arr[left] < arr[right - 1])
	{
		if (arr[mid] < arr[left])
			return left;
		else
		{
			if (arr[mid] > arr[right - 1])
				return right - 1;
			else
				return mid;
		}
	}
	else
	{
		if (arr[mid] > arr[left])
			return left;
		else
		{
			if (arr[mid] < arr[right - 1])
				return right - 1;
			else
				return mid;
		}
	}
}
int wakeng(int arr[], int left, int right)
{
	int begin = left;
	int end = right - 1;
	//记录一下该基准值
	int mid = getMId(arr, left, right);
	swap(&arr[mid], &arr[right - 1]);
	int key = arr[right - 1];

	while (begin < end)
	{
		while (begin < end && arr[begin] >= key)
			begin++;
		if (begin < end)
		{
			arr[end] = arr[begin];
			end--;
		}
		while (begin < end && arr[end] <= key)
			end--;
		if (begin < end)
		{
			arr[begin] = arr[end];
			begin++;
		}
	}
	//填最后一个坑
	arr[begin] = key;
	return begin;
}
int part2(int arr[], int left, int right)
{
	int cur = left;
	int prev = cur - 1;
	int mid = getMId(arr, left, right);
	swap(&arr[mid], &arr[right - 1]);
	int key = arr[right - 1];
	while (cur < right)
	{
		if (arr[cur] > key && ++prev != cur)
		{
			swap(&arr[cur], &arr[prev]);
		}
		cur++;
	}
	if (++prev != right - 1)
	{
		swap(&arr[prev], &arr[right - 1]);
	}
	return prev;
}
int part(int arr[], int left, int right)
{
	//将数组的最后一个元素作为它的基准值
	int mid = getMId(arr, left, right);
	swap(&arr[mid], &arr[right - 1]);
	int key = arr[right - 1];
	int begin = left;
	int end = right - 1;
	while (begin < end)
	{
		while (begin < end && arr[begin] >= key)
			begin++;
		while (begin < end && arr[end] <= key)
			end--;
		if (begin < end)
		{
			swap(&arr[begin], &arr[end]);
		}
	}
	//交换基准值
	if (begin != right - 1)
	{
		swap(&arr[begin], &arr[right - 1]);
	}
	return begin;
}
void Quicksort(int arr[], int n)
{
	Stack s;
	init1(&s);
	int left = 0;
	int right = n;
	pushStack(&s, right);
	pushStack(&s, left);
	while (!is_empty(&s))
	{
		left = return_top(&s);
		popStack(&s);
		right = return_top(&s);
		popStack(&s);
		if (right - left >= 1)
		{
			int div = wakeng(arr, left, right);
			
			pushStack(&s, right);
			pushStack(&s, div + 1);
			pushStack(&s, div);
			pushStack(&s, left);
		}
	}
	destory1(&s);

}
void test01()
{
	int arr[] = { 1,3,4,5,2,3,0,9,20 ,11, 7,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Quicksort(arr, len);
	print(arr, len);
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
