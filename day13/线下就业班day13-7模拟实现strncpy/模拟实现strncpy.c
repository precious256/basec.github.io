#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
char* my_strncpy(char* des, const char* src, size_t len)
{
	assert(des != NULL && src != NULL);
	int i = 0;
	char* pdes = des;
	for (; i < len&&*src; i++)
	{
		*pdes++ = *src++;
	}
	*pdes = '\0';
	return des;
}
void test01()
{
	char des[6] = "hello";
	char src[10] = "worldaaa";//在满足拷贝字节数小于目标字符串大小时，此时会复制逐个字节盖，并且在结尾处+'\0'，
	 //当大于时，此时会复制完成，哪怕越界，但是造成的弊端是复制的字符串无法正常输出。
	//strncpy(des, src, 10);

	char* des1 = my_strncpy(des, src, 4);
	printf("%s\n", des1);

}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
