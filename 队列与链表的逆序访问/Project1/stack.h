#pragma once
#include<stdbool.h>
typedef int  datatype;
typedef struct Stack {
	datatype *val;
	int size;
	int capacity;
}Stack;
//��ʼ����ջ
//void init(Stack* s);
//ջ������
void extend(Stack* s);
//��ջ����
void pushStack(Stack* s, datatype val);
//��ջ
void popStack(Stack* s);
//����ջ��Ԫ��
datatype return_top(Stack* s);
//����ջ����Ч����
int return_num(Stack* s);
//�ж�ջ�Ƿ�Ϊ��
bool is_empty(Stack* s);
//ջ������
//void destory(Stack* s);
