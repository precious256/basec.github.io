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
//初始化该队列
void init(Queue *p);
//开辟空间
Qnode* my_malloc(datatype1 val);
//入队列操作
void push_queue(Queue* p, datatype1 val);
//出队操作
void pop_queue(Queue* p);
//判断队列是否为空
bool is_empty(Queue* p);
//获取队头元素
datatype1 return_top(Queue* p);
//获取队尾元素
datatype1 return_back(Queue* p);
//返回有效元素个数
int return_value(Queue* p);
//销毁队列
void destory1(Queue* p);


