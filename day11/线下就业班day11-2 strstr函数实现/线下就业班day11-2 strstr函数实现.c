#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 != NULL && str2 != NULL);
//	int len = strlen(str1);
//	char* des = str1;
//	char* source = str2;
//	while (*source != '\0')
//	{
//		if (strncmp(des, source, len)==0)
//		{
//			return source;
//		}
//		else
//		{
//			source += 1;
//		}
//	}
//	return NULL;
//}
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL && str2 != NULL);
	const char* pstr1 = str1;
	const char* pstr2 = str2;
	int i, j;
	i = 0;
	j = 0;
	while (pstr1[i] != '\0' && pstr2[j] != '\0')
	{
		if (pstr1[i] == pstr2[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1; //关键
			j = 0;
		}
	}
	if (pstr1[j] == '\0')
		return pstr1 + i - j;
	return NULL;


}
void test01()
{
	char* str = "hello world";
	char* str1 = "hllo";
	char* des = my_strstr(str1, str);
	if (des == NULL)
	{
		printf("未找到\n");
	}
	else
	printf("str比对结果是%s\n", des);

}

int main(void)
{
	test01();
	
	system("pause");
	return EXIT_SUCCESS;
}
