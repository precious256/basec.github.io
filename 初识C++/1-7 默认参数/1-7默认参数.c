#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#define a 20
#define Fun(i) fun(i,a)

int fun(int x,int y)
{
	return x+y;
}
int main(void)
{
	printf("10+20=%d\n", Fun(10));
	system("pause");
	return EXIT_SUCCESS;
}
