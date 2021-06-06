#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
int& add(int a, int b)
{
	int result = a + b;
	return result;
}
void test()
{
	int a = 10;
	int b = 20;
	int &ret = add(a, b);
	cout << ret << endl;
	cout << ret << endl;
	cout << ret << endl;
}
//引用数组
void test02()
{
	int arr[5] = { 1,2,3,4,5 };
	//第一中方法
	typedef int(parr)[5];
	parr& a1 = arr;
	for (int i = 0; i < 5 ; i++)
	{
		cout << a1[i] << endl;
	}
	typedef int(&parr1)[5];
	parr1 a2 = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << a2[i] << endl;
	}
	int(&parr2)[5] = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << parr2[i] << endl;
	}

}
//引用指针
void test03()
{
	const char* p = "hello world";
	const char*& p1 = p;
	cout << p1 << endl;

}
int main()
{
	//test();
	//test02();
	test03();
	system("pause");
	return 0;
}
