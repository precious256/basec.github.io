#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
char* my_strncat(char* des, const char* src,size_t len)
{
	assert(des != NULL && src != NULL);
	char* pdes = des;
	const char* psrc = src;
	while (*pdes != NULL)
	{
		pdes++;
	}
	while (len--)
	{
		*pdes++ = *psrc++;
		
	}
	*pdes = '\0';
	return des;
}
void test01()
{
	char str1[25] = "hello";
	char str2[10] = "\tworld";
	char* des = my_strncat(str1, str2, sizeof(str2));
	printf("%s\n", des);

}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
