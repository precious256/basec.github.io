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
	using namespace A;//Ŀ�ģ�ʹ�����ռ�A�е�Ԫ���ڴ˺����ڱ�Ϊȫ�ֱ���.ע�⣺�Ǵ˺���
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
