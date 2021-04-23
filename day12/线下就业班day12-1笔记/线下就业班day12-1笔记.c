/*************************************************
*1.结构体的4个特性
*2.位域与位段 位域：节省空间  1.不能跨字节存储 2.有类型限制，不能跨类型存储，存储的时候要注意保持数据完整性，若超出最大位，此时会出现内存丢失情况
* 
* 位段：位段的成员必须是 int ，unsigned int，char必须是整形
* 3.枚举 枚举类型为4个字节
*/
//#pragma pack (show)//查看编译器的对齐模数

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>
//#include <Windows.h>
//struct student 
//{
//	int a;
//	char c;
//	double b;
//};
//struct test
//{
//	short a;//0-3
//	struct
//	{
//		int b;//4-7
//		double c;//8-15
//		char d;//15-22
//	};
//	long e;//23-39
//};
////
//int main(void)
//{
//	printf("sizeof(student)=%d\n", sizeof(struct student));
//
//	printf("%d", sizeof(struct test));	
//	system("pause");
//	return EXIT_SUCCESS;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//using namespace std;
//struct student
//{
//	int age;
//	struct tt
//	{
//		int a;
//		int b;
//
//	};
//	char name;
//};
//int main()
//{
//	cout << sizeof(student) << endl;
//	system("pause");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>
//#include <Windows.h>
//struct student
//{
//	int a;
//	double d;
//	char c;
//};
//int main(void)
//{
//	int len = offsetof(struct student, d);
//	printf("%d\n", len);
//	system("pause");
//	return EXIT_SUCCESS;
//}
//enum a
//
//
//
//
//{
//	mon,year
//};
