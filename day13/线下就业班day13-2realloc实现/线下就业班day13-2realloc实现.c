#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
//realloc()����ԭ�� void*realloc(void*space,size_t size);//�� 1��ԭ�ռ�  ��2���µ���Ҫ����Ŀռ�
//�����ߣ� 1.����size���ռ�2.��ԭ�ռ��ֵ���п��������� size����С����ȷ�Ͽ�����ȷ�ԣ���3.free��ԭ�ռ� 4.�����¿��ٿռ��ַ
//ע�⣺realloc()�����ȿ��Խ�ԭ�ռ�����Ҳ���Լ�С��
//realloc()���ٵ����������1.ֱ���������ռ����� 2.������ռ䲻�����¿���һ���ռ䣬ͬʱ�ͷ�ԭ��ռ�õĿռ�
//realloc()����ʵ�֣���Ϊ�޷�ʵ�������ڴ�󿪱ٵ��������ֻ�ṩһ�ַ���
void* my_realloc(void* des, size_t size)
{
	void* new_space = malloc(size);//1.����ռ�
	memcpy(new_space, des, size);//2.��ԭ�ռ�size��С�����ݸ��ƣ���ʱsizeΪ�¿��ٵĿռ��С
	free(des);//3�ͷ�ԭ�ռ�
	des = NULL;
	return new_space;//�����¿��ٵĿռ�


}
void test01()
{
	int* arr = (int*)malloc(sizeof(int) * 5);
	if (arr == NULL)
	{
		return;
	}
	for (size_t i = 0; i < 5; i++)
	{
		arr[i] = i + 1;
	}
	for (size_t i = 0; i < 5; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	arr =(int *) realloc(arr, sizeof(int) * 10);
	for (size_t i = 5; i < 10; i++)
	{
		arr[i] = i + 1;
	}
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	free(arr);
	arr = NULL;
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
