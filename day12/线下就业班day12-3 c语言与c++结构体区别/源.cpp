#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


//c++�нṹ�����ǿ��԰�����Ա������
struct student
{

	int age;
	char name[20];

	void show();//�����ڽṹ�������������ⶨ�壬Ҳ����ֱ�ӷ��ڽṹ���ڲ�
};
//c++�нṹ���ǿ��Ա��̳еģ�Ĭ�������Ϊ���м̳�
struct teacher :student
{
	double score;
};
void student::show()//��һ��������thisָ�룬ָ��ò��ֿռ�
{
	/*printf("����%s\t", name);
	printf("����%d\n", age);*/
	printf("����%s\t", this->name);
	printf("����%d\n", this->age);
}
void test01()
{
	cout << sizeof(student) << endl;//���ۣ��ڴ�������Ԫ��ʱ����ʱ������ռ�κοռ䣬��һ���ṹ����ֻ��һ������ʱ����ʱ��ռ1�ֽ�
	student t1 = { 10,"����" };//�ṹ���������ʱ���Բ���struct�ؼ���
	t1.show();
}
void test02()
{
	cout << sizeof(teacher) << endl;//��ʱֵΪ32=24+8.�����ڽ�stdentԪ��Ҳ�����ȥ
	teacher t;//t�������Ե��ü̳����Ľṹ�������������������ĳ�Ա����
	t.age = 10;
	strcpy(t.name, "����");
	t.score = 90.0;
	t.show();
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
