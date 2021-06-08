//需求，获取打印机的打印次数
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class print
{
private:
	//1.将无参构造函数与拷贝构造函数私有化
	print()
	{
		mount = 0;
	}
	print(const print& m1)
	{

	}
public:
	//使用静态成员函数返回指针
	static print* get()
	{
		return p;
	}
	 void dayin(string name)
	{
		cout << name << "打印" << endl;
		mount++;
	}
	int return_num()
	{
		return mount;
	}
private:
	static print* p;//2声明一个静态成员指针
	int mount;
};
print* print::p = new print;//3声明一个静态成员指针
void test()
{
	print *m1 = print::get();
	m1->dayin("生产部");
	print* m2 = print::get();
	m2->dayin("研发部");
	print* m3 = print::get();
	m3->dayin("市场部");
	cout << "打印次数" << m3->return_num() << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}
