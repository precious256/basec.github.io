#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
char* my_strcpy(char* des, const char* src)
{
	assert(des != NULL && src != NULL);
	char* pdes = des;
	const char* psrc = src;
	while (*psrc != '\0')
	{
		*pdes = *psrc;
		pdes++;
		psrc++;
	}
	*pdes = '\0';
	return des;
}
void test01()
{
	char buf[25] = "hello";
	char buf1[12] = "hello world";
	char* des = my_strcpy(buf, buf1);
	printf("%s\n", des);
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
