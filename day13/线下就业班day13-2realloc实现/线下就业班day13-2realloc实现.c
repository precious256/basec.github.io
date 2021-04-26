#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
//realloc()函数原型 void*realloc(void*space,size_t size);//参 1：原空间  参2：新的需要申请的空间
//三步走： 1.申请size个空间2.对原空间的值进行拷贝，拷贝 size个大小，（确认拷贝正确性），3.free掉原空间 4.返回新开辟空间地址
//注意：realloc()函数既可以将原空间增大，也可以减小。
//realloc()开辟的两种情况：1.直接在其后面空间申请 2.若后面空间不大，则新开辟一个空间，同时释放原来占用的空间
//realloc()函数实现：因为无法实现在其内存后开辟的情况，故只提供一种方法
void* my_realloc(void* des, size_t size)
{
	void* new_space = malloc(size);//1.申请空间
	memcpy(new_space, des, size);//2.对原空间size大小个数据复制，此时size为新开辟的空间大小
	free(des);//3释放原空间
	des = NULL;
	return new_space;//返回新开辟的空间


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
