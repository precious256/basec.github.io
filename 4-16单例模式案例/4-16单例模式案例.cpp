//���󣬻�ȡ��ӡ���Ĵ�ӡ����
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class print
{
private:
	//1.���޲ι��캯���뿽�����캯��˽�л�
	print()
	{
		mount = 0;
	}
	print(const print& m1)
	{

	}
public:
	//ʹ�þ�̬��Ա��������ָ��
	static print* get()
	{
		return p;
	}
	 void dayin(string name)
	{
		cout << name << "��ӡ" << endl;
		mount++;
	}
	int return_num()
	{
		return mount;
	}
private:
	static print* p;//2����һ����̬��Աָ��
	int mount;
};
print* print::p = new print;//3����һ����̬��Աָ��
void test()
{
	print *m1 = print::get();
	m1->dayin("������");
	print* m2 = print::get();
	m2->dayin("�з���");
	print* m3 = print::get();
	m3->dayin("�г���");
	cout << "��ӡ����" << m3->return_num() << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}
