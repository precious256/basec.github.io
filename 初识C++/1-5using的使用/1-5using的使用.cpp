#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
namespace A
{
	int a = 20;
	int b = 30;
	int c = 50;
}
void test()
{
	using namespace A;//目的：使命名空间A中的元素在此函数内变为全局变量.注意：是此函数
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
int main()
{
	test();
	//cout << a << endl;//error
	system("pause");
	return 0;
}
