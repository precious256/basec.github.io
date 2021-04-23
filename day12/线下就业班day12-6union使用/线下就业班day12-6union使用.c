#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//共用体：
//特点：共用体大小永远是共用体中最大元素的值
//      共用体在一段时间内仅有一个元素有效，一个元素失效
//      共用体也必须考虑内存对齐的问题
union a
{
	int a;
	char c;
};
//共用体与struct区别：
//联合的所有成员引用的是内存中的相同位置。当你想在不同时刻把不同的东西存储于同一位置时，就可以使用联合。
//结构体(struct)中所有变量是“共存”的——优点是“有容乃大”，全面；缺点是struct内存空间的分配是粗放的，不管用不用，全分配。
//而联合体(union)中是各变量是“互斥”的——缺点就是不够“包容”；但优点是内存使用更为精细灵活，也节省了内存空间。
//结构体在一个时刻可以调用所有变量，而共用体不可以，只可以一个有效，一个失效。
void test01()
{
	union a s1;
	s1.a = 10000;//0010 0111 0001 0000
	printf("%d\n", s1.c);//此时c是16   0001 0000
}
//利用共用体判断大小端
void test02()
{
	union a s1;
	s1.a = 1;
	if (s1.a & 1 == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
}
//利用内存中的存储方式判断大小端
void test03()
{
	int a = 0x01;
	if (a && 1)
	{
		printf("xiao\n");
	}
	else
	{
		printf("da\n");
	}
}
int main(void)
{
	//test01();
	//test02();
	//test03();
	typedef struct {
		int a;
		char b;
		short c;
		short d;
	}AA_t;
	printf("%d\n",sizeof(AA_t));
	system("pause");
	return EXIT_SUCCESS;
}

