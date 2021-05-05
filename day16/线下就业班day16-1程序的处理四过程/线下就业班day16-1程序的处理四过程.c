//touch指令
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//gcc编译4步骤：【重点】
//1. 预处理 - E	xxx.i	预处理文件
//gcc - E xxx.c - o xxx.i
//1) 头文件展开。-- - 不检查语法错误。 可以展开任意文件。
//2）宏定义替换。-- - 将宏名替换为宏值。
//3）替换注释。-- - 变成空行
//4）展开条件编译-- - 根据条件来展开指令。
//2. 编译 - S	xxx.s	汇编文件
//gcc - S hello.i - o hello.s
//1）逐行检查语法错误。【重点】-- - 整个编译4步骤中最耗时的过程。
//2）将C程序翻译成 汇编指令，得到.s 汇编文件。
//3. 汇编 - c	xxx.o	目标文件
//gcc - c hello.s - o hello.o
//1）翻译：将汇编指令翻译成对应的 二进制编码。
//4. 链接		无	xxx.exe	可执行文件。
//gcc  hello.o - o hello.exe
//1）数据段合并
//2）数据地址回填
//3）库引入
//vs 下为 IDE(集成开发环境)

void test01()
{
	FILE* fp = fopen("a.txt", "r");
	if (fp == NULL)
	{
		perror("");
	}
	fclose(fp);
}
int main(void)
{
	//printf("%d\n", ___STDC___);
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
