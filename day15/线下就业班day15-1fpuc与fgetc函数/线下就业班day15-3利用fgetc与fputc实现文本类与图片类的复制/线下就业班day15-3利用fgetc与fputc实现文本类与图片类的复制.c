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
 fp = fopen("test.txt", "rb");//���Զ������ļ����ж�дʱ�����ַ���Ĳ��䣬�����ͼƬ���ת��Ϊ��Ӧ�Ķ����ƽ��д洢
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
	while ((ch = fgetc(fp)) != EOF)//����ȡ��-1ʱֹͣ��ȡ������Ӧʹ�� fread()��ȡ
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
