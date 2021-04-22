/*****************字符串与结构体****************************
*1.字符串查找strstr()函数(kmp)算法
*2.strtok()函数  字符串截断函数   2.从不是分割符的第一个字符开始进行判断 3.在分割内部会记录上一次所进行分割的位置，正则表达式实现匹配
*3.strerror()函数
*4.memcpy()函数
*5.memset函数
*6.memcmp函数
*7.memmove()函数//相对于memcpy函数，可以解决内存重叠情况
*/
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>
//#include <Windows.h>
//void test01()
//{
//	int arr[][2] = { 1,2,3,4,5,6 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", len);
//	for (size_t i = 0; i < len; i++)
//	{
//		for (size_t j= 0; j < 2; j++)
//		{
//			printf("%d\t", *(*(arr + i ) + j));//
//		}
//	}
//}
//int main(void)
//{
//	test01();
//	system("pause");
//	return EXIT_SUCCESS;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#pragma pack(1)
struct student
{
	char a;
	int c;
	double b;

};
int main(void)
{
	struct student t1;
	/*printf("%d\n", sizeof(t1));*/
	printf("%d\n", sizeof(struct student));
	system("pause");
	return EXIT_SUCCESS;
}
