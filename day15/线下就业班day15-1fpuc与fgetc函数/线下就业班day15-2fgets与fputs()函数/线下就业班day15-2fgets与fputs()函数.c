#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
//int fputs(const char* str, FILE* stream);
//���ܣ���str��ָ�����ַ���д�뵽streamָ�����ļ��У��ַ��������� '\0'  ��д���ļ���
//������
//str���ַ���
//stream���ļ�ָ��
//����ֵ��
//�ɹ���0
//
//ʧ�ܣ� - 1
void test01()
{
	char buf[15] = "hello world\n";
	char buf1[12] = "hello";
	FILE* fp = fopen("fputs.txt", "w");
	if (fp == NULL)
	{
		perror(" ");
	}
	fputs(buf, fp);
	fputs(buf1, fp);
	fclose(fp);
}
//fgets  ���ļ���ȡ�ַ���
//ע�� : fgets��ȡ����\n����
//#include <stdio.h>
//char* fgets(char* str, int size, FILE * stream);
//���ܣ���streamָ�����ļ��ڶ����ַ������浽str��ָ�����ڴ�ռ䣬ֱ�����ֻ����ַ��������ļ���β�����Ѷ���size - 1���ַ�Ϊֹ�������Զ������ַ� '\0' ��Ϊ�ַ���������
//������
//str���ַ���
//size��ָ������ȡ�ַ����ĳ��ȣ�size - 1��
//stream���ļ�ָ��
//����ֵ��
//�ɹ����ɹ���ȡ���ַ���
//�����ļ�β����� NULL
void test02()
{
	FILE* fp = fopen("fputs.txt", "r");
	if (fp==NULL)
	{
		perror(" ");
	}
	char buf[128];
	fgets(buf, 128, fp);//��ʱ��fputs�ļ�����hello world\n hello �����ַ����������ڶ�ȡ����\n�ַ�������ֹͣ��ȡ
	printf("buf=%s\n", buf);
	fclose(fp);
}
int main(void)
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
