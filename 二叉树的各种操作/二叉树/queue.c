#include"queue.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
//初始化该队列
void init(Queue* p)
{
	assert(p);
	p->back = p->front = my_malloc(0);
}
//开辟空间
Qnode* my_malloc(datatype1 val)
{
	Qnode* newnode = (Qnode*)malloc(sizeof(Qnode));
	newnode->val=val;
	newnode->next = NULL;
	return newnode;
}
//入队列操作
void push_queue(Queue* p,datatype1 val)
{
	assert(p);
	p->back->next = my_malloc(val);
	p->back = p->back->next;
}
//出队操作
void pop_queue(Queue* p)
{
	Qnode* del = NULL;
	assert(p);
	//分两种情况，一个是删完后没有有效元素，一个是有的
	if (!is_empty(p))
	{
		del = p->front->next;
		p->front->next = del->next;
		free(del);
		//这里需要确定是不是出队列后就没有有效元素了
		if (p->front->next == NULL)
		{
			p->back = p->front;//让back重新指向头结点
		}
	}
	else
	{
		return;
	}
}
//判断队列是否为空
bool is_empty(Queue* p)
{
	return p->front == p->back;//若此时指针同一指向，则表示没有有效元素
}
//获取队头元素
datatype1 return_top(Queue* p)
{
	assert(!is_empty(p));
	return p->front->next->val;
	
}
//获取队尾元素
datatype1 return_back(Queue* p)
{
	assert(!is_empty(p));
	return p->back->val;
}
//返回有效元素个数
int return_value(Queue* p)
{
	assert(p);
	Qnode* cur = p->front->next;
	int count = 0;
	while (cur)
	{
		++count;
		cur = cur->next;
	}
	return count;
}
//销毁队列
void destory1(Queue* p)
{
	Qnode* del = p->front;
	while (del)
	{
		p->front = del->next;
		free(del);
		del = p->front;
	}
	p->back = p->front = NULL;
}
