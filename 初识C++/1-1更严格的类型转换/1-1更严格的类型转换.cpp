#define _CRT_SECURE_NO_WARNINGS
#include<iostream>//C++�еı�׼������� ������c���Ե�#include<stdio.h>
#include<string>
#include<cstdlib>
using namespace std;//�õ�std�� �е�cin--scanf     cout ---printf   ���Լ��������
int main()
{
	char* name = (char*)malloc(15);
	memcpy(name, "hello C++", 15);
	cout << name << endl;
	system("pause");
	return 0;
}
