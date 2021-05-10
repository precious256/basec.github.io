#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
struct student
{
	int val;
	struct student* next;
};
struct student* init()
{
	struct student* pheader = (struct student*)malloc(sizeof(struct student));
	if (pheader == NULL)
	{
		return;
	}
	pheader->val = 0;
	return pheader;
}
void insert(struct student* pheader)
{
	if(pheader == NULL)
	{
		return;
	}
	struct student* pcur = pheader;
	int temp;
	while (scanf("%d", &temp)==1&&temp!=-1)
	{
		struct student* newnode = (struct student*)malloc(sizeof(struct student));
		newnode->val = temp;
		pcur->next = newnode;
		newnode->next = NULL;
		pcur = newnode;
	}

}
void show(struct student* pheader)
{
	if(pheader == NULL)
	{
		return;
	}
	struct student* pcur = pheader->next;
	while (pcur != NULL)
	{
		printf("%d\t", pcur->val);
		pcur = pcur->next;
	}
	printf("\n");
}
void de_link(struct student* pheader, int val)
{
	if (pheader == NULL)
	{
		return;
	}
	struct student* pre = pheader;
	struct student* pcur = pheader->next;
	while (pcur != NULL)
	{
		struct student* pnext = pcur->next;
		if (pcur->val == val)
		{
			pre->next = pcur->next;
			free(pcur);
		}
		pre = pcur;
		pcur = pnext;
		
	}
}
void test01()
{
	struct student* pheader = init();
	insert(pheader);
	
	show(pheader);
	de_link(pheader, 2);
	show(pheader);
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
