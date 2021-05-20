#include"Dlist.h"
#include<stdio.h>
#include<malloc.h>
//��ʼ��ͷ���
LinkNode init()
{
	LinkNode pheader = my_malloc(0);
	pheader->prev = pheader;
	pheader->next = pheader;
	return pheader;
}
//ִ�е��ǿ����ڴ溯��
LinkNode my_malloc(eletype data)
{
	LinkNode newnode = (LinkNode)malloc(sizeof(Node));
	if (newnode == NULL)
	{ 
		printf("�ڴ濪�ٲ��ɹ�\n");
		return;
	}
	newnode->val = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}
//ִ�е���ͷ�����
void pushfront(LinkNode header, eletype data)
{
	insert_num(header->next, data);
}
//ִ�е���ͷɾ�Ĳ���
void popfront(LinkNode pheader)
{
	delete_num(pheader->next);
}
//ִ�е���β�����
void pushback(LinkNode pheader, eletype data)
{
	insert_num(pheader, data);

}
//ִ�е���βɾ�Ĳ���
void popback(LinkNode pheader)
{
	delete_num(pheader->prev);
}
//ִ�е�������λ��Ԫ�ص�ɾ��
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
//ִ�е�������Ԫ�صĲ���
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
//�������ЧԪ�ظ�����ͳ��
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
//����ĳһԪ���״γ��ֵĽ��
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
//˫��ѭ��������޸�
void  rectify(LinkNode p, eletype olddata, eletype newdata)
{
	LinkNode recitf_num=search(p,olddata);
	if (recitf_num)
	{
		recitf_num->val = newdata;
	}
	else
	{
		printf("Ԫ�ز����ڣ��޸�ʧ��\n");
		return;
	}
}
//��������
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
//���������
void destory(LinkNode pheader)
{
	if (pheader == NULL)
	{
		return;
	}
	else
	{
		clean(pheader);//��Ϊ�������û��Ĵ������٣�ֻ����ͷ��㣬��δ�Ժ���������٣�����ڴ��й¶
		free(pheader);
		pheader->next = NULL;
		pheader->prev = NULL;
	}
}
//����Ĵ�ӡ
void print(LinkNode pheader)
{
	if (pheader == NULL || pheader->next == pheader)
	{
		printf("������Ԫ��\n");
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