#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//���ܣ�д��һ���ַ����ļ���
//#include <stdio.h>
//int fputc(int ch, FILE* stream);
//���ܣ���chת��Ϊunsigned char��д��streamָ�����ļ���
//������
//ch����Ҫд���ļ����ַ�
//stream���ļ�ָ��
//����ֵ��
//�ɹ����ɹ�д���ļ����ַ�
//ʧ�ܣ����� - 1
void test01()
{
	FILE* fp = fopen("fputc.txt", "w");
	char buf[] = "hello world";
	int len = sizeof(buf);
	int i = 0;
	while (len)
	{
		fputc(buf[i++], fp);
		len--;
	}
	fclose(fp);
}
//#include <stdio.h>
//int fgetc(FILE* stream);
//���ܣ���streamָ�����ļ��ж�ȡһ���ַ�
//������
//stream���ļ�ָ��
//����ֵ��
//�ɹ������ض�ȡ�����ַ�
//ʧ�ܣ� - 1
void test02()
{
	FILE* fp = fopen("fputc.txt", "r");
	char buf[13];
	int i = 0;
	while ((buf[i++] = fgetc(fp)) != EOF);
	printf("%s\n", buf);
	fclose(fp);
}
int main(void)
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
