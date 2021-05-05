#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#define my_offsetof(name1,element)  (((int)(&name1.element))-(int )(&name1))
struct student
{
	char name[10];
	int age;
	double score;
};
void test01()
{
	struct student t1;
	int off = my_offsetof(t1, score);
	printf("%d\n", off);
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
