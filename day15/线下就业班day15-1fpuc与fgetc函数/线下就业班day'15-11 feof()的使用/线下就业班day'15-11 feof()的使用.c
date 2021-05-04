#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//feof()可以用来替代EOF吗？
//不可以，因为fgetc()函数有两种情况返回值为-1，1、读到文件尾 2、读取错误（读取到了-1字符）
//注：故feof()函数严格情况下只可以作为判断文件是否正常读取与否的条件
int main(void)
{
	int c;
	FILE* fp = fopen("Test.c", "r");
	if (!fp)
	{
		perror("File opening failed");
		return -1;
	}

	while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
	{
		putchar(c);
	}
	//判断是什么原因结束的
	if (ferror(fp))
		puts("I/O error when reading");
	else if (feof(fp))
		puts("End of file reached successfully");
	fclose(fp);
	system("pause");
	return EXIT_SUCCESS;
}
