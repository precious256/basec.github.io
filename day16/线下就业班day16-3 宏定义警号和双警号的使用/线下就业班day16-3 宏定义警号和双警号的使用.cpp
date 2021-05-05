#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//使用 # ，把一个宏参数变成对应的字符串
//注意，使用#时必须加上双引号
#define print(n)  printf(""#n"is%d\n",n)
#define init(name)  struct name##_test{};
void test01()
{
	print(10 + 3);
}
//##可以把位于它两边的符号合成一个符号。 它允许宏定义从分离的文本片段创建标识符。

void test02()
{
  init(my);
  my_test s1;
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
