#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<malloc.h>
//函数原型 void*calloc(size_t num,size_t ele_size);//num为元素个数，ele_size为元素大小
//其实这边的num.ele_size的值在满足num*ele_size=你需要的大小  其组合来说，可以是任意的，但必须是整数
void test01()
{
	int* p = (int*)calloc(1, 40);
	//与malloc异同
	//同：都是开辟空间的函数，都需要手动释放。
	//不同：开辟语法不同，calloc函数在开辟成功后会将开辟出来的数据初始化，而malloc不会
	if (p == NULL)
	{
		return;
	}
	for (size_t i = 0; i < 10; i++)
	{
		p[i] = i * 10;
	}
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d\t", p[i]);
	}
	printf("\n");
	free(p);
	p = NULL;
}
int main(void)
{
	//test01();
	int* p = alloca(4);
	*p = 20;
	//free(p);
	system("pause");
	return EXIT_SUCCESS;
}
