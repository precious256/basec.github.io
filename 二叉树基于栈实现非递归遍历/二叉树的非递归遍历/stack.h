#pragma once
#include<stdbool.h>
struct binary;
typedef struct binary*  datatype1;
typedef struct Stack {
	datatype1 *val;
	int size;
	int capacity;
}Stack;
//��ʼ����ջ
void init1(Stack* s);
//ջ������
void extend(Stack* s);
//��ջ����
void pushStack(Stack* s, datatype1 val);
//��ջ
void popStack(Stack* s);
//����ջ��Ԫ��
datatype1 return_top(Stack* s);
//����ջ����Ч����
int return_num(Stack* s);
//�ж�ջ�Ƿ�Ϊ��
bool is_empty(Stack* s);
//ջ������
void destory1(Stack* s);
