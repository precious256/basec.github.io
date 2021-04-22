#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
int my_strlen(const char* des)
{
	assert(des != NULL);
	const char* pdes = des;
	int len = 0;
	while (*pdes++ != '\0')
	{
		len++;
	}
	return len;
}
int digit_mystrlen( char* des)
{
	assert(des != NULL);
	if (*des == '\0')
	{
		return 0;
	}
	return 1 + digit_mystrlen(des + 1);
}
void test01()
{
	char* des = "hello world";
	//int len = my_strlen(des);
	int len = digit_mystrlen(des);//递归
	printf("%s\t的有效位数为%d\n", des, len);
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
