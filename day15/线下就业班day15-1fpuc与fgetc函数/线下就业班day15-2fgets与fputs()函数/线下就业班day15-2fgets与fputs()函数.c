#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
//int fputs(const char* str, FILE* stream);
//功能：将str所指定的字符串写入到stream指定的文件中，字符串结束符 '\0'  不写入文件。
//参数：
//str：字符串
//stream：文件指针
//返回值：
//成功：0
//
//失败： - 1
void test01()
{
	char buf[15] = "hello world\n";
	char buf1[12] = "hello";
	FILE* fp = fopen("fputs.txt", "w");
	if (fp == NULL)
	{
		perror(" ");
	}
	fputs(buf, fp);
	fputs(buf1, fp);
	fclose(fp);
}
//fgets  从文件读取字符串
//注意 : fgets读取遇到\n结束
//#include <stdio.h>
//char* fgets(char* str, int size, FILE * stream);
//功能：从stream指定的文件内读入字符，保存到str所指定的内存空间，直到出现换行字符、读到文件结尾或是已读了size - 1个字符为止，最后会自动加上字符 '\0' 作为字符串结束。
//参数：
//str：字符串
//size：指定最大读取字符串的长度（size - 1）
//stream：文件指针
//返回值：
//成功：成功读取的字符串
//读到文件尾或出错： NULL
void test02()
{
	FILE* fp = fopen("fputs.txt", "r");
	if (fp==NULL)
	{
		perror(" ");
	}
	char buf[128];
	fgets(buf, 128, fp);//此时在fputs文件中有hello world\n hello 两个字符串，但由于读取到了\n字符，所以停止读取
	printf("buf=%s\n", buf);
	fclose(fp);
}
int main(void)
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
