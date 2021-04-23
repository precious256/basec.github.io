#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//引入位域的原因：有些信息在存储时，并不需要占用一个完整的字节， 而只需占几个或一个二进制位。
//例如在存放一个开关量时，只有0和1 两种状态， 用一位二进位即可。为了节省存储空间，并使处理简便
//，C语言又提供了一种数据结构，称为“位域”或“位段”。所谓“位域”是把一个字节中的二进位划分为几个不同的区域，
//并说明每个区域的位数。每个域有一个域名，允许在程序中按域名进行操作。 这样就可以把几个不同的对象用一个字节的二进制位域来表示。
struct student
{
	char a : 2;
	char b : 4;
};
//1.一个位域必须存储在同一个字节中，不能跨两个字节
struct t
{
	int a : 5;
	int b : 5;
};
//2.位域可以没有名称，示意这部分空间不可使用
struct t1
{
	int a : 30;
	int : 2;
	int b : 2;
};
//3.位域的长度不可以大于数据类型一个字节的长度 eg:int a:33;//err
//4.所有位域不可以跨类型存储，类型必须一致
struct t2
{
	/*int a : 2;
	char b : 2;
	int c : 20;*///当看到不同类型的位域出现时，此时系统默认该位域已结束，此时sizeof求值为12
	int a : 2;
	int c : 20;
	char b : 2;
	
};
void test01()
{
	printf("%d\n", sizeof(struct student));
	printf("%d\n", sizeof(struct t));
	printf("%d\n", sizeof(struct t1));
	printf("%d\n", sizeof(struct t2));
}

int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
