#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
#if 0
struct Student
{
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;
};
class person
{
public:
	void setperson(const char* name, int age)
	{
		strcpy(_name, name);
		_age = age;

	}
	void print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
private:
	char _name[15];
	int _age;
};
// void person::setperson(const char* name, int age)
//{
//	 strcpy(_name, name);
//	 _age = age;
//
//}
// void person::print()
// {
//	 cout << "name:" << _name << endl;
//	 cout << "age:" << _age << endl;
// }
 void test02()
 {
	 person p1;
	 p1.setperson("zhangsan ", 18);
	 p1.print();
 }
void test01()
{
	Student m1;
	m1.SetStudentInfo("张三", "男", 18);
	m1.PrintStudentInfo();
}
int main()
{
	test02();
	system("pause");
	return 0;
}

struct student
{
	void set(const char* name1, int age1);
	void print();
	int age;
	char name[15];
};
void student::set(const char* name1, int age1)
{
	strcpy(name, name1);
	age = age1;
}
void student::print()
{
	cout << "name" << name << endl;
	cout << "age" << age << endl;
}
void test01()
{
	student m1;
	m1.set("张三", 18);
	m1.print();
	cout << "姓名" << m1.name << endl;
	cout << "年龄" << m1.age << endl;
}
int main()
{
	test01();
	return 0;
}

class student
{
	void set(const char* name1, int age1);
	void print();
	char name[15];
	int age;
};
void student::set(const char* name1, int age1)
{
	strcpy(name, name1);
	age = age1;
}
void student::print()
{
	cout << "name" << name << endl;
	cout << "age" << age << endl;
}
void test01()
{
	student m1;
	m1.set("张三", 18);
	m1.print();
}
int main()
{
	test01();
	return 0;
}
struct Student
{
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;
};
struct person :Student//给一个默认的继承方式
{
	void set(int high1);
	void print();
	int high;
};
void person::set(int high1)
{
	high = high1;
}
void person::print()
{
	cout << "姓名" << _name << endl;
	cout << "性别" << _gender << endl;
	cout << "年龄" << _age << endl;
	cout << "身高" << high << endl;
}
void test01()
{
	
	person m2;
	m2.SetStudentInfo("张三", "男", 20);
	m2.set(180);
	m2.print();
}
int main()
{
	test01();
	return 0;
}

class student
{
	void set(const char* name1, int age1);
	void print();
	char name[15];
	int age;
};
void student::set(const char* name1, int age1)
{
	strcpy(name, name1);
	age = age1;
}
void student::print()
{
	cout << "name" << name << endl;
	cout << "age" << age << endl;
}
class person :student
{
	void set1(int high1);
	int high;
};
void student::set1(int high1)
{
	high = high1;
}
void test01()
{
	person m1;
	m1.set("张三", "男", 20);
	m1.set1(180);
	m1.print();
}
int main()
{
	test01();
	return 0;
}
class person
{
	void set()
	{

	}
	void print()
	{

	}
	int num1;
	int num2;
	int num3;
};
void test01()
{
	cout << sizeof(person) << endl; //输出结果为12
}
int main()
{
	test01();
	return 0;
}

class person
{
	void print()
	{

	}
};
void test()
{
	cout << sizeof(person) << endl;//输出结果为1
}
int main()
{
	test();
	return 0;
}

#pragma pack(3)
class person
{
	int age;
	int num1;
	int p;
	static int p1;
};
void test01()
{
	cout << sizeof(person) << endl;//结果为12
}
int main()
{
	test01();
	return 0;

}
# endif
class student
{
public:
	void set(const char* name1, int age1);
	void print();
	char name[15];
	int age;
};
void student::set(const char* name1, int age1)
{
	strcpy(name, name1);
	age = age1;
}
void student::print()
{
	cout << "name" << name << endl;
	cout << "age" << age << endl;
}
void test01()
{
	student m1;
	m1.set("张三", 18);
	m1.print();
}
int main()
{
	test01();
	return 0;
}