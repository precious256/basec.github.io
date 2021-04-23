#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


//c++中结构体内是可以包含成员函数的
struct student
{

	int age;
	char name[20];

	void show();//可以在结构体内声明，类外定义，也可以直接放在结构体内部
};
//c++中结构体是可以被继承的，默认情况下为公有继承
struct teacher :student
{
	double score;
};
void student::show()//有一个隐含的this指针，指向该部分空间
{
	/*printf("姓名%s\t", name);
	printf("年龄%d\n", age);*/
	printf("姓名%s\t", this->name);
	printf("年龄%d\n", this->age);
}
void test01()
{
	cout << sizeof(student) << endl;//结论：在存在其他元素时，此时函数不占任何空间，但一个结构体中只有一个函数时，此时会占1字节
	student t1 = { 10,"张三" };//结构体变量定义时可以不加struct关键字
	t1.show();
}
void test02()
{
	cout << sizeof(teacher) << endl;//此时值为32=24+8.类似于将stdent元素也计算进去
	teacher t;//t变量可以调用继承来的结构体的任意变量，包括它的成员函数
	t.age = 10;
	strcpy(t.name, "张三");
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
