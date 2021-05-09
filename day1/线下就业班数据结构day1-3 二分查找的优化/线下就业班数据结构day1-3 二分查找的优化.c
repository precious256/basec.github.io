#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
int my_halfsearch(int arr[], int len, int target)
{
	if (arr == NULL)
	{
		return;
	}
	int left = 0;
	int right = len - 1;
	int mid = 0;
	if (target > arr[right] || target < arr[left])
	{
		return -1;
	}
	while (left <= right)
	{
		mid = left + ((right - left) >> 1);//���ַ�����Ϊ�˱���left+right������
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else if (arr[mid] > target)
		{
			right = mid - 1;
		}
	}
	return -1;
}
void test01()
{
	int arr[] = { 1,2,3,4,5,6,7,8,10,20,40,60,100 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("����������Ҫ��ѯ������\n");
	int target;
	scanf("%d", &target);
	int i=my_halfsearch(arr, len, target);
	if (i == -1)
	{
		printf("δ�ҵ�\n");
	}
	else
	{
		printf("�±�Ϊ%d\n", i);
	}
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
