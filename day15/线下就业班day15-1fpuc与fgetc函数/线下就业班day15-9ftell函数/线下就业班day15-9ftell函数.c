#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
//long ftell(FILE* stream);
//���ܣ���ȡ�ļ������ļ���꣩�Ķ�дλ�á�
//������
//stream���Ѿ��򿪵��ļ�ָ��
//����ֵ��
//�ɹ�����ǰ�ļ������ļ���꣩�Ķ�дλ��
//ʧ��:-1
/*4 rewind
	: ����: ������ƶ�����ͷ, ��fseek(fp, 0, SEEK_SET);

void rewind(FILE* stream);
���ܣ����ļ������ļ���꣩�Ķ�дλ���ƶ����ļ���ͷ��
������
stream���Ѿ��򿪵��ļ�ָ��
����ֵ��
�޷���ֵ*/

void test01()
{
	FILE* fp = fopen("1.txt", "rb");
	if (fp == NULL)
	{
		perror("");
		return;
	}
	
	
	char ch = fgetc(fp);
	int pos=ftell(fp);
	printf("%d\n", pos);rewind(fp);
	pos = ftell(fp);
	printf("%d\n", pos);
	
	fclose(fp);

}

int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
