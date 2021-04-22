#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
char* my_strcat(char* dest, const char* src)
{
	assert(dest != NULL && src != NULL);
	char* pdest = dest;
	
	while (*pdest != '\0')
	{
		pdest++;
	}
	while (*src != '\0')
	{
		*pdest++ = *src++;
	}
	*pdest = '\0';
	return dest;

}
void test01()
{
	char buf[25] = "hello";
	char buf1[10] = " world";
	char* des = my_strcat(buf, buf1);
	printf("%s\n", des);

}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
