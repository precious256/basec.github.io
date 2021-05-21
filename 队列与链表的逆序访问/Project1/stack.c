#include"stack.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>
//初始化该栈
void init(Stack* s)
{
	assert(s);
	s->val = (datatype*)malloc(sizeof(datatype) * 5);
	s->capacity = 5;
	s->size = 0;
	
}
//栈的扩容
void extend(Stack* s)
{
	if (s->size == s->capacity)
	{
		s->val = (datatype *)realloc(s->val,sizeof(datatype)* s->capacity * 2);
		if (s->val == NULL)
		{
			printf("内存扩容失败\n");
			return;
		}
		s->capacity *= 2;
	}
}
//入栈操作
void pushStack(Stack* s, datatype val)
{
	assert(s);
	extend(s);
	s->val[s->size++] = val;
}
//出栈
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
//返回栈顶元素
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
//返回栈的有效个数
int return_num(Stack* s)
{
	assert(s);
	return s->size;
}
//判断栈是否为空
bool is_empty(Stack* s)
{
	assert(s);
	if (s->size != 0)
	{
		return false;
	}
	return true;
}
//栈的销毁
void destory(Stack* s)
{
	assert(s);
	if (s->val != NULL)
	{
		free(s->val);
		s->val = NULL;
	}
}