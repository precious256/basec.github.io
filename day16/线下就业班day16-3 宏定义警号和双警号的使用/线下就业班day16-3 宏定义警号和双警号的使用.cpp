#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//ʹ�� # ����һ���������ɶ�Ӧ���ַ���
//ע�⣬ʹ��#ʱ�������˫����
#define print(n)  printf(""#n"is%d\n",n)
#define init(name)  struct name##_test{};
void test01()
{
	print(10 + 3);
}
//##���԰�λ�������ߵķ��źϳ�һ�����š� ������궨��ӷ�����ı�Ƭ�δ�����ʶ����

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
