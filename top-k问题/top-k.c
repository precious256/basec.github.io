//˼�룺���ö����򣬴���������ȡ��k��Ԫ�أ�Ȼ���ȡԪ���滻�ķ�ʽ���������k��ֵ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
int mp(int a, int b)
{
	return a > b;
}

void adjust(int arr[], int size, int root,int(*mp)(int ,int))
{
	int child = root * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && mp(arr[child] , arr[child + 1]))
		{
			child += 1;
		}
		if (arr[root] > arr[child])
		{
			swap(&arr[child], &arr[root]);
		}
		else
		{
			return;
		}
	}
}
void test01()
{
	int arr[] = { 12,1,2,3,11,4,5,6,7,8,9,10,11 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int arr1[5] = {0};//�洢�����������Ԫ��
	memcpy(arr1, arr, sizeof(int) * 5);//���������5��Ԫ��
	
	int size = len - 5;
	int i = 5;
	while (size--&&i<len)
	{  
		int root = (5 - 2) / 2;
		
		for (; root >= 0; root--)
		{
			adjust(arr1, 5, root, mp);
		}
		while (arr1[0] > arr[i])
		{
			i++;
		}
		swap(&arr1[0], &arr[i]);
		i++;
	}
	for (int root = (5 - 2) / 2; root >= 0; root--)
	{
		adjust(arr1, 5, root, mp);
	}
	int end = 5 - 1;
	while (end)
	{
		swap(&arr1[end], &arr1[0]);
		adjust(arr1, end, 0,mp);
		end--;
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr1[i]);
	}
	

}

int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}


