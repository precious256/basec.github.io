#include"stack.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>
//��ʼ����ջ
void init(Stack* s)
{
	assert(s);
	s->val = (datatype*)malloc(sizeof(datatype) * 5);
	s->capacity = 5;
	s->size = 0;
	
}
//ջ������
void extend(Stack* s)
{
	if (s->size == s->capacity)
	{
		s->val = (datatype *)realloc(s->val,sizeof(datatype)* s->capacity * 2);
		if (s->val == NULL)
		{
			printf("�ڴ�����ʧ��\n");
			return;
		}
		s->capacity *= 2;
	}
}
//��ջ����
void pushStack(Stack* s, datatype val)
{
	assert(s);
	extend(s);
	s->val[s->size++] = val;
}
//��ջ
void popStack(Stack* s)
{
	if (is_empty(s))
	{
		return;
	}
	else
	{
		s->size--;
	}
}
//����ջ��Ԫ��
datatype return_top(Stack* s)
{
	if (is_empty(s))
	{
		return;
	}
	else
	{
		return s->val[s->size - 1];
	}
}
//����ջ����Ч����
int return_num(Stack* s)
{
	assert(s);
	return s->size;
}
//�ж�ջ�Ƿ�Ϊ��
bool is_empty(Stack* s)
{
	assert(s);
	if (s->size != 0)
	{
		return false;
	}
	return true;
}
//ջ������
void destory(Stack* s)
{
	assert(s);
	if (s->val != NULL)
	{
		free(s->val);
		s->val = NULL;
	}
}