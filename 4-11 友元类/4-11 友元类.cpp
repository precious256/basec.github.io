//���ַ�ʽ 1.ͨ�����η���  2.ͨ������ָ�����
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
		cout << "student�޲ι���" << endl;
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
{   //1.ͨ�������������
public:
	
	void show(student& m1)
	{
		cout << "����:" << m1.age;
		cout << "�ɼ�:" << m1.name << endl;
	}

};
class student3
{
public:
	student3()
	{
		m1 = new student;//����student��Ĭ�Ϲ��캯��
	}
	void func()
	{
		cout << "����:" << m1->name << endl;
		cout << "�ɼ�:" << m1->age << endl;
	}
	//��Ϊ���õ�new�����������Ϊ�˱���ǳ�������������⣬Ӧ�Ժ����������
	student3(const student3& f1)
	{
		m1 = new student;//ֱ�ӿ��٣������Զ����ù��캯��
		
	}
	~student3()
	{
		if (m1 != NULL)
		{
			delete m1;
			m1 = NULL;
			cout << "���������ĵ���" << endl;
		}
	}
private:
	student* m1;
};
void test01()
{
	student m1("С��", 90);
	student2 m2;
	m2.show(m1);
}
void test02()
{
	student m1("С��", 90);
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
