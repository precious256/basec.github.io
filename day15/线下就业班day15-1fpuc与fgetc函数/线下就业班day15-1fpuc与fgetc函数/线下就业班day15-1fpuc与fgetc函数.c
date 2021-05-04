#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//功能：写入一个字符到文件中
//#include <stdio.h>
//int fputc(int ch, FILE* stream);
//功能：将ch转换为unsigned char后写入stream指定的文件中
//参数：
//ch：需要写入文件的字符
//stream：文件指针
//返回值：
//成功：成功写入文件的字符
//失败：返回 - 1
void test01()
{
	FILE* fp = fopen("fputc.txt", "w");
	char buf[] = "hello world";
	int len = sizeof(buf);
	int i = 0;
	while (len)
	{
		fputc(buf[i++], fp);
		len--;
	}
	fclose(fp);
}
//#include <stdio.h>
//int fgetc(FILE* stream);
//功能：从stream指定的文件中读取一个字符
//参数：
//stream：文件指针
//返回值：
//成功：返回读取到的字符
//失败： - 1
void test02()
{
	FILE* fp = fopen("fputc.txt", "r");
	char buf[13];
	int i = 0;
	while ((buf[i++] = fgetc(fp)) != EOF);
	printf("%s\n", buf);
	fclose(fp);
}
int main(void)
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
