#pragma once
#include<stdio.h>
struct message
{
	char address[20];
	char name[12];
	char sex[2];
	int age;
	int pn;

};
static int size = 0;
//��ʼ��
void init();
//���ļ�
//��ӳ�Ա
void add();
//���ҳ�Ա
struct message* search(const char* name);
//ɾ����Ա
void dele_message(const char* name);
//�޸ĳ�Ա
void rectify_message(const char* name);
//չʾ��Ա
void show();
//�������Գ�Ա����
void sort_byname();
//�����Ա
void destory();

