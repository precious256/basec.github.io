#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//����λ���ԭ����Щ��Ϣ�ڴ洢ʱ��������Ҫռ��һ���������ֽڣ� ��ֻ��ռ������һ��������λ��
//�����ڴ��һ��������ʱ��ֻ��0��1 ����״̬�� ��һλ����λ���ɡ�Ϊ�˽�ʡ�洢�ռ䣬��ʹ������
//��C�������ṩ��һ�����ݽṹ����Ϊ��λ�򡱻�λ�Ρ�����ν��λ���ǰ�һ���ֽ��еĶ���λ����Ϊ������ͬ������
//��˵��ÿ�������λ����ÿ������һ�������������ڳ����а��������в����� �����Ϳ��԰Ѽ�����ͬ�Ķ�����һ���ֽڵĶ�����λ������ʾ��
struct student
{
	char a : 2;
	char b : 4;
};
//1.һ��λ�����洢��ͬһ���ֽ��У����ܿ������ֽ�
struct t
{
	int a : 5;
	int b : 5;
};
//2.λ�����û�����ƣ�ʾ���ⲿ�ֿռ䲻��ʹ��
struct t1
{
	int a : 30;
	int : 2;
	int b : 2;
};
//3.λ��ĳ��Ȳ����Դ�����������һ���ֽڵĳ��� eg:int a:33;//err
//4.����λ�򲻿��Կ����ʹ洢�����ͱ���һ��
struct t2
{
	/*int a : 2;
	char b : 2;
	int c : 20;*///��������ͬ���͵�λ�����ʱ����ʱϵͳĬ�ϸ�λ���ѽ�������ʱsizeof��ֵΪ12
	int a : 2;
	int c : 20;
	char b : 2;
	
};
void test01()
{
	printf("%d\n", sizeof(struct student));
	printf("%d\n", sizeof(struct t));
	printf("%d\n", sizeof(struct t1));
	printf("%d\n", sizeof(struct t2));
}

int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
