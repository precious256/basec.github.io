#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
void merge(int *arr1,int maxsize, int len1, int *arr2, int len2)
{
	if (arr1 == NULL || arr2 == NULL)
	{
		return;
	}
	int m = len1 - 1;//标记数组一中最大元素下标
	int n = len2 - 1;//标记数组二中最大元素下标
	maxsize = maxsize - 1;//从数组最大元素可以插入
	printf("%d\n", maxsize);
	printf("%d\n", m);
	printf("%d\n", n);
	while (n>=0)
	{
		if (m>=0&&(arr1[m] > arr2[n]))
		{
			arr1[maxsize--] = arr1[m--];
		}
		else
		{
			arr1[maxsize--] = arr2[n--];
		}
	}

}
void test01()
{
	int arr1[7] = { 1,3,5 };
	int arr2[4] = { 2,4,6,8 };
	merge(arr1, 7, 3, arr2, 4);
	printf("after the merge\n");
	for (size_t i = 0; i < 7; i++)
	{
		printf("%d\t", arr1[i]);
	}
	printf("\n");

}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
