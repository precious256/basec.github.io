#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
void test01()
{
	int arr[] = { 1,3,4,5,2,3,0,9,10 ,11, 7,20 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 1; i < len; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int j = i - 1;
			int temp = arr[i];
			while (j >= 0 && temp < arr[j])
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = temp;
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
