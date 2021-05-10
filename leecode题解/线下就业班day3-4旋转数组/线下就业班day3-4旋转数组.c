//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
void reverse_arr(int* arr, int start, int end)
{
	if (arr == NULL)
	{
		return;
	}
	int temp;
	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
void test01()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("��������Ҫ��ת�ĸ���");
	int k;
	scanf("%d", &k);
	k %= len;//���������Ч��ת����
	printf("��תǰ\n");
	for (size_t i = 0; i < len; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	reverse_arr(arr, 0, len-k - 1);
	reverse_arr(arr, len-k, len - 1);
	reverse_arr(arr, 0, len - 1);
	printf("��ת��\n");
	for (size_t i = 0; i < len; i++)
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
