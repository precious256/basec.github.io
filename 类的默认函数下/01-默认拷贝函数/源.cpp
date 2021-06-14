#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
#if 0
class student
{
public:
	//构造函数
	student(const char* str, int _age, double _score)
	{
		int len = strlen(str);
		name = (char*)malloc(len + 1);
		if (name == nullptr)
		{
			cout << "内存开辟失败，初始化错误" << endl;
			return;
		}
		strcpy(name, str);
		age = _age;
		score = _score;
	}
	//析构函数
	~student()
	{
		if (name == nullptr)
		{
			return;
		}
		free(name);
		name = nullptr;

	}
	//打印函数
	void show()
	{
		cout << "姓名" << "  " << name << endl;
		cout << "年龄" << "  " << age << endl;
		cout << "成绩" << "  " << score << endl;
	}
private:
	char* name;
	int age;
	double score;
};
void test01()
{
	student m1("张三", 20, 98.5);
	//调用默认拷贝的两种方式
	student m2(m1);
	student m2 = m1;
}
int main()
{
	system("pause");
	return 0;
}

class person
{
public:
	person(const char* _name, int _age)
	{
		strcpy(name, _name);
		age = _age;
		cout << "构造函数的调用" << this<<endl;
	}
	~person()
	{
		cout << "析构函数的调用" << this<<endl;
	}
	void show()
	{
		cout << "姓名  " << name << endl;
		cout << "年龄   " << age << endl;
	}
private:
	char name[15];
	int age;
};
void test()
{
	person m1("张三", 20);
	person m2(m1);
	//person m2=m1;
	m1.show();
	m2.show();
}
int main()
{
	test();
	return 0;
}

class student
{
public:
	//构造函数
	student(const char* str, int _age, double _score)
	{
		cout << "构造函数" << endl;
		int len = strlen(str);
		name = (char*)malloc(len + 1);
		if (name == nullptr)
		{
			cout << "内存开辟失败，初始化错误" << endl;
			return;
		}
		strcpy(name, str);
		age = _age;
		score = _score;
	}
	//拷贝构造函数,加const原因是为了避免在拷贝时的错误修改
	student(const student& p1)
	{
		cout << "拷贝构造函数调用" << endl;
		name = (char*)malloc(strlen(p1.name) + 1);
		if (name == NULL)
		{
			cout << "内存开辟失败，拷贝退出" << endl;
			return;
		}
		strcpy(name, p1.name);
		age = p1.age;
		score = p1.score;
	}
	void operator = (const student& p1)
	{
		//避免赋值运算符重载后对原空间内存泄露
		if (this->name != NULL)
		{
			free(this->name);
		}
		cout << "赋值运算符重载函数调用" << endl;
		name = (char*)malloc(strlen(p1.name) + 1);
		if (name == NULL)
		{
			cout << "内存开辟失败，拷贝退出" << endl;
			return;
		}
		strcpy(name, p1.name);
		age = p1.age;
		score = p1.score;
	}
	//析构函数
	~student()
	{
		cout << "析构函数" << endl;
	
		if (name == nullptr)
		{
			return;
		}
		free(name);
		name = nullptr;

	}
	//打印函数
	void show()
	{
		cout << "打印函数" << endl;
	
		cout << "姓名" << "  " << name << endl;
		cout << "年龄" << "  " << age << endl;
		cout << "成绩" << "  " << score << endl;
	}
private:
	char* name;
	int age;
	double score;
};
//以对象类型返回的话，此时也必须调用拷贝构造函数
student  mytest(const student& d)
{
	return d;
}
void test01()
{
	student m1("张三", 20, 98.5);

	//student m2=mytest(m1);
	student m2("李四",  21, 98.7);
	cout << "赋值运算符赋值前" << endl;
	m1.show();
	m2.show();
	cout << "赋值运算符重载后" << endl;
	m2=m1;
	m1.show();
	m2.show();
	

}
int main()
{
	test01();
	system("pause");
	return 0;
}

class date
{
public:
	date(int _year = 1900, int _month = 1, int _day = 1)
	{
		year = _year;
		month = _month;
		day = _day;
	}

