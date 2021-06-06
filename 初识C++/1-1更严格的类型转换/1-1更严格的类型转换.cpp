#define _CRT_SECURE_NO_WARNINGS
#include<iostream>//C++中的标准输入输出 类似于c语言的#include<stdio.h>
#include<string>
#include<cstdlib>
using namespace std;//用到std库 中的cin--scanf     cout ---printf   所以加这个声明
int main()
{
	char* name = (char*)malloc(15);
	memcpy(name, "hello C++", 15);
	cout << name << endl;
	system("pause");
	return 0;
}
