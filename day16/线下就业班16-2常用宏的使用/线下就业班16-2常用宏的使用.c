#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#define log(msg) Log(__FILE__,__LINE__,__DATE__,__TIME__,msg)
//__FILE__���ص�ǰ�������ļ�
//__LINE__���س���ĵڼ���
//__DATE__���س��������
//__TIME__���س����ʱ��
void Log(const char* file, int line, const char* data, const char* time, const char* msg)
{
	printf("%s : %d : %s [%s-%s]\n", file, line, msg, data, time);
}
void test01()
{
	FILE* fp = fopen("may.txt", "r");
	if (fp == NULL)
	{
		log("���ļ�ʧ��");
	}
	else
	{
		log("���ļ��ɹ�");
	}
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
