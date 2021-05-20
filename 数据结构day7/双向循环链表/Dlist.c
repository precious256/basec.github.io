#include"Dlist.h"
#include<stdio.h>
#include<malloc.h>
//初始化头结点
LinkNode init()
{
	LinkNode pheader = my_malloc(0);
	pheader->prev = pheader;
	pheader->next = pheader;
	return pheader;
}
//执行的是开辟内存函数
LinkNode my_malloc(eletype data)
{
	LinkNode newnode = (LinkNode)malloc(sizeof(Node));
	if (newnode == NULL)
	{ 
		printf("内存开辟不成功\n");
		return;
	}
	newnode->val = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}
//执行的是头插操作
void pushfront(LinkNode header, eletype data)
{
	insert_num(header->next, data);
}
//执行的是头删的操作
void popfront(LinkNode pheader)
{
	delete_num(pheader->next);
}
//执行的是尾插操作
void pushback(LinkNode pheader, eletype data)
{
	insert_num(pheader, data);

}
//执行的是尾删的操作
void popback(LinkNode pheader)
{
	delete_num(pheader->prev);
}
//执行的是任意位置元素的删除
void delete_num(LinkNode pos)
{
	if (pos == NULL)
	{
		return;
	}
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
//执行的是任意元素的插入
void insert_num(LinkNode pos, eletype data)
{
	LinkNode newnode = NULL;
	if (pos == NULL)
	{
		return;
	}
	newnode = my_malloc(data);
	newnode->next = pos;
	newnode->prev = pos->prev;
	newnode->prev->next = newnode;
	pos->prev = newnode;

}
//链表的有效元素个数的统计
int cal_num(LinkNode pheader)
{
	if (pheader == NULL || pheader->next == pheader)
	{
		return 0;
	}
	LinkNode cur = pheader->next;
	int count = 0;
	while (cur != pheader)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
//查找某一元素首次出现的结点
LinkNode search(LinkNode pheader,eletype data)
{
	if (pheader == NULL || pheader->next == pheader)
	{
		return NULL;
	}
	LinkNode cur = pheader->next;
	while (cur != pheader)
	{
		if (cur->val == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//双向循环链表的修改
void  rectify(LinkNode p, eletype olddata, eletype newdata)
{
	LinkNode recitf_num=search(p,olddata);
	if (recitf_num)
	{
		recitf_num->val = newdata;
	}
	else
	{
		printf("元素不存在，修改失败\n");
		return;
	}
}
//链表的清空
void clean(LinkNode pheader)
{
	if (pheader == NULL || pheader->next == pheader)
	{
		return;
	}
	LinkNode cur = pheader->next;
	LinkNode* pnext = NULL;
	while (cur != pheader)
	{
		pnext = cur->next;
		free(cur);
		cur = pnext;
	}
	pheader->next = pheader;
	pheader->prev = pheader;

}
//链表的销毁
void destory(LinkNode pheader)
{
	if (pheader == NULL)
	{
		return;
	}
	else
	{
		clean(pheader);//因为避免了用户的错误销毁，只销毁头结点，并未对后续结点销毁，造成内存的泄露
		free(pheader);
		pheader->next = NULL;
		pheader->prev = NULL;
	}
}
//链表的打印
void print(LinkNode pheader)
{
	if (pheader == NULL || pheader->next == pheader)
	{
		printf("链表无元素\n");
		return;
	}
	LinkNode cur = pheader->next;
	LinkNode pnext = NULL;
	while (cur != pheader)
	{
		pnext = cur->next;
		printf("%d\t", cur->val);
		cur = pnext;
	}
	printf("\n");
}