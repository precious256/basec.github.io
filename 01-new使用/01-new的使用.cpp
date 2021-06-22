#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
#if 0
void test()
{
	int* p = new int;
	*p = 100;
	cout << *p << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}

void test()
{
	int* p = new int[10];
	for (int i = 0; i < 10; i++)
	{
		p[i] = i * 10;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}

void test()
{
	int* p = new int;
	int* p1 = new int[10];
	delete p;
	delete[]p1;
}
int main()
{
	test();
	return 0;
}

void test()
{
	int* p =(int *) malloc(sizeof(int) * 10);
	int* p1 = (int*)calloc(10, sizeof(int));
	int* p2 = new int[10]{ 1 };
	free(p);
	free(p1);
	delete[]p2;

}
int main()
{
	test();
	return 0;
}

class date
{
public:
	date()
	{
		year = 1900;
		month = 0;
		day = 0;
		cout << "构造函数调用" << endl;
	}
	~date()
	{
		cout << "析构函数调用" << endl;
	}
private:
	int year;
	int month;
	int day;
};
void test01()
{
	date* m1 = (date*)malloc(sizeof(date) * 5);
	cout << "free调用" << endl;
	free(m1);
	
}
void test02()
{
date* m2 = new date[5];
cout << "delete调用" << endl;
delete[]m2;
}
int main()
{
	cout << "malloc开辟" << endl;
	test01();
	cout << "new 开辟" << endl;
	test02();
	return 0;
}
#endif
#if 0
class student
{
public:
	student()
	{
		cout << "构造调用" << endl;
		age = 20;
		char* name = new char[20];
	}
	~student()
	{
		if (name)
		{
			delete[]name;
		}
		cout << "析构调用" << endl;
	}
private:
	int age;
	char* name;
};
void test()
{
	student* m1 = (student*)malloc(sizeof(student));
	if (m1 == NULL)
	{
		cout << "内存开辟失败，退出" << endl;
		return;
	}
	delete m1;
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
class student
{
public:
	student()
	{
		cout << "构造调用" << endl;
		age = 20;
		char* name = new char[20];
	}
	~student()
	{
		if (name)
		{
			delete[]name;
		}
		cout << "析构调用" << endl;
	}
private:
	int age;
	char* name;
};
void test()
{
	student* m1 = new student;
	free(m1);
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
class student
{
public:
	student()
	{
		cout << "构造调用" << endl;
		age = 100;
		
	}
	/*~student()
	{
		
		cout << "析构调用" << endl;
	}*/
private:
	int age;
	
};
void test()
{
	//student* m1 = new student;
	//delete m1;
	student* m2 = new student[10];
	delete[]m2;
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
class student
{
public:
	student()
	{
		age = 12;
	}
	~student()
	{

	}
	void* operator new(size_t size)
	{
		return malloc(size);
	}
	void operator delete(void* p)
	{
		if (p)
		{
			free(p);
		}
	}
private:

	int age;
};
int main()
{
	student* m1 = new student;
	delete m1;
}

void* operator new(size_t size, char filename[], char funcName[], int lineNo)
{
	cout << filename << ":" << funcName << ":" << lineNo << ":" << lineNo << endl;
	return malloc(size);
}

int main()
{
	 int* p = new(__FILE__, __FUNCDNAME__, __LINE__) int;
	delete p;
	return 0;
}

int main()
{
	_CrtMemBlockHeader
}
#endif
void merge(int A[], int m, int B[], int n) 
{
	int i = m - 1;
	int  j = n - 1;
	int index = m + n - 1;
	while (j >= 0 )
	{
		if (i >= 0 && B[j] <= A[i])
		{
			A[index--] = A[i--];
		}
		else
		{
			A[index--] = B[j--];
		}
	}

	
}
int main()
{
	int a[6] = { 1,2,3 };
	int b[3] = { 2,5,6};
	merge(a, 3, b, 3);
	for (int i = 0; i < 6; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}