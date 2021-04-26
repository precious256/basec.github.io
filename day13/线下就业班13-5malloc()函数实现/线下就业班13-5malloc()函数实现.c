#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
//函数原型 void*malloc(size_t);
//因为返回值未void*类型，所以在接受malloc()返回值时应该加上强转类型，在c语言中无所谓，但是还是应保持好一点的习惯
//malloc()开辟的空间不会对所开辟的空间的数据进行初始化，开辟出来的数据就是随机值
//malloc()必须与free()一起出现，不能不释放开辟出的空间，但是若程序结束，其开辟的空间也会随着程序结束一起释放了。
//free()过后的需不需要将原指针置空（指向NULL值）？
//需要：1.可以避免用户错误使用释放的空间 2.避免二次释放带来的错误，将同一空间释放两次，因为free(NULL)值是不会报错的
struct student
{
	int id;
	char name[15];
	int age;
	double score;
};
void test01()
{
	struct student* t1 = (struct student*)malloc(sizeof(struct student));
	//判断开辟成功的两种方法
	//1.采用if语句
	if (t1 == NULL)
	{
		perror(" ");//打印错误信息
		return;
	}
	//2.采用断言函数
	assert(t1 != NULL);
	t1->age = 18;
	t1->id = 18060102;
	strcpy(t1->name, "张三");
	t1->score = 90.0;
	printf("姓名%s\t学号%d\t年龄%d\t成绩%f\n", t1->name, t1->id, t1->age, t1->score);
	free(t1);
	t1 = NULL;
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
