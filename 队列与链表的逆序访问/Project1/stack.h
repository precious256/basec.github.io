#pragma once
#include<stdbool.h>
typedef int  datatype;
typedef struct Stack {
	datatype *val;
	int size;
	int capacity;
}Stack;
//初始化该栈
//void init(Stack* s);
//栈的扩容
void extend(Stack* s);
//入栈操作
void pushStack(Stack* s, datatype val);
//出栈
void popStack(Stack* s);
//返回栈顶元素
datatype return_top(Stack* s);
//返回栈的有效个数
int return_num(Stack* s);
//判断栈是否为空
bool is_empty(Stack* s);
//栈的销毁
//void destory(Stack* s);
