#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//�����壺
//�ص㣺�������С��Զ�ǹ����������Ԫ�ص�ֵ
//      ��������һ��ʱ���ڽ���һ��Ԫ����Ч��һ��Ԫ��ʧЧ
//      ������Ҳ���뿼���ڴ���������
union a
{
	int a;
	char c;
};
//��������struct����
//���ϵ����г�Ա���õ����ڴ��е���ͬλ�á��������ڲ�ͬʱ�̰Ѳ�ͬ�Ķ����洢��ͬһλ��ʱ���Ϳ���ʹ�����ϡ�
//�ṹ��(struct)�����б����ǡ����桱�ġ����ŵ��ǡ������˴󡱣�ȫ�棻ȱ����struct�ڴ�ռ�ķ����Ǵַŵģ������ò��ã�ȫ���䡣
//��������(union)���Ǹ������ǡ����⡱�ġ���ȱ����ǲ��������ݡ������ŵ����ڴ�ʹ�ø�Ϊ��ϸ��Ҳ��ʡ���ڴ�ռ䡣
//�ṹ����һ��ʱ�̿��Ե������б������������岻���ԣ�ֻ����һ����Ч��һ��ʧЧ��
void test01()
{
	union a s1;
	s1.a = 10000;//0010 0111 0001 0000
	printf("%d\n", s1.c);//��ʱc��16   0001 0000
}
//���ù������жϴ�С��
void test02()
{
	union a s1;
	s1.a = 1;
	if (s1.a & 1 == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
}
//�����ڴ��еĴ洢��ʽ�жϴ�С��
void test03()
{
	int a = 0x01;
	if (a && 1)
	{
		printf("xiao\n");
	}
	else
	{
		printf("da\n");
	}
}
int main(void)
{
	//test01();
	//test02();
	//test03();
	typedef struct {
		int a;
		char b;
		short c;
		short d;
	}AA_t;
	printf("%d\n",sizeof(AA_t));
	system("pause");
	return EXIT_SUCCESS;
}

