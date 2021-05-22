#include"queue.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
//��ʼ���ö���
void init(Queue* p)
{
	assert(p);
	p->back = p->front = my_malloc(0);
}
//���ٿռ�
Qnode* my_malloc(datatype val)
{
	Qnode* newnode = (Qnode*)malloc(sizeof(Qnode));
	newnode->val=val;
	newnode->next = NULL;
	return newnode;
}
//����в���
void push_queue(Queue* p,datatype val)
{
	assert(p);
	p->back->next = my_malloc(val);
	p->back = p->back->next;
}
//���Ӳ���
void pop_queue(Queue* p)
{
	Qnode* del = NULL;
	assert(p);
	//�����������һ����ɾ���û����ЧԪ�أ�һ�����е�
	if (!is_empty(p))
	{
		del = p->front->next;
		p->front->next = del->next;
		free(del);
		//������Ҫȷ���ǲ��ǳ����к��û����ЧԪ����
		if (p->front->next == NULL)
		{
			p->back = p->front;//��back����ָ��ͷ���
		}
	}
	else
	{
		return;
	}
}
//�ж϶����Ƿ�Ϊ��
bool is_empty(Queue* p)
{
	return p->front == p->back;//����ʱָ��ͬһָ�����ʾû����ЧԪ��
}
//��ȡ��ͷԪ��
datatype return_top(Queue* p)
{
	assert(!is_empty(p));
	return p->front->next->val;
	
}
//��ȡ��βԪ��
datatype return_back(Queue* p)
{
	assert(!is_empty(p));
	return p->back->val;
}
//������ЧԪ�ظ���
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
//���ٶ���
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
//��������
void test()
{
	Queue p;
	init(&p);
	push_queue(&p, 1);
	push_queue(&p, 2);
	push_queue(&p, 3);
	push_queue(&p, 4);
	push_queue(&p, 5);
	printf("��ǰ��ЧԪ��Ϊ%d\n", return_value(&p));
	printf("��ͷԪ��Ϊ%d\n", return_top(&p));
	printf("��βԪ��Ϊ%d\n", return_back(&p));
	printf("��ǰ�����Ƿ�Ϊ��%d\n", is_empty(&p));
	pop_queue(&p);
	pop_queue(&p);
	printf("��ǰ��ЧԪ��Ϊ%d\n", return_value(&p));
	printf("��ͷԪ��Ϊ%d\n", return_top(&p));
	printf("��βԪ��Ϊ%d\n", return_back(&p));
	printf("��ǰ�����Ƿ�Ϊ��%d\n", is_empty(&p));
	pop_queue(&p);
	pop_queue(&p);
	printf("��ǰ��ЧԪ��Ϊ%d\n", return_value(&p));
	printf("��ͷԪ��Ϊ%d\n", return_top(&p));
	printf("��βԪ��Ϊ%d\n", return_back(&p));
	printf("��ǰ�����Ƿ�Ϊ��%d\n", is_empty(&p));
	destory(&p);
	printf("��ǰ�����Ƿ�Ϊ��%d\n", is_empty(&p));
}