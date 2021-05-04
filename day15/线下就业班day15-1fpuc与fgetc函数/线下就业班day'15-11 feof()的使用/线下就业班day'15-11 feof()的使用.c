#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//feof()�����������EOF��
//�����ԣ���Ϊfgetc()�����������������ֵΪ-1��1�������ļ�β 2����ȡ���󣨶�ȡ����-1�ַ���
//ע����feof()�����ϸ������ֻ������Ϊ�ж��ļ��Ƿ�������ȡ��������
int main(void)
{
	int c;
	FILE* fp = fopen("Test.c", "r");
	if (!fp)
	{
		perror("File opening failed");
		return -1;
	}

	while ((c = fgetc(fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
	{
		putchar(c);
	}
	//�ж���ʲôԭ�������
	if (ferror(fp))
		puts("I/O error when reading");
	else if (feof(fp))
		puts("End of file reached successfully");
	fclose(fp);
	system("pause");
	return EXIT_SUCCESS;
}
