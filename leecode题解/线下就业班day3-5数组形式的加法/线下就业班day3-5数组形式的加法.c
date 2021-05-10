#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	if (A == NULL)
	{
		return;
	}
	int len = log10(K) + 1;//获取相加数字的有效位数
	int size = ASize > len ? ASize + 1 : len + 1;
	*returnSize = size;
	int* newspace1 = (int*)malloc(sizeof(int) * size);
	memset(newspace1, 0, sizeof(int) * size);
	if (newspace1 == NULL)
	{
		return;
	}
	while ((ASize>0||K!=0)&&size>0)
	{
		if(ASize>0)
		K += A[--ASize];
		newspace1[--size] = K % 10;
		K /= 10;
	}
	*returnSize -= size;
	return newspace1+size;

}
void test01()
{
	int arr[] = { 1,2,0,0 };
	printf("%d\n", arr[0]);
	int k = 34;
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	int p_size = 0;
	int* p = addToArrayForm(arr, arr_size, k, &p_size);
	printf("%d\n", p_size);
	for (size_t i = 0; i < p_size; i++)
	{
		printf("%d\t", p[i]);
	}

	
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
