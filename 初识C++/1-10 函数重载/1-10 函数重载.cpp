#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//����������ͬ
int add(int a, int b)
{
	return a + b;
}
int add(int a)
{
	return a;
}
//��������˳��ͬ
double add1(int a, double b)
{
	return a + b;
}
double add1(double a, int b)
{
	return a + b;
}
//�������Ͳ�ͬ
double add2(int a)
{
	return a;
}
double add2(double a)
{
	return a;
}
int main()
{
	/*add(1);
	add(1, 2);*/
	system("pause");
	return 0;
}
