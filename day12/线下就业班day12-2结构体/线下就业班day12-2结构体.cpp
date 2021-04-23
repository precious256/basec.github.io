#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//结构体：用户将不同数据类型的数据放在一块
//内存对齐的意义：以空间换时间，避免内存的二次读取，尽可能减少cpu访存
//1.第一个属性开始，从0计算偏移量
//第二个属性要放在min（该属性的大小,对齐模数）的整数倍上
//2.当所有属性计算完成后，整体做二次偏移
// 将所有的属性计算完成后，取min（该结构体中的最大数据字节，对齐模数）的整数倍
//3.变量的起始内存必须是它的整数倍，比如char a；占一个字节，但是后跟int类型数据，所以此时只能从4的整数倍开始，造成了本占一个字节的数据占了4字节
//4.所占的字节数并非一成不变的，可以通过修改默认情况下的对齐模数，达到修改所占内存大小的目的。
struct student
{
	char c;//0-3  4个字节
	int age;//变量的起始内存必须是它的整数倍 4-7
	double score;//8-15
};
//未命名结构体使用,在创建时设立变量，后续不可设立
//struct
//{
//	int a;
//	char c;
//}s1;
//结构体中嵌套结构体
//将未命名的结构体嵌套在其中，c语言与c++运行结果一致，当加上名字后，此时c++中嵌套的结构体不占空间
struct teacher
{
	char c;//4
	struct tt
	{
		int a;//4
		char d;//4
	};
	int age;//4
};
int main(void)
{
	printf("%d\n", sizeof(struct student));
	//printf("%d\n", sizeof(s1));
	printf("%d\n", sizeof(struct teacher));
	system("pause");
	return EXIT_SUCCESS;
}
