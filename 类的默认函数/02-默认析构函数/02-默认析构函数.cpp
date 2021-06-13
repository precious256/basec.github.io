#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class student
{
public:
	student()
	{
		strcpy(name, "张三");
		age = 100;
		score = 90.0;
		cout << "student 构造调用" << endl;
	}
	~student()
	{
		cout << "student 析构调用" << endl;
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
		cout << "person 构造的调用" << endl;

		strcpy(id, "1900201");
	}
	~person()
	{
		cout << "person 类型析构的调用" << endl;
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
