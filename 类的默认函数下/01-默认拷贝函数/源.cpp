#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
#if 0
class student
{
public:
	//���캯��
	student(const char* str, int _age, double _score)
	{
		int len = strlen(str);
		name = (char*)malloc(len + 1);
		if (name == nullptr)
		{
			cout << "�ڴ濪��ʧ�ܣ���ʼ������" << endl;
			return;
		}
		strcpy(name, str);
		age = _age;
		score = _score;
	}
	//��������
	~student()
	{
		if (name == nullptr)
		{
			return;
		}
		free(name);
		name = nullptr;

	}
	//��ӡ����
	void show()
	{
		cout << "����" << "  " << name << endl;
		cout << "����" << "  " << age << endl;
		cout << "�ɼ�" << "  " << score << endl;
	}
private:
	char* name;
	int age;
	double score;
};
void test01()
{
	student m1("����", 20, 98.5);
	//����Ĭ�Ͽ��������ַ�ʽ
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
		cout << "���캯���ĵ���" << this<<endl;
	}
	~person()
	{
		cout << "���������ĵ���" << this<<endl;
	}
	void show()
	{
		cout << "����  " << name << endl;
		cout << "����   " << age << endl;
	}
private:
	char name[15];
	int age;
};
void test()
{
	person m1("����", 20);
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
	//���캯��
	student(const char* str, int _age, double _score)
	{
		cout << "���캯��" << endl;
		int len = strlen(str);
		name = (char*)malloc(len + 1);
		if (name == nullptr)
		{
			cout << "�ڴ濪��ʧ�ܣ���ʼ������" << endl;
			return;
		}
		strcpy(name, str);
		age = _age;
		score = _score;
	}
	//�������캯��,��constԭ����Ϊ�˱����ڿ���ʱ�Ĵ����޸�
	student(const student& p1)
	{
		cout << "�������캯������" << endl;
		name = (char*)malloc(strlen(p1.name) + 1);
		if (name == NULL)
		{
			cout << "�ڴ濪��ʧ�ܣ������˳�" << endl;
			return;
		}
		strcpy(name, p1.name);
		age = p1.age;
		score = p1.score;
	}
	void operator = (const student& p1)
	{
		//���⸳ֵ��������غ��ԭ�ռ��ڴ�й¶
		if (this->name != NULL)
		{
			free(this->name);
		}
		cout << "��ֵ��������غ�������" << endl;
		name = (char*)malloc(strlen(p1.name) + 1);
		if (name == NULL)
		{
			cout << "�ڴ濪��ʧ�ܣ������˳�" << endl;
			return;
		}
		strcpy(name, p1.name);
		age = p1.age;
		score = p1.score;
	}
	//��������
	~student()
	{
		cout << "��������" << endl;
	
		if (name == nullptr)
		{
			return;
		}
		free(name);
		name = nullptr;

	}
	//��ӡ����
	void show()
	{
		cout << "��ӡ����" << endl;
	
		cout << "����" << "  " << name << endl;
		cout << "����" << "  " << age << endl;
		cout << "�ɼ�" << "  " << score << endl;
	}
private:
	char* name;
	int age;
	double score;
};
//�Զ������ͷ��صĻ�����ʱҲ������ÿ������캯��
student  mytest(const student& d)
{
	return d;
}
void test01()
{
	student m1("����", 20, 98.5);

	//student m2=mytest(m1);
	student m2("����",  21, 98.7);
	cout << "��ֵ�������ֵǰ" << endl;
	m1.show();
	m2.show();
	cout << "��ֵ��������غ�" << endl;
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
	//���캯��
	student(const char* str, int _age, double _score)
	{
		
		int len = strlen(str);
		name = (char*)malloc(len + 1);
		if (name == nullptr)
		{
			cout << "�ڴ濪��ʧ�ܣ���ʼ������" << endl;
			return;
		}
		strcpy(name, str);
		age = _age;
		score = _score;
	}


	//���ΪʲôҪ�������ã����������ڴ治�ᱻ�ͷţ����Դ�ʱ����������û����ģ��ڶ���ԭ������Ϊ�������ÿ���
	//��ʡһ��������һ���������ڴ濪������ʡ�ڴ棬Ҳ��ʡʱ�䡣
	student& operator = (const student& p1)
	{
		//���⸳ֵ��������غ��ԭ�ռ��ڴ�й¶
		if (this->name != NULL)
		{
			free(this->name);
		}
		cout << "��ֵ��������غ�������" << endl;
		name = (char*)malloc(strlen(p1.name) + 1);
		if (name == NULL)
		{
			cout << "�ڴ濪��ʧ�ܣ������˳�" << endl;
			return *this ;
		}
		strcpy(name, p1.name);
		age = p1.age;
		score = p1.score;
		return *this;//����return p1��ʱ�����ԣ���Ϊ����ִ�и�ֵ��������������ͬ�ġ�
	}
	//��������
	~student()
	{
		cout << "��������" << endl;

		if (name == nullptr)
		{
			return;
		}
		free(name);
		name = nullptr;

	}
	//��ӡ����
	void show()
	{
		
		cout << "����" << "  " << name << endl;
		cout << "����" << "  " << age << endl;
		cout << "�ɼ�" << "  " << score << endl;
	}
private:
	char* name;
	int age;
	double score;
};
void test01()
{
	student m1("����", 20, 98.5);

	//student m2=mytest(m1);
	student m2("����", 21, 98.7);
	student m3("����", 22, 99.9);
	cout << "��ֵ�������ֵǰ" << endl;
	m1.show();
	m2.show();
	m3.show();
	cout << "��ֵ��������غ�" << endl;
	m1 = m2 = m3;//�ײ��൱�ڵ��� m1.operator=(m2.operator(m3));��ʱ��û�з���ֵ�Ļ����൱�ڰ�void��ֵ��m1�����ǲ�����ġ�
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
	//ǰ��++����+1��Ȼ���ٸ�ֵ����Ϊ��ԭ�ж������+1֮���ٸ�ֵ�����Բ���Ҫ�����¶���
	date& operator ++()
	{
		this->day += 1;
		return *this;
	}
	//����++���Ȼ�ȡ������û��+1��ֵ�����ڲ��Ѿ�+1����ʱ��Ҫһ���м����ȥ��¼֮ǰ��ֵ
	date operator++(int)
	{
		date temp(*this);//����Ĭ�Ͽ������캯������Ϊ��ʱ���漰��Դ����
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
		day += 1;//�ڲ���const������£����ǿ��Զ�thisָ���µı��������޸�
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