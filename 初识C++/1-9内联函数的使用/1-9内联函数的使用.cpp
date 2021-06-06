#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

inline int add(int a, int b)
{
	return a + b;
}
int main()
{
	int ret = add(10, 20);
	cout << ret << endl;
	system("pause");
	return 0;
}

