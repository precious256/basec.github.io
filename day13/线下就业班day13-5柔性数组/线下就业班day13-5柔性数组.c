#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//���������ص㣺
//�ṹ�е����������Աǰ���������һ��������Ա��
//sizeof ���ص����ֽṹ��С����������������ڴ档
//�������������Ա�Ľṹ��malloc()���������ڴ�Ķ�̬���䣬���ҷ�����ڴ�Ӧ�ô��ڽṹ�Ĵ�С������Ӧ
//���������Ԥ�ڴ�С��
//��;: ����Ϊ0���������Ҫ��;��Ϊ��������Ҫ�䳤�ȵĽṹ��
//�÷� : ��һ���ṹ������, ����һ������Ϊ0������, �Ϳ���ʹ������ṹ���ǿɱ䳤��.���ڱ�������˵, ��ʱ����Ϊ0�����鲢��ռ�ÿռ�, ��Ϊ����������ռ�ռ�, ��ֻ��һ��ƫ����, ������������ű��������һ�������޸ĵĵ�ַ����
struct student
{
	int age;
	char name[15];
	char str[0];//�����Ϊ�������� 1.��ռ�ռ� 2.�����������б���֮�󣬶���ֻ�ܴ���һ��
};
void test01()
{
   const char* str = "hello world";
	int len = strlen(str);
	struct student* t1 = (struct student*)malloc((sizeof(struct student) + len + 1));//ʵ�ʣ�����Ҫ�ڶ���ʱ���ٿռ䣬
	//����������Ӧ��ͬ�������͵Ĵ�С������
	t1->age = 10;
	strcpy(t1->str, "����");
	strcpy(t1->name, "����");
}
int main(void)
{

	system("pause");
	return EXIT_SUCCESS;
}
