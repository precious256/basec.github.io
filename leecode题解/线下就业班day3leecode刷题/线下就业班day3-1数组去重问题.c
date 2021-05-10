#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
int my_unique(int arr[], int len)
{
	if (len < 2)
	{
		return len;
	}
	int index = 0;
	for (size_t i = 1; i < len; i++)
	{
		if (arr[index] == arr[i])
		{
			continue;
		}
		else
		{
			arr[++index] = arr[i];
		}
	}
	return index + 1;
}
void test01()
{
	int arr[] = { 0,0,1,1,2,2,2,3,3,4,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int size=my_unique(arr, len);
	printf("去重前\n");
	for (size_t i = 0; i < len; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("去重后\n");
	for (size_t i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}


}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
//leecode链接:https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/