#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
int fib_version1(int n)
{
	if (n < 3&&n>1)//0 1 1 2 3
	{
		return 1;
	}
	if (n == 1)
	{
		return 0;
	}
	return fib_version1(n - 1) + fib_version1(n - 2);
}
void test01()
{
	printf("%d\n",fib_version1(6));
}
int fib_version2(int n)
{
	if (n < 3 && n>1)
	{
		return 1;
	}
	
	int first, second, end;
	first = 1;
	second = 1;
	for (size_t i = 2; i < n; i++)
	{
		end = first + second;
		first = second;
		second = end;
	}
	return end;
}
void test02()
{
	printf("%d\n", fib_version2(5));//0 1 1 2 3 5 
}
//Î²µÝ¹é
int fib_version3(int first,int second,int n)
{
	if (n < 3)
	{
		return 1;
	}
	if (n == 3)
	{
		return first + second;
	}
	return fib_version3(second, first + second, n - 1);
}
void test03()
{
	printf("%d\n", fib_version3(1,1,45));//0 1 1 2 3 5 
}
int main(void)
{
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
