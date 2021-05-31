#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
void test()
{
	int arr[] = { 1,2,3,1,2,3,4,1,2,3,4,8,5,6,7,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int Max, Min;
	Max = Min = 0;
	for (int i = 1; i < len; i++)
	{
		if (arr[Max] < arr[i])
		{
			Max = i;
		}
		if (arr[Min] > arr[i])
		{
			Min = i;
		}
	}
	int size = arr[Max] - arr[Min] + 1;
	int* auxiliary_arr = (int*)calloc(sizeof(int) ,size);
	if(auxiliary_arr==NULL)
	{
		return;
	}
	for (int i = 0; i < len; i++)
	{
		auxiliary_arr[arr[i]]++;
	}
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		int k = auxiliary_arr[i];
		while (k--)
		{
			arr[j++] = i;
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("%2d", arr[i]);
	}
}
int main(void)
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}
