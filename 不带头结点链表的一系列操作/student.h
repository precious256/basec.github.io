#ifndef __STUDENT_H__
#define __STUDENT_H__
//#include<stdio.h>

typedef struct student
{
	int age;
	
	struct student* next;

}NODE;
typedef NODE* LinkList;
//����һ��ͷ���
LinkList init();
//β��
void Link_insert(LinkList pheader);
//ͷ��
void Link_insertbyheade(LinkList pheader,int data);
//��λ�ò���
void Link_insertbypos(LinkList pheader,int pos,int data);
//��ӡ����
void Link_show(LinkList pheader);
//��ȡĳһλ�õ�Ԫ��
int Getelem(LinkList pheader, int pos);
//ɾ��ĳһλ�õ�ֵ
void Dele_pos(LinkList pheader, int pos);
//ɾ���������ض�Ԫ�ص�ֵ
void Dele_val(LinkList pheader, int data);
//Ѱ���м���
LinkList find_middle(LinkList pheader);
//Ѱ�ҵ����ڼ�����Ԫ��
LinkList find_endnumber(LinkList pheader, int k);
void reverse_Linklist(LinkList pheader);
//�������
void Clean(LinkList pheader);
//��������
void Destory(LinkList pheader);
#endif 

