//两种方式 1.通过传参访问  2.通过传入指针访问
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class student
{
	//friend void student2::show(student& m1);
	friend class student2;
	friend class student3;
public:
	student()
	{
		cout << "student无参构造" << endl;
	}
	student(string Name, int Age)
	{
		age = Age;
		name = Name;
	}
public:
	int age;
private:
	string name;
};
class student2
{   //1.通过传入参数访问
public:
	
	void show(student& m1)
	{
		cout << "姓名:" << m1.age;
		cout << "成绩:" << m1.name << endl;
	}

};
class student3
{
public:
	student3()
	{
		m1 = new student;//调用student的默认构造函数
	}
	void func()
	{
		cout << "姓名:" << m1->name << endl;
		cout << "成绩:" << m1->age << endl;
	}
	//因为会用到new运算符，所以为了避免浅拷贝带来的问题，应对函数进行深拷贝
	student3(const student3& f1)
	{
		m1 = new student;//直接开辟，它会自动调用构造函数
		
	}
	~student3()
	{
		if (m1 != NULL)
		{
			delete m1;
			m1 = NULL;
			cout << "析构函数的调用" << endl;
		}
	}
private:
	student* m1;
};
void test01()
{
	student m1("小花", 90);
	student2 m2;
	m2.show(m1);
}
void test02()
{
	student m1("小明", 90);
	student3 m2;
	m2.func();
	student3 m3 = m2;
	m3.func();

}
int main()
{
	test01();
	system("pause");
	return 0;
}
