#include"list.h"
#include<stdio.h>
#include<assert.h>
LinkNode init()
{
	LinkNode pheader = (LinkNode)malloc(sizeof(Node));
	pheader->val = -1;
	pheader->next = NULL;
	return pheader;
}
LinkNode my_malloc(datatype val)
{
	LinkNode newnode = (LinkNode)malloc(sizeof(Node));
	newnode->next = NULL;
	newnode->val = val;
	return newnode;
}
void insert(LinkNode pheader, datatype val)
{
	if (pheader == NULL)
	{
		return;
	}
	LinkNode newnode = my_malloc(val);
	newnode->next = pheader->next;
	pheader->next = newnode;

}
void show(LinkNode pheader)
{
	if (pheader)
	{
		show(pheader->next);
		printf("%d\n", pheader->val);
	}
}
void destory(LinkNode pheader)
{
	LinkNode cur = pheader->next;
	while (cur)
	{
		free(cur);
		cur = cur->next;
	}
	free(pheader);
}
