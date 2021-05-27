#pragma once
#include<stdbool.h>
struct binary;
typedef struct binary* datatype1;
typedef struct queue
{
	datatype1 val;
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
Qnode* my_malloc(datatype1 val);
//����в���
void push_queue(Queue* p, datatype1 val);
//���Ӳ���
void pop_queue(Queue* p);
//�ж϶����Ƿ�Ϊ��
bool is_empty(Queue* p);
//��ȡ��ͷԪ��
datatype1 return_top(Queue* p);
//��ȡ��βԪ��
datatype1 return_back(Queue* p);
//������ЧԪ�ظ���
int return_value(Queue* p);
//���ٶ���
void destory1(Queue* p);


