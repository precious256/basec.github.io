#include"message.h"
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<assert.h>
#include<assert.h>
#include <stdlib.h>
#include<sys/stat.h>
#pragma warning(disable:4996)
extern int size;
//��ʼ��
void init()
{
	FILE* fp = fopen("message.txt", "wb");
	assert(fp != NULL);
	fclose(fp);
	printf("�ļ������ɹ�\n");
}
//���ļ�

//��ӳ�Ա
void add()
{
	FILE* fp = fopen("message.txt", "ab");
	if (fp == NULL)
	{
		perror("");
		return;
	}
	printf("��ӭ����¼��ϵͳ\n");
	int choice = 0;
	
	
	while (1)
	{
		struct message temp;
		
		printf("����������\n");
		while (scanf("%s", &temp.name) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("������������������\n");

		}
		printf("�������Ա�\n");
		while (scanf("%s", &temp.sex) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("������������������\n");
		}
		printf("����������\n");
		while (scanf("%d", &temp.age) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("������������������\n");
		}
		printf("��������ĵ绰����\n");
		while (scanf("%d", &temp.pn) != 1)
		{
			while (getchar() != '\n')
			{

			}

			printf("������������������\n");
		}
		printf("��������ĵ�ַ\n");
		while (scanf("%s", &temp.address) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("������������������\n");
		}
		size++;
		printf("��%d���û��Ѿ������Ϣ¼��\n", size);
		Sleep(3000);
		system("cls");
	    fwrite(&temp, 1, sizeof(struct message), fp);
		 fflush(fp);
		 printf("����ѡ��¼�뻹���˳�,0�˳�\n");
		
		
		scanf("%d", &choice);
		if (choice != 0)
		{
			continue;
		}
		else
		{
			return;
		}	
	}
    fclose(fp);
}
//���ҳ�Ա
int search(const char* name)
{
	FILE* fp = fopen("message.txt", "rb");
	if (fp == NULL)
	{
		perror("");
		return;
	}
	if (size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����¼��\n");
		return NULL;
	}
	struct message* temp = (struct message*)malloc(sizeof(struct message));
	int cont = fread(temp, 1, sizeof(struct message), fp);
	int ps = 0;

	while (cont != 0)
	{
		if (strcmp(temp->name, name) == 0)
		{
			fclose(fp);
			return ps;

		}
		cont = fread(temp, 1, sizeof(struct message), fp);
		ps++;
	}
    return -1;
}
//ɾ����Ա
void dele_message(const char* name)
{
	int result = search(name);
	if (result == -1)
	{
		printf("ͨѶ¼��û��%s�����\n", name);
		return;
	}
	else
	{
		printf("����Ϊ%s����ϵ��λ�ڸ�ͨѶ��ĵ�%dλ", name, result + 1);
	}

	FILE* fp = fopen("message.txt", "rb");
	if (fp == NULL)
	{
		perror("");
		return;
	}
	struct message* arr = (struct message*)malloc(sizeof(struct message) * size);
	fread(&(*arr), 1, sizeof(struct message), fp);
	fclose(fp);
	FILE* fp1 = fopen("message.txt", "wb");
	for (size_t i = 0; i < size; i++)
	{
		if (i==result)
		{
			continue;
		}
		fwrite(&arr[i], 1, sizeof(struct message), fp1);	
	}
	size--;
	free(arr);
	arr = NULL;
	printf("ɾ���ɹ�\n");
	fclose(fp1);
}
//�޸ĳ�Ա
void rectify_message(const char* name)
{
	int result = search(name);
	if (result == -1)
	{
		printf("ͨѶ¼��û��%s�����\n", name);
		return;
	}
	else
	{
		printf("����Ϊ%s����ϵ��λ�ڸ�ͨѶ��ĵ�%dλ", name, result + 1);
	}
	FILE* fp = fopen("message.txt", "rb");
	if (fp == NULL)
	{
		perror("");
		return;
	}
	struct message* arr = (struct message*)malloc(sizeof(struct message) * size);
	fread(&(*arr), 1, sizeof(struct message), fp);
	fclose(fp);
	FILE* fp1 = fopen("message.txt", "wb");
	for (size_t i = 0; i < size; i++)
	{
		if (i == result)
		{
			printf("�û����ҵ����밴��ʾ����¼����Ϣ\n");
			printf("����������\n");
			while (scanf("%s", &arr[i].name) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");
			}
			printf("�������Ա�\n");
			while (scanf("%s", &arr[i].sex) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");
			}
			printf("����������\n");
			while (scanf("%d", &arr[i].age) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");
			}
			printf("��������ĵ绰����\n");
			while (scanf("%d", &arr[i].pn) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");
			}
			printf("��������ĵ�ַ\n");
			while (scanf("%s", &arr[i].address) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");
			}
			//break;
		}
		
		fwrite(&arr[i], 1, sizeof(struct message), fp1);

	}
	free(arr);
	arr = NULL;
	fclose(fp1);
	
	//char* oldname = "G:\\���ؿƼ�\\c����\\day15\\���¾�ҵ��day15-1fpuc��fgetc����\\���¾�ҵ��day15-13 ͨѶ¼2.0\\message.txt";
	//char* newname = "G:\\���ؿƼ�\\c����\\day15\\���¾�ҵ��day15-1fpuc��fgetc����\\���¾�ҵ��day15-13 ͨѶ¼2.0\\copy.txt";
	//int fd2 = fileno(fp);
	//fchmod(fd2, 0777);
	/*if (remove(oldname) == 0)
	{
		printf("��ɾ��\n");
	}
	else
	{
		perror("ɾ��ʧ��\n");
	}
	int ret=rename(newname, oldname);
	if (ret == 0)
	{
		printf("�޸ĳɹ�\n");
	}
	else
	{
		perror("�޸�ʧ��\n");
	}	*/
	
	printf("�޸ĳɹ�\n");
	
}
//չʾ��Ա
void show()
{
	FILE* fp = fopen("message.txt", "rb");
	if (fp == NULL)
	{
		perror("");
		return;
	}
	if (size == 0)
	{
		printf("Ŀǰ���û�\n");
		return;
	}
	printf("��ӭ�����ֿ�ϵͳ\n");
	printf("size=%d\n", size);
	struct message* arr = (struct message*)malloc(sizeof(struct message) * size);
	fread(&(*arr), 1, sizeof(struct message)*size, fp);	
	fclose(fp);
	for (size_t i = 0; i < size; i++)
	{
		printf("��%d���û���Ϣ\n", i+1);
		printf("����%s\n", arr[i].name);
		printf("�Ա�%s\n", arr[i].sex);
		printf("����%d\n", arr[i].age);
		printf("��ϵ��ʽ%d\n", arr[i].pn);
		printf("��ַ%s\n", arr[i].address);
	}
	free(arr);
	arr = NULL;

}
//�������Գ�Ա����
void sort_byname()
{
	FILE* fp = fopen("message.txt", "rb");
	if (fp == NULL)
	{
		perror("");
		return;
	}
	if (size == 0)
	{
		printf("����¼�����ݣ��ٽ�������\n");
		return;
	}
	if (size == 1)
	{
		return;
	}
	struct message* arr = (struct message*)malloc(sizeof(struct message) * size);
	struct message* temp = (struct message*)malloc(sizeof(struct message));
	fread(&(*arr), 1, sizeof(struct message)*size, fp);
	int max;
	for (size_t i = 0; i < size - 1; i++)
	{
		max = i;
		for (size_t j = i+1; j < size; j++)
		{
			if (strcmp(arr[max].name, arr[j].name) > 0)
			{
				max = j;//max=1
			}
		}
		printf("max=%d\n", max);
		if (i != max)
		{
			memcpy(temp, arr + i, sizeof(struct message));
			memcpy(arr + i, arr+ max, sizeof(struct message));
			memcpy(arr + max, temp, sizeof(struct message));
		}
	}
	free(temp);
	temp = NULL;
	fclose(fp);
	FILE* fp1 = fopen("message.txt", "wb");
	fwrite(&(*arr), 1, sizeof(struct message)*size, fp1);
	free(arr);
	arr = NULL;
	printf("����������ɹ�\n");
	fclose(fp1);
}
//�����Ա
void destory()
{
	init();
	size = 0;
}