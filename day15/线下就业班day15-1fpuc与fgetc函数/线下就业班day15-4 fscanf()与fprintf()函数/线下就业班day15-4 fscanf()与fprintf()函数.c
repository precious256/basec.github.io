#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
//int fprintf(FILE* stream, const char* format, ...);
//���ܣ����ݲ���format�ַ�����ת������ʽ�����ݣ�Ȼ�󽫽�������streamָ�����ļ��У�ָ�������ַ��������� '\0'  Ϊֹ��
//������
//stream���Ѿ��򿪵��ļ�
//format���ַ�����ʽ���÷���printf()һ��
//����ֵ��
//�ɹ���ʵ��д���ļ����ַ�����
//ʧ�ܣ� - 1
void test01()
{
	//��printf()��������printf()�ǽ�������뵽�նˣ���fpritnf()�ǽ����������ļ���
	//stdin�������� \stdout�ն� \  stderr������Ǵ�����Ϣ
	fprintf(stdout, "%s", "hello world");//�൱��printf,��Ϊstdout��Ӧ�ľ��Ǻڴ���
	int year, month, day;
	fscanf(stdin, "%d %d %d", &year, &month, &day);//stdin��ʱ�൱��scanf("%d %d %d",&year,&month,&day);
	printf("%d��%d��%d��\n", year, month, day);
	
}
void test02()
{
	FILE* fp = fopen("fprintf.txt", "wb");
	if (fp == NULL)
	{
		perror("");
	}
	int len=fprintf(fp, "%d��%d��\0%d��", 2020, 10, 15);//������\0ֹͣд�룬��ʱ�ļ����е���2020��10�£���Ϊ10λ
	printf("%d\n", len);
	fclose(fp);
	
}
//fscanf()�������
//#include <stdio.h>
//int fscanf(FILE * stream, const char* format, ...);
//���ܣ���streamָ�����ļ���ȡ�ַ����������ݲ���format�ַ�����ת������ʽ�����ݡ�
//������
//stream���Ѿ��򿪵��ļ�
//format���ַ�����ʽ���÷���scanf()һ��
//����ֵ��
//�ɹ���������Ŀ���ɹ�ת����ֵ�ĸ���
//ʧ�ܣ� - 1
void test03()
{
	FILE* fp = fopen("fprintf.txt", "rb");
	if (fp == NULL)
	{
		perror("");
		return;
	}
	int year, month;
	fscanf(fp, "%d��%d��", &year, &month);//ʹ��fscanf()ע�⣺1.Ҫ��֤��Ҫ��ȡ���ݸ�ʽ����ȷ��
	//2.���ļ�����ʲô���ӣ����ȡ��Ӧ����ʱ����������Ҳ���������Ӧ�ĸ�ʽ��Ҫ������ɺ������ݵĴ����ȡ��

	printf("%d\t%d\n", year, month);
}
int main(void)
{
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
