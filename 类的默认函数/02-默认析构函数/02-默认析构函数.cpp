#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class student
{
public:
	student()
	{
		strcpy(name, "����");
		age = 100;
		score = 90.0;
		cout << "student �������" << endl;
	}
	~student()
	{
		cout << "student ��������" << endl;
	}
private:
	char name[15];
	int age;
	double score;
};
class person
{
public:
	person()
	{
		cout << "person ����ĵ���" << endl;

		strcpy(id, "1900201");
	}
	~person()
	{
		cout << "person ���������ĵ���" << endl;
	}
private:
	char id[20];
	student m1;

};
void test()
{ 
	person p1;
}
int main()
{
	test();
	system("pause");
	return 0;
}
