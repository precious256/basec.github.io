//touchָ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//gcc����4���裺���ص㡿
//1. Ԥ���� - E	xxx.i	Ԥ�����ļ�
//gcc - E xxx.c - o xxx.i
//1) ͷ�ļ�չ����-- - ������﷨���� ����չ�������ļ���
//2���궨���滻��-- - �������滻Ϊ��ֵ��
//3���滻ע�͡�-- - ��ɿ���
//4��չ����������-- - ����������չ��ָ�
//2. ���� - S	xxx.s	����ļ�
//gcc - S hello.i - o hello.s
//1�����м���﷨���󡣡��ص㡿-- - ��������4���������ʱ�Ĺ��̡�
//2����C������� ���ָ��õ�.s ����ļ���
//3. ��� - c	xxx.o	Ŀ���ļ�
//gcc - c hello.s - o hello.o
//1�����룺�����ָ���ɶ�Ӧ�� �����Ʊ��롣
//4. ����		��	xxx.exe	��ִ���ļ���
//gcc  hello.o - o hello.exe
//1�����ݶκϲ�
//2�����ݵ�ַ����
//3��������
//vs ��Ϊ IDE(���ɿ�������)

void test01()
{
	FILE* fp = fopen("a.txt", "r");
	if (fp == NULL)
	{
		perror("");
	}
	fclose(fp);
}
int main(void)
{
	//printf("%d\n", ___STDC___);
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
