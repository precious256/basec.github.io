#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
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
void adjust_down(int arr[], int n,int root)
{
	int child = root * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] < arr[child])
		{
			child += 1;
		}
		if (arr[child] < arr[root])
		{
			swap(&arr[child], &arr[root]);
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
void test01()
{
	int arr[] = { 1,3,4,5,2,3,0,9,10 ,11, 7,20 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int root = (len - 2) / 2; root >= 0; root--)
	{
		adjust_down(arr, len, root);
	}
	int end = len - 1;
	while (end)
	{
		swap(&arr[end], &arr[0]);
		adjust_down(arr, end, 0);
		end--;
	}
	print(arr, len);
}

int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
