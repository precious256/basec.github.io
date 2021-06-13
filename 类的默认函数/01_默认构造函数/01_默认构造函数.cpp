#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class student
{
public:
	student()
	{
		cout << "student 调用" << endl;
		strcpy(name, "李四");
		age = 20;
		score = 91.4;
	}
	student(const char* _name, int _age, double _score)
	{
		strcpy(name, _name);
		age = _age;
		score = _score;
	}
	void print()
	{
		cout << "name" << name << endl;
		cout << "年龄" << age << endl;
		cout << "成绩" << score << endl;
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
		cout << "person类的调用" << endl;
	}
private:
	char id[20];
	student m1;

};
int main()
{
	//student m1("张三", 18, 90.0);
	person m2;
	system("pause");
	return 0;
}
