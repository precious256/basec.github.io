//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
//�����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
int number = 0;
struct message
{
	char address[20];
	char name[12];
	char sex[2];
	int age;
	int pn;	
};
struct message* init()//��ʼ��
{
	struct message* init = malloc(sizeof(struct message) * 1000);
	if (init == NULL)
	{
		perror(" ");
	}
	
	return init;
}
void add(struct message *t)
{
	struct message* t1 = t;
	if (t1 == NULL)
	{
		printf("�ÿռ���δ����\n");
		return;
	}
	if (number >= 1000)
	{
		printf("�ڴ��������޷�д��\n");
	}
	
	int choice = 0;
	while (1)
	{
		printf("����������\n");
		while (scanf("%s", &t1->name) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("������������������\n");
			
		}
		printf("�������Ա�\n");
		while (scanf("%s", &t1->sex) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("������������������\n");
		}
		printf("����������\n");
		while (scanf("%d", &t1->age) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("������������������\n");
		}
		printf("��������ĵ绰����\n");
		while (scanf("%d", &t1->pn) != 1)
		{
			while (getchar() != '\n')
			{

			}
			
			printf("������������������\n");
		}
		printf("��������ĵ�ַ\n");
		while (scanf("%s", &t1->address) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("������������������\n");
		}
		number++;
		printf("��%d���û��Ѿ������Ϣ¼��\n", number);
		t1++;
		printf("����ѡ��¼�뻹���˳�,0�˳�\n");
		scanf("%d", &choice);
		if (choice!=0)
		{
			continue;
		}
		else
		{
			return;
		}
		
	}

}
void show(struct message* t1)
{
	if (t1 == NULL)
	{
		perror(" ");
		return;
	}
	if (number == 0)
	{
		printf("�ÿռ���δ¼������\n");
		return;
	}
	for (size_t i = 0; i < number; i++)
	{
		printf("����%s\n", t1->name);
		printf("�Ա�%s\n", t1->sex);
		printf("����%d\n", t1->age);
		printf("��ϵ��ʽ%d\n", t1->pn);
		printf("��ַ%s\n", t1->address);
		t1++;
	}
}
void dl(struct message* p)
{
	if (p == NULL)
	{
		return;
	}
	free(p);
	p = NULL;
	number = 0;
}

void sort_name(struct message* p)
{
	if (p == NULL)
	{
		return;
	}
	if (number == 0)
	{
		printf("�ÿռ���δ¼������\n");
		return;
	}
	struct message* temp = p;
	int max;
	int len = sizeof(struct message);
	/*struct message* temp1 = malloc(sizeof(struct message));*/
	for (size_t i = 0; i < number-1; i++)
	{
		max = i;
		for (size_t j = 0; j < number; j++)
		{
			if (strcmp(temp[max].name, temp[j].name)>0)
			{
				max = j;
			}
		}
		if (i != max)
		{
			/*memcpy(temp1,temp+i*len, sizeof(struct message));
			memcpy(temp + i * len, temp + max * len, sizeof(struct message));
			memcpy(temp + max * len, temp1, sizeof(struct message));*/
			struct message s1 = temp[i];
			temp[i] = temp[max];
			temp[max] = s1;
		}
	}
	/*free(temp1);*/
	//temp1 = NULL;
}
void search(struct message* p, int n)
{
	assert(p != NULL);
	if (number == 0)
	{
		printf("�ÿռ���δ¼������\n");
		return;
	}
	struct message* temp = p;
	for (size_t i = 0; i < number; i++)
	{
		if (temp->pn - n == 0)
		{
			printf("���ҵ�\n");
			printf("����%s\n", temp->name);
			printf("�Ա�%s\n", temp->sex);
			printf("����%d\n", temp->age);
			printf("��ϵ��ʽ%d\n", temp->pn);
			printf("��ַ%s\n", temp->address);
			break;
		}
		temp++;
		if (i+1 == number)
		{
			printf("δ�ҵ�\n");
			return 0;
		}
	}
	return 1;
}
void rectify(struct message* p,int n)
{
	assert(p != NULL);
	if (number == 0)
	{
		printf("�ÿռ���δ¼������\n");
		return;
	}
	struct message* temp = p;
	for (size_t i = 0; i < number; i++)
	{
		if (temp->pn - n == 0)
			
		{
			printf("�û����ҵ����밴��ʾ����¼����Ϣ\n");
			printf("����������\n");
			while (scanf("%s", &temp->name) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");
			}
			printf("�������Ա�\n");
			while (scanf("%s", &temp->sex) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");
			}
			printf("��������ĵ绰����\n");
			while (scanf("%d", &temp->pn) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");
			}
			printf("��������ĵ�ַ\n");
			while (scanf("%s", &temp->address) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");
			}
			break;
		}
		
		temp++;
		if (i+1 == number)
		{
			printf("δ�ҵ����û�\n");
		}
	}

}
void dele(struct message* p,int n)
{
	assert(p != NULL);
	if (number == 0)
	{
		printf("�ÿռ���δ¼������\n");
		return;
	}
	struct message* temp = p;
	for (size_t i = 0; i < number; i++)
	{
		if (temp->pn - n == 0)
		{
			printf("���û���ɾ��\n");
			for (size_t j = i; j < number; j++)
			{
				temp = temp+1;
				temp++;
			}
			number--;
		}
		else if (i + 1 == number)
		{
			printf("δ�ҵ�\n");
			return;
		}
	}

}
void test()
{
	struct message* t = init();
	int choice;
	int k;
	while (1)
	{
		printf("************************\n");
		printf("��ӭ�����绰��ϵͳ\n");
		printf("************************\n");
		printf("��ѡ��������Ҫ�Ĳ���\n");
		printf("1.¼����Ϣ\t");
		printf("2.�����û�\n");
		printf("3.ɾ���û�\t");
		printf("4.�޸��û�\n");
		printf("5.����������\t");
		printf("6.���ٸü�¼��\n");
		printf("7.����ü�¼��\n");
		printf("8.�˳���ϵͳ\n");
		while (scanf("%d", &choice) != 1&&(choice>=0&&choice<9))
		{
			while (getchar() != '\n')
			{

			}
			
		}
		switch (choice)
		{
		case 1:add(t); break;
		case 2:
		{
			printf("��������Ҫ��ѯ�û��ֻ���\n");
			while (scanf("%d", &k) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");
				
			}
			search(t, k); break;
		}
		case 3:
		{
			printf("��������Ҫɾ���û��ֻ���\n");
			while (scanf("%d", &k) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");

			}
			dele(t, k); break;
		}
		case 4:
		{
			printf("��������Ҫ�޸��û��ֻ���\n");
			while (scanf("%d", &k) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");

			}
			rectify(t, k); break;
		}
		case 5:sort_name(t); break;
		case 6:dl(t); break;
		case 7:show(t); break;
		case 8: return;
		}
		system("pause");
		system("cls");
	}
	
}
int main(void)
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}
