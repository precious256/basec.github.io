#include"list.h"
#include<stdio.h>
#include<assert.h>
void init1(Stack* s)
{
	assert(s);
	s->val1 = (datatype1*)malloc(sizeof(datatype1) * 5);
	s->capacity = 5;
	s->size = 0;
}
//Õ»µÄÀ©ÈÝ
void extend(Stack* s)
{
	if (s->size == s->capacity)
	{
		s->val1 = (datatype1*)realloc(s->val1, sizeof(datatype1) * s->capacity * 2);
		if (s->val1 == NULL)
		{
			printf("ÄÚ´æÀ©ÈÝÊ§°Ü\n");
			return;
		}
		s->capacity *= 2;
	}
}
//ÈëÕ»²Ù×÷
void pushStack(Stack* s, datatype1 num)
{
	assert(s);
	extend(s);
	s->val1[s->size++] = num;
}
//³öÕ»
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
void destory1(Stack* s)
{
	assert(s);
	if (s->val1 != NULL)
	{
		free(s->val1);
		s->val1 = NULL;
	}
}
datatype1 return_top(Stack* s)
{
	if (is_empty(s))
	{
		return;
	}
	else
	{
		return s->val1[s->size - 1];
	}
}
bool is_empty(Stack* s)
{
	assert(s);
	if (s->size != 0)
	{
		return false;
	}
	return true;
}
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
void show(LinkNode pheader,Stack *s)
{
	/*if (pheader)
	{
		show(pheader->next);
		printf("%d\n", pheader->val);
	}*/
	
	while (pheader)
	{
		pushStack(s, pheader->val);
		pheader = pheader->next;
	}
	
}
void stack_show(Stack* s)
{
	
	while (!is_empty(s))
	{
		
		printf("%d\n", return_top(s));
		popStack(s);
	}
	destory1(s);
}
void destory(LinkNode pheader)
{
	
	if (pheader == NULL)
	{
		return;
	}
	LinkNode pcur = pheader->next;
	while (pcur)
	{
		LinkNode pnext = pcur->next;
		free(pcur);
		pcur = pnext;
	}
	pheader->next = NULL;
	
}
