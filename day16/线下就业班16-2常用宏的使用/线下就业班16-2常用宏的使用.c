#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#define log(msg) Log(__FILE__,__LINE__,__DATE__,__TIME__,msg)
//__FILE__返回当前操作的文件
//__LINE__返回出错的第几行
//__DATE__返回出错的日期
//__TIME__返回出错的时间
void Log(const char* file, int line, const char* data, const char* time, const char* msg)
{
	printf("%s : %d : %s [%s-%s]\n", file, line, msg, data, time);
}
void test01()
{
	FILE* fp = fopen("may.txt", "r");
	if (fp == NULL)
	{
		log("打开文件失败");
	}
	else
	{
		log("打开文件成功");
	}
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
