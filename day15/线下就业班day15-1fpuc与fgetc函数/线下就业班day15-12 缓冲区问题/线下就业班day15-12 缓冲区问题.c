#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//缓冲区本质：内存中的一块临时空间
// 为什么要引入缓冲区?
//1. 这样就可以减少磁盘的读写次数，再加上计算机对缓冲区的操作大大快于对磁盘的操作，故应用缓冲区可大大提高计算机的运行速度。
//2. 它使得低速的输入输出设备和高速的CPU能够协调工作，避免低速的输入输出设备占用CPU，解放出CPU，使其能够高效率工作。
//刷新缓冲区的三种情况
//1.使用fflush函数强制刷新
// 头文件 #include<stdio.h>
// 原型int fflush(FILE *fp);
// 返回值：成功为0，失败为EOF
//2.程序结束
//3.缓冲区满的情况
int main(void)
{

	system("pause");
	return EXIT_SUCCESS;
}
