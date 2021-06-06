#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
namespace A
{
	int a = 10;
	int b = 20;
	namespace B
	{
		int c = 30;
	}

}
namespace A
{
	int d = 40;
}
void test03()
{
	namespace D = A;
	cout << "»»±ðÃû" << endl;
	cout << D::B::c << endl;
	cout << D::a << endl;
	cout << D::b << endl;
	cout << D::d << endl;
}
void test01()
{
	cout << A::B::c << endl;
	cout << A::a << endl;
	cout << A::b << endl;
	cout << A::d << endl;
}
namespace 
{
	int a = 20;
}
void test02()
{
	cout << a << endl;
}
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}
