#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int return_max(int a,int b)
{
	return a > b ? a : b;
}
void test01()
{
	int a = 10;
	int b = 20;
	int max1 = return_max(a, b);
	printf("×î´óÖµ%d\n", max1);
}
int main(void)
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}
