#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 != NULL && str2 != NULL);
//	const char* pstr1 = str1;
//	const char* pstr2 = str2;
//	while (*pstr1 != '\0' || *pstr2 != '\0')
//	{
//		if (*pstr1 - *pstr2 != 0)
//		{
//			break;
//		}
//		pstr1++;
//		pstr2++;
//		if (*pstr1 == '\0' && *pstr2 == '\0')
//		{
//			return 0;
//		}
//		if (*pstr1 != '\0' && *pstr2 == '\0')
//		{
//			return 1;
//		}
//		if (*pstr1 == '\0' && *pstr2 != '\0')
//		{
//			return -1;
//		}
//
//		
//	}
//	return *pstr1 - *pstr2;
//
//
//}
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL && str2 != NULL);
	const char* pstr1 = str1;
	const char* pstr2 = str2;
	int ret;
	while (!(ret=*pstr1 - *pstr2) && *pstr1)
	{
		pstr1++;
		pstr2++;
	}
	if (ret < 0)
	{
		return -1;
	}
	if (ret > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void test01()
{
	const char* str1 = "hello";
	const char* str2 = "helpo";
	int result = my_strcmp(str1, str2);
	if (result > 0)
	{
		printf("str1>str2\n");
	}
	else if(result<0)
	{
		printf("str1<str2\n");
	}
	else
	{
		printf("str1=str2\n");
	}
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