	~date()
	{

	}

	int year;
	int month;
	int day;
};
int  operator-(const date& p1, const date& p2)
{
	return p1.day - p2.day;
}
void test()
{
	date m1(2021, 6, 13);
	date m2(2021, 6, 21);
	int result=m2 - m1;
	cout << result << endl;
}
int main()
{
	test();
	return 0;
}

class student
{
public:
	//构造函数
	student(const char* str, int _age, double _score)
	{
		
		int len = strlen(str);
		name = (char*)malloc(len + 1);
		if (name == nullptr)
		{
			cout << "内存开辟失败，初始化错误" << endl;
			return;
		}
		strcpy(name, str);
		age = _age;
		score = _score;
	}


	//这块为什么要返回引用：首先它的内存不会被释放，所以此时返回引用是没问题的，第二个原因是因为返回引用可以
	//节省一次它拷贝一次所带来内存开销，节省内存，也节省时间。
	student& operator = (const student& p1)
	{
		//避免赋值运算符重载后对原空间内存泄露
		if (this->name != NULL)
		{
			free(this->name);
		}
		cout << "赋值运算符重载函数调用" << endl;
		name = (char*)malloc(strlen(p1.name) + 1);
		if (name == NULL)
		{
			cout << "内存开辟失败，拷贝退出" << endl;
			return *this ;
		}
		strcpy(name, p1.name);
		age = p1.age;
		score = p1.score;
		return *this;//或者return p1此时都可以，因为这两执行赋值操作后内容是相同的。
	}
	//析构函数
	~student()
	{
		cout << "析构函数" << endl;

		if (name == nullptr)
		{
			return;
		}
		free(name);
		name = nullptr;

	}
	//打印函数
	void show()
	{
		
		cout << "姓名" << "  " << name << endl;
		cout << "年龄" << "  " << age << endl;
		cout << "成绩" << "  " << score << endl;
	}
private:
	char* name;
	int age;
	double score;
};
void test01()
{
	student m1("张三", 20, 98.5);

	//student m2=mytest(m1);
	student m2("李四", 21, 98.7);
	student m3("王五", 22, 99.9);
	cout << "赋值运算符赋值前" << endl;
	m1.show();
	m2.show();
	m3.show();
	cout << "赋值运算符重载后" << endl;
	m1 = m2 = m3;//底层相当于调用 m1.operator=(m2.operator(m3));此时若没有返回值的话，相当于把void的值给m1，这是不允许的。
	m1.show();
	m2.show();
	m3.show();


}
int main()
{
	test01();
	return 0;
}

class date
{
public:
	date(int _year = 1900, int _month = 1, int _day = 1)
	{
		year = _year;
		month = _month;
		day = _day;
	}

	~date()
	{

	}
	//前置++，先+1，然后再赋值，因为对原有对象进行+1之后再赋值，所以不需要创建新对象
	date& operator ++()
	{
		this->day += 1;
		return *this;
	}
	//后置++，先获取到的是没有+1的值，其内部已经+1，这时需要一个中间变量去记录之前的值
	date operator++(int)
	{
		date temp(*this);//调用默认拷贝构造函数，因为此时不涉及资源管理
		day += 1;
		return temp;
	}
private:

	int year;
	int month;
	int day;
};

void test()
{
	date m1(2021, 6, 13);
	date m2(2021, 6, 21);
	m1 = ++m1;
	m2 = m2++;


}
int main()
{
	test();
	return 0;
}
#endif
class date
{
public:
     date(int _year , int _month , int _day )
	{
		year = _year;
		month = _month;
		day = _day;
	}

	~date()
	{

	}
	date *operator&()
	{
		day += 1;//在不加const的情况下，我们可以对this指针下的变量进行修改
		cout << this << endl;
		return this;
	}
	
private:

	int year;
	int month;
	int day;
};

void test()
{
	//date m1(2021, 6, 13);
	//const date m2(2021, 6, 21);
	



}
int main()
{
	test();
	return 0;
}