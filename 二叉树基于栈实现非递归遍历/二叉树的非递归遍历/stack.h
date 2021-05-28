#pragma once
#include<stdbool.h>
struct binary;
typedef struct binary*  datatype1;
typedef struct Stack {
	datatype1 *val;
	int size;
	int capacity;
}Stack;
//初始化该栈
void init1(Stack* s);
//栈的扩容
void extend(Stack* s);
//入栈操作
void pushStack(Stack* s, datatype1 val);
//出栈
void popStack(Stack* s);
//返回栈顶元素
datatype1 return_top(Stack* s);
//返回栈的有效个数
int return_num(Stack* s);
//判断栈是否为空
bool is_empty(Stack* s);
//栈的销毁
void destory1(Stack* s);
