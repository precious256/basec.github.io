#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<malloc.h>
//����ԭ�� void*calloc(size_t num,size_t ele_size);//numΪԪ�ظ�����ele_sizeΪԪ�ش�С
//��ʵ��ߵ�num.ele_size��ֵ������num*ele_size=����Ҫ�Ĵ�С  �������˵������������ģ�������������
void test01()
{
	int* p = (int*)calloc(1, 40);
	//��malloc��ͬ
	//ͬ�����ǿ��ٿռ�ĺ���������Ҫ�ֶ��ͷš�
	//��ͬ�������﷨��ͬ��calloc�����ڿ��ٳɹ���Ὣ���ٳ��������ݳ�ʼ������malloc����
	if (p == NULL)
	{
		return;
	}
	for (size_t i = 0; i < 10; i++)
	{
		p[i] = i * 10;
	}
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d\t", p[i]);
	}
	printf("\n");
	free(p);
	p = NULL;
}
int main(void)
{
	//test01();
	int* p = alloca(4);
	*p = 20;
	//free(p);
	system("pause");
	return EXIT_SUCCESS;
}
