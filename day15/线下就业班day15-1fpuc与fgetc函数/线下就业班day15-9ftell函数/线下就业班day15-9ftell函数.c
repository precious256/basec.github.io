#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
//long ftell(FILE* stream);
//功能：获取文件流（文件光标）的读写位置。
//参数：
//stream：已经打开的文件指针
//返回值：
//成功：当前文件流（文件光标）的读写位置
//失败:-1
/*4 rewind
	: 作用: 将光标移动到开头, 和fseek(fp, 0, SEEK_SET);

void rewind(FILE* stream);
功能：把文件流（文件光标）的读写位置移动到文件开头。
参数：
stream：已经打开的文件指针
返回值：
无返回值*/

void test01()
{
	FILE* fp = fopen("1.txt", "rb");
	if (fp == NULL)
	{
		perror("");
		return;
	}
	
	
	char ch = fgetc(fp);
	int pos=ftell(fp);
	printf("%d\n", pos);rewind(fp);
	pos = ftell(fp);
	printf("%d\n", pos);
	
	fclose(fp);

}

int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
