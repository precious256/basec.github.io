#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
//int fprintf(FILE* stream, const char* format, ...);
//功能：根据参数format字符串来转换并格式化数据，然后将结果输出到stream指定的文件中，指定出现字符串结束符 '\0'  为止。
//参数：
//stream：已经打开的文件
//format：字符串格式，用法和printf()一样
//返回值：
//成功：实际写入文件的字符个数
//失败： - 1
void test01()
{
	//与printf()函数区别：printf()是将结果输入到终端，但fpritnf()是将结果输入进文件中
	//stdin键盘输入 \stdout终端 \  stderr保存的是错误信息
	fprintf(stdout, "%s", "hello world");//相当于printf,因为stdout对应的就是黑窗口
	int year, month, day;
	fscanf(stdin, "%d %d %d", &year, &month, &day);//stdin此时相当于scanf("%d %d %d",&year,&month,&day);
	printf("%d年%d月%d日\n", year, month, day);
	
}
void test02()
{
	FILE* fp = fopen("fprintf.txt", "wb");
	if (fp == NULL)
	{
		perror("");
	}
	int len=fprintf(fp, "%d年%d月\0%d日", 2020, 10, 15);//当出现\0停止写入，此时文件中有的是2020年10月，字为10位
	printf("%d\n", len);
	fclose(fp);
	
}
//fscanf()拆包函数
//#include <stdio.h>
//int fscanf(FILE * stream, const char* format, ...);
//功能：从stream指定的文件读取字符串，并根据参数format字符串来转换并格式化数据。
//参数：
//stream：已经打开的文件
//format：字符串格式，用法和scanf()一样
//返回值：
//成功：参数数目，成功转换的值的个数
//失败： - 1
void test03()
{
	FILE* fp = fopen("fprintf.txt", "rb");
	if (fp == NULL)
	{
		perror("");
		return;
	}
	int year, month;
	fscanf(fp, "%d年%d月", &year, &month);//使用fscanf()注意：1.要保证需要读取数据格式的正确，
	//2.在文件中是什么样子，你读取相应数据时除了数据外也必须呈现相应的格式，要不会造成后续数据的错误读取。

	printf("%d\t%d\n", year, month);
}
int main(void)
{
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
