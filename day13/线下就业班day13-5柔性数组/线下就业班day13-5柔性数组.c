#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//柔性数组特点：
//结构中的柔性数组成员前面必须至少一个其他成员。
//sizeof 返回的这种结构大小不包括柔性数组的内存。
//包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应
//柔性数组的预期大小。
//用途: 长度为0的数组的主要用途是为了满足需要变长度的结构体
//用法 : 在一个结构体的最后, 申明一个长度为0的数组, 就可以使得这个结构体是可变长的.对于编译器来说, 此时长度为0的数组并不占用空间, 因为数组名本身不占空间, 它只是一个偏移量, 数组名这个符号本身代表了一个不可修改的地址常量
struct student
{
	int age;
	char name[15];
	char str[0];//这个即为柔性数组 1.不占空间 2.必须置于所有变量之后，而且只能存在一个
};
void test01()
{
   const char* str = "hello world";
	int len = strlen(str);
	struct student* t1 = (struct student*)malloc((sizeof(struct student) + len + 1));//实质：仍需要在定义时开辟空间，
	//可以让其适应不同长度类型的大小的数组
	t1->age = 10;
	strcpy(t1->str, "张三");
	strcpy(t1->name, "李四");
}
int main(void)
{

	system("pause");
	return EXIT_SUCCESS;
}
