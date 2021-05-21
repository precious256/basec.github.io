#pragma once
#include<stdbool.h>
typedef int  datatype1;
typedef struct Stack {
	datatype1* val1;
	int size;
	int capacity;
}Stack;
void init1(Stack* s);
//ջ������
void extend(Stack* s);
//��ջ����
void pushStack(Stack* s, datatype1 val);
//��ջ
void popStack(Stack* s);
void destory1(Stack* s);
bool is_empty(Stack* s);
void stack_show(Stack* s);
datatype1 return_top(Stack* s);
typedef int datatype;
typedef struct list
{
	datatype val;
	struct list* next;
}Node;
typedef Node* LinkNode;
LinkNode init();
LinkNode my_malloc(datatype val);
void insert(LinkNode pheader, datatype val);
void show(LinkNode pheader,  Stack* s);
void destory(LinkNode pheader);
