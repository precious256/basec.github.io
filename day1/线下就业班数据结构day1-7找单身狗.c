#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

void findTwoNum(int arr[], int n, int* pnum1, int* pnum2)
{
	int i;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		sum ^= arr[i];
	}
	int pos=0;
	for (i = 0; i < 32; i++)
	{
		if (sum &1<< i)
		{
			pos = i;
			break;
		}
	}
	//���ҵ��з����һλ������һλ�ϣ�������һ����һ��1һ��0
	//*pnum1 = *pnum2 = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] & 1 << pos)
		{
			*pnum1 ^= arr[i]; //��һλ��1�ģ�������1��
		}
		else
		{
			*pnum2 ^= arr[i]; //��һλ��0�ģ�������2��
		}
	}
}
void test01()
{
	int arr[] = { 1,2,1,3,4,2,3,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int num1, num2=0;
	num1 = 0;
	findTwoNum(arr, len, &num1, &num2);
	printf("sum=%d sum=%d\n", num1,num2);
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
