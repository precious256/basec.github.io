#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#define swap(n) ((((n)&0x55555555)<<1|((n)&0xaaaaaaaa)>>1))
void test01()
{
	int n = 25;
	printf("交换前%d\n", n);
   n=swap(n);
	printf("交换后%d\n", n);
	
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
