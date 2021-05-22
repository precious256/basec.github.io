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
//初始化该队列
void init(Queue *p);
//开辟空间
Qnode* my_malloc(datatype val);
//入队列操作
void push_queue(Queue* p, datatype val);
//出队操作
void pop_queue(Queue* p);
//判断队列是否为空
bool is_empty(Queue* p);
//获取队头元素
datatype return_top(Queue* p);
//获取队尾元素
datatype return_back(Queue* p);
//返回有效元素个数
int return_value(Queue* p);
//销毁队列
void destory(Queue* p);
//测试用例
void test();

