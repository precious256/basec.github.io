#pragma once
#include<stdbool.h>
typedef int datatype;
typedef struct queue
{
	datatype val;
	struct queue* next;
}Qnode;
typedef struct s1
{
	Qnode* front;
	Qnode* back;
}Queue;
//��ʼ���ö���
void init(Queue *p);
//���ٿռ�
Qnode* my_malloc(datatype val);
//����в���
void push_queue(Queue* p, datatype val);
//���Ӳ���
void pop_queue(Queue* p);
//�ж϶����Ƿ�Ϊ��
bool is_empty(Queue* p);
//��ȡ��ͷԪ��
datatype return_top(Queue* p);
//��ȡ��βԪ��
datatype return_back(Queue* p);
//������ЧԪ�ظ���
int return_value(Queue* p);
//���ٶ���
void destory(Queue* p);
//��������
void test();

