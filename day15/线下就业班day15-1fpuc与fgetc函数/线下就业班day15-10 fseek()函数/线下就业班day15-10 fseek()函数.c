
//fseek
//#include <stdio.h>
//int fseek(FILE* stream, long offset, int whence);
//���ܣ��ƶ��ļ������ļ���꣩�Ķ�дλ�á�
//������
//stream���Ѿ��򿪵��ļ�ָ��
//offset������whence���ƶ���λ������ƫ��������������������Ҳ���Ը���������������������whence�����ƶ�������Ǹ�����
// �������whence�����ƶ��������ǰ�ƶ����ֽ����������ļ���ͷ������أ��������ƶ����ֽ����������ļ�ĩβ���ٴ�д��ʱ�������ļ��ߴ硣
//whence����ȡֵ���£�
//SEEK_SET�����ļ���ͷ�ƶ�offset���ֽ�
//
//SEEK_CUR���ӵ�ǰλ���ƶ�offset���ֽ�
//SEEK_END�����ļ�ĩβ�ƶ�offset���ֽ�
//����ֵ��
//�ɹ���0
//ʧ�ܣ� - 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
int main()
{
    FILE* fp = NULL;
    fp = fopen("fseek.txt", "wb");
    if (!fp)
    {
        perror("");
        return -1;
    }
    fputs("helloworld", fp);
    fseek(fp, 0, SEEK_SET);//�ƶ���굽ͷ
    fputs("seek", fp);
    fseek(fp, -20, SEEK_END);//��������ô�죿
    fputs("abc", fp);
    fclose(fp);
    system("pause");
    return 0;
}