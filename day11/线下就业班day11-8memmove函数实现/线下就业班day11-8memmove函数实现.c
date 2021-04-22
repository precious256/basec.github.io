#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
//memcpy()与memmove函数区别
//函数原型;void* memcpy(void* destin, void* source, unsigned n);
//函数原型：void* memmove(void* destin, void* source, unsigned n);
//相对于memmove函数，在不发生内存重叠的情况下，此时memcpy()函数的效率高于memmove函数
//在发生内存重叠的情况下，此时memmove()可以确保复制的准确性
void* my_memmove(void* destin, void* source, int n)
{
	n = (int)n;
	assert(destin != NULL && source != NULL);
	char* pdes = (char*)destin;
	const char* psrc = (const char*)source;
	//没有发生内存重叠的现象
	if (pdes > psrc || pdes > psrc + n)
	{
		while (n-- != 0)
		{
			*pdes++ = *psrc++;
		}
	}
	//当发生内存重叠的情况时，让目标空间由后向前进行拷贝，避免了内存覆盖的情况
	else
	{
		pdes += n - 1;
		psrc += n - 1;
		while (n-- != 0)
		{
			*pdes = *psrc;
		}

	}
	return destin;
}
void test01()
{
	char buf[12] = "hello";
	char buf1[10] = "world";

	printf("复制前%s\n", buf);
	my_memmove(buf, buf1, 3);

	printf("复制后%s\n", buf);
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
