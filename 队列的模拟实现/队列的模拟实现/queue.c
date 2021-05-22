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
Qnode* my_malloc(datatype val)
{
	Qnode* newnode = (Qnode*)malloc(sizeof(Qnode));
	newnode->val=val;
	newnode->next = NULL;
	return newnode;
}
//入队列操作
void push_queue(Queue* p,datatype val)
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
datatype return_top(Queue* p)
{
	assert(!is_empty(p));
	return p->front->next->val;
	
}
//获取队尾元素
datatype return_back(Queue* p)
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
void destory(Queue* p)
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
//测试用例
void test()
{
	Queue p;
	init(&p);
	push_queue(&p, 1);
	push_queue(&p, 2);
	push_queue(&p, 3);
	push_queue(&p, 4);
	push_queue(&p, 5);
	printf("当前有效元素为%d\n", return_value(&p));
	printf("队头元素为%d\n", return_top(&p));
	printf("队尾元素为%d\n", return_back(&p));
	printf("当前队列是否为空%d\n", is_empty(&p));
	pop_queue(&p);
	pop_queue(&p);
	printf("当前有效元素为%d\n", return_value(&p));
	printf("队头元素为%d\n", return_top(&p));
	printf("队尾元素为%d\n", return_back(&p));
	printf("当前队列是否为空%d\n", is_empty(&p));
	pop_queue(&p);
	pop_queue(&p);
	printf("当前有效元素为%d\n", return_value(&p));
	printf("队头元素为%d\n", return_top(&p));
	printf("队尾元素为%d\n", return_back(&p));
	printf("当前队列是否为空%d\n", is_empty(&p));
	destory(&p);
	printf("当前队列是否为空%d\n", is_empty(&p));
}