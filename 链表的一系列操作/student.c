#include"student.h"
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
LinkList init()
{
	NODE* pheader = (LinkList)malloc(sizeof(NODE));
	if (pheader == NULL)
	{
		return;
	}
	//ͷ���ֻ��һ����ʶ���ã�����֮����ã���δ������Ч���ݣ���ȻҲ��������Ϊ��Ч����
	pheader->age = -1;
	pheader->next = NULL;
	return pheader;

}
//β��
void Link_insert(LinkList pheader)
{
	if (pheader == NULL)
	{
		return;
	}
	LinkList pre, pcur;
	int temp;
	pre = pheader;
	pcur = pheader->next;
	while (pcur != NULL)
	{
		pre = pcur;//������¼����NULLֵǰ��ĵ�һ����Чλ
		pcur = pcur->next;
	}
	while (1)
	{
		printf("���������䣬-1�˳�\n");
		scanf("%d", &temp);
		if (temp == -1)
		{
			break;
		}
		LinkList newnode = (LinkList)malloc(sizeof(NODE));
		newnode->age = temp;
		newnode->next = NULL;
		pre->next = newnode;
		pre = newnode;
		

	}
	printf("β�������\n");
}
//��ӡ����
void Link_show(LinkList pheader)
{
	if (pheader == NULL)
	{
		return;
	}
	LinkList pcur = pheader->next;
	
	
	while (pcur != NULL)
	{
		printf("����%d\n", pcur->age);
		pcur = pcur->next;
	}
	printf("��ӡ���\n");
}
//ͷ��
void Link_insertbyheade(LinkList pheader, int data)
{
	if (pheader == NULL)
	{
		return;
	}
	LinkList newnode = (LinkList)malloc(sizeof(NODE));
	newnode->age = data;
	newnode->next = pheader->next;
	pheader->next = newnode;
}
//��λ�ò���
void Link_insertbypos(LinkList pheader, int pos, int data)
{
	if (pheader == NULL)
	{
		return;
	}
	int j = 1;
	LinkList pcur = pheader->next;
	LinkList pre = pheader;
	while (j < pos && pcur)
	{
		pre = pcur;//Ϊ�˱������λ�ò�������ȡǿ�Ʋ����������ı������
		pcur = pcur->next;
		++j;
	}
	//����λ�ò�����������λ��С��1ʱ����ʱ��ȡͷ����룬�����ȡβ��
	//Ӧ�Բ���λ�ò����������β��
	if (pcur == NULL)
	{
		LinkList newnode = (LinkList)malloc(sizeof(NODE));
		newnode->age = data;
		newnode->next = NULL;
		pre->next = newnode;
	}
	//�ȿ���ִ���������룬Ҳ��ִ�е�λ��С��1ʱ��ͷ��
	else
	{
		LinkList newnode = (LinkList)malloc(sizeof(NODE));
		newnode->age = data;
		newnode->next = pre->next;
		pre->next = newnode;
	}

}
//��ȡĳһλ�õ�Ԫ��
int Getelem(LinkList pheader, int pos)
{
	if (pheader == NULL)
	{
		return;
	}
	int j = 1;
	LinkList pcur = pheader->next;
	while (pcur != NULL && j < pos)
	{
		pcur = pcur->next;
		++j;
	}
	if (pcur == NULL)
	{
		printf("λ��Ϊ%d��Ԫ�ز�����\n", pos);
	}
	else
	{
		printf("λ��Ϊ%d��Ԫ�ص�ֵΪ%d\n", pos, pcur->age);
	}
}
//ɾ��ĳһλ�õ�ֵ
void Dele_pos(LinkList pheader, int pos)
{
	if (pheader == NULL)
	{
		return;
	}
	int j = 1;
	LinkList pcur = pheader;
	while (pcur != NULL && j < pos)
	{
		pcur = pcur->next;
		++j;
	}
	if (pcur == NULL)
	{
		printf("λ��Ϊ%d��Ԫ�ز�����\n", pos);
	}
	else
	{
		LinkList del = pcur->next;
		pcur->next = del->next;
		free(del);

	}
}
//ɾ���������ض�Ԫ�ص�ֵ
void Dele_val(LinkList pheader, int data)
{
	if (pheader == NULL)
	{
		return;
	}
	LinkList pre, pcur;
	pre = pheader;
	pcur = pheader->next;
	while (pcur)
	{
		if (pcur->age == data)
		{
			LinkList pnext = pcur->next;
			free(pcur);
			pre->next = pnext;
			pcur = pnext;


		}
		else
		{
		pre = pcur;
		pcur = pcur->next;
		}
		
	}
}
//Ѱ���м���
LinkList find_middle(LinkList pheader)
{
	//�ⷨ������ָ��İ취
	//�������ȶ���һ��fast(��)��slow(��)���
	//���ȶ�����ָ��ͷ��㣬Ȼ��slowÿ��ָ����һ����fast��ָ��ÿ�α�fast����һ��
	if (pheader == NULL)
	{
		return;
	}
	LinkList fast, slow;
	//��Ϊ�ҵ�ͷ��㲢δʹ����Чֵ,���Դ�ʱָ�����ͷ������һ�����
	fast = pheader->next;
	slow = pheader->next;
	while (fast != NULL&&fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//ԭ����Ϊ��ָ��ÿ�α���ָ�����һ�������Ե���ָ���ߵ���βʱ����ʱǡ����ָ��ָ��������м��㡣
	return slow;
}
//Ѱ�ҵ����ڼ�����Ԫ��
LinkList find_endnumber(LinkList pheader, int k)
{
	if (pheader == NULL)
	{
		return;
	}
	LinkList fast,slow ;
	slow = pheader->next;
	fast = pheader->next;
	while (k--)
	{
		if (fast)
		{
			fast = fast->next;
		}
		else
		{
			return NULL;
		}

	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
void reverse_Linklist(LinkList pheader)
{
	if (pheader == NULL)
	{
		return;
	}
	//��ָ�뷨��pre��¼��������Ԫ��ǰһ��� pcur��¼���ǵ�ǰ������� pnext ��¼��һ���
	LinkList pre, pcur, pnext;
	pre = NULL;
	pnext = NULL;
	pcur = pheader->next;
	while (pcur)
	{
		pnext = pcur->next;
		pcur->next = pre;
		pre = pcur;
		pcur = pnext;
	}
	pheader->next = pre;
}
//�������,�����ٵ������Ǵ�ʱ����ͷ��㣬���������ͷ������д��
void Clean(LinkList pheader)
{
	if (pheader == NULL)
	{
		return;
	}
	LinkList pcur = pheader->next;
	while (pcur)
	{
		LinkList pnext = pcur->next;
		free(pcur);
		pcur = pnext;
	}
	pheader->next = NULL;
}
//��������,�������ʣ��ͷ���ɾ������ʱ����д�룬��ֻ�����¿���
void Destory(LinkList pheader)
{
	Clean(pheader);//������ǰ�����Ƚ���������գ����������ڴ�й¶�����
	if (pheader == NULL)
	{
		return;
	}
	free(pheader);
	pheader = NULL;
}