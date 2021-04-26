/*************************************
*1.动态开辟与静态开辟（栈区，堆区，静态常量区）
* 静态常量区：（static 定义的变量，字符串常量）
* 判断malloc()失败的两种方法：if语句，assert（）函数，
* malloc函数特性：
* 内存泄漏：程序不结束，之前所申请的空间无法释放（此时指针指向一个新开辟的空间）
* free()函数：
* calloc()函数与malloc()区别：
* 1.申请方式不同  2.malloc()开辟出来的数据为随机值，calloc为0值
* relloc()函数两种方式 1.增加空间  2.减少空间 
* 
* 1.去寻找大的空间（建立在当前空间之后内存满足的情况下，os决定）
* 2.对之前空间进行复制。同时释放之前的空间
* 注：用原有指针去接受realloc函数返回值
* 柔性数组****
*/
//所有动态开辟的数据都在堆区吗？
//所有开辟内存的函数都可以被释放吗？ _alloca

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<vld.h>//检测内存泄露
void test01()
{
	
	//int* p = (int*)malloc(sizeof(int) * 10);
	int* p = (int*)calloc(1, sizeof(int) * 10);
	for (size_t i = 0; i < 10; i++)
	{
		p[i] = i + 1;
	}
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d\t", p[i]);
	}
	printf("\n");
	free(p);
	
	
	p = NULL;//延时性,避免错误访问，避免恶意释放
	free(p);
	/*for (size_t i = 0; i < 10; i++)
	{
		printf("%d\t", p[i]);
	}*/
	printf("\n");
}
void test02()
{
	int* p = malloc(sizeof(int) * 10);
	for (size_t i = 0; i < 10; i++)
	{
		p[i] = i + 1;

	}
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d\t", p[i]);
	}
	printf("\n");
	p = (int*)realloc(p, sizeof(int)*5);//截断问题
	for (size_t i = 0; i < 4; i++)
	{
		printf("%d\t", p[i]);
	}
	free(p);
	p = NULL;
}
int main(void)
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
