#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
enum a {
	mon,
	tus,
	wed,
	thur,
	fri,
	satur,
	sun,
    
};
void test01()
{
	printf("%d\n", sizeof(enum a));//1.ö���������ж��ٸ�Ԫ�أ����С��Ϊ4�����߲��ı䡣
	//ö���ڱ���׶ν������滻�ɶ�Ӧ��ֵ�����ǿ��Խ�ö�����Ϊ����׶εĺꡣ
	//2.ö��Ĭ�������Ԫ�ش�0��ʼ�����ε�����
	enum a t1=0;
	for (size_t i = 0; i < 7; i++)
	{
		printf("%d\t", t1++);
		
	}
}
//enum ����switch���ʹ��
void test02()
{
	enum a t1 = mon;
	
	while(1)
	{int n=scanf("%d", &t1);
	if (n == 0)
	{
		printf("�������Ͳ����ϣ�����ѭ��\n");
		return;
	}
		switch (t1)
		{
		case 0: {printf("1\n"); break; }
		case 1: {printf("2\n"); break; }
		case 2: {printf("3\n"); break; }
		case 3: {printf("4\n"); break; }
		case 4: {printf("5\n"); break; }
		case 5: {printf("6\n"); break; }
		case 6: {printf("7\n"); break; }
		default: {printf("error number\n"); continue; }
		}
		
	}

}
int main(void)
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
