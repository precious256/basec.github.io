/*************************************
*1.��̬�����뾲̬���٣�ջ������������̬��������
* ��̬����������static ����ı������ַ���������
* �ж�malloc()ʧ�ܵ����ַ�����if��䣬assert����������
* malloc�������ԣ�
* �ڴ�й©�����򲻽�����֮ǰ������Ŀռ��޷��ͷţ���ʱָ��ָ��һ���¿��ٵĿռ䣩
* free()������
* calloc()������malloc()����
* 1.���뷽ʽ��ͬ  2.malloc()���ٳ���������Ϊ���ֵ��callocΪ0ֵ
* relloc()�������ַ�ʽ 1.���ӿռ�  2.���ٿռ� 
* 
* 1.ȥѰ�Ҵ�Ŀռ䣨�����ڵ�ǰ�ռ�֮���ڴ����������£�os������
* 2.��֮ǰ�ռ���и��ơ�ͬʱ�ͷ�֮ǰ�Ŀռ�
* ע����ԭ��ָ��ȥ����realloc��������ֵ
* ��������****
*/
//���ж�̬���ٵ����ݶ��ڶ�����
//���п����ڴ�ĺ��������Ա��ͷ��� _alloca

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<vld.h>//����ڴ�й¶
void test01()
{
	
	//int* p = (int*)malloc(sizeof(int) * 10);
	int* p = (int*)calloc(1, sizeof(int) * 10);
	for (size_t i = 0; i < 10; i++)
	{
		p[i] = i + 1;
	}
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d\t", p[i]);
	}
	printf("\n");
	free(p);
	
	
	p = NULL;//��ʱ��,���������ʣ���������ͷ�
	free(p);
	/*for (size_t i = 0; i < 10; i++)
	{
		printf("%d\t", p[i]);
	}*/
	printf("\n");
}
void test02()
{
	int* p = malloc(sizeof(int) * 10);
	for (size_t i = 0; i < 10; i++)
	{
		p[i] = i + 1;

	}
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d\t", p[i]);
	}
	printf("\n");
	p = (int*)realloc(p, sizeof(int)*5);//�ض�����
	for (size_t i = 0; i < 4; i++)
	{
		printf("%d\t", p[i]);
	}
	free(p);
	p = NULL;
}
int main(void)
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
