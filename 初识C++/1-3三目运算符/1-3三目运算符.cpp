#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
void test()
{
	int a = 10;
	int b = 20;
	(a > b ? a : b) = 300;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}
