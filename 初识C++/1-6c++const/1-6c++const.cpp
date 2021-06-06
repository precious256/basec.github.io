#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
const int a = 10;
int main()
{

	volatile const int b = 20;
	int* p = (int*)&b;
	cout << "before change b=" << b << endl;
	*p = 200;
	cout << "after change b=" << b << endl;

	system("pause");
	return 0;
}
