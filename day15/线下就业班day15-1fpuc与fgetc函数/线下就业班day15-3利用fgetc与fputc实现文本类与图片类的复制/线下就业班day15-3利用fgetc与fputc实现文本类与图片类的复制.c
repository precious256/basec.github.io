#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
void test01()
{
	FILE* fp = fopen("fputc.txt", "wb");
	char buf[] = "hello world";
	int len = sizeof(buf);
	int i = 0;
	while (len)
	{
		fputc(buf[i++], fp);
		len--;
	}
	fclose(fp);
 fp = fopen("test.txt", "rb");//当以二进制文件进行读写时，其字符类的不变，数组或图片则会转化为相应的二进制进行存储
	if (fp == NULL)
	{
		perror("");
	}
	FILE* fp1 = fopen("copy_fputc.txt", "wb");
	if (fp1 == NULL)
	{
		perror("");
	}
	char ch;
	while ((ch = fgetc(fp)) != EOF)//当读取到-1时停止读取，所以应使用 fread()读取
	{
		fputc(ch, fp1);
	}
	fclose(fp);
	fclose(fp1);
}
void test02()
{
	FILE* fp = fopen("test.jpg", "rb");
	if (fp == NULL)
	{
		perror("");
	}
	FILE* fp1 = fopen("copy_kelisiding.jpg", "wb");//
	if (fp1 == NULL)
	{
		perror("");
	}
	
	char buffer[256] = { 0 };
	int count = fread(buffer, sizeof(char), 256, fp);

	while (count != 0)
	{
		fwrite(buffer, 1, count, fp1);
		count = fread(buffer, sizeof(char), 256, fp);
	}
	fclose(fp);
	fclose(fp1);
}
int main(void)
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
