#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include"message.h"

int main(void)
{

	int choice;
	char  k[15];
	while (1)
	{
		printf("************************\n");
		printf("��ӭ�����绰��ϵͳ\n");
		printf("************************\n");
		printf("��ѡ��������Ҫ�Ĳ���\n");
		printf("1.�����ļ�(�ڴ��������ʱʹ��)\n");
		printf("2.¼����Ϣ\t");
		printf("3.�����û�\n");
		printf("4.ɾ���û�\t");
		printf("5.�޸��û�\n");
		printf("6.����������\t");
		printf("7.����ü�¼��\n");
		printf("8.���ٸü�¼��\n");
		printf("9.�˳���ϵͳ\n");
		while (scanf("%d", &choice) != 1 && (choice >= 0 && choice < 9))
		{
			while (getchar() != '\n')
			{

			}

		}
		switch (choice)
		{
		case 1:init(); break;
		case 2:add(); break;
		
		case 3:
		{
			printf("size=%d\n", size);
			printf("��������Ҫ�����û�����\n");
			while (scanf("%s", &k) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");

			}
			struct message* temp = (struct message*)malloc(sizeof(struct message) );
			FILE* fp = fopen("message.txt", "rb");
			int size_message = 0;
			int cont = fread(&(*temp), 1, sizeof(struct message), fp);
			while (cont != 0)
			{
				size_message++;
				cont = fread(&(*temp), 1, sizeof(struct message), fp);
			}
			free(temp);
			temp = NULL;
			fseek(fp, 0, SEEK_SET);
			struct message* temp1 = (struct message*)malloc(sizeof(struct message)*size_message);
			fread(&(*temp1), 1, sizeof(struct message)*size_message, fp);
			int result = search(k);
			if (result!= -1)
			{
				printf("����%s\n", temp1[result].name);
				printf("�Ա�%s\n", temp1[result].sex);
				printf("����%d\n", temp1[result].age);
				printf("��ϵ��ʽ%d\n", temp1[result].pn);
				printf("��ַ%s\n", temp1[result].address);
			}
			else
			{
				printf("����Ϊ%s\t����ϵ�˲�������\n", k);
			}
			fclose(fp);
			free(temp1);
			temp1 = NULL;
			break;
		}
		case 4:
		{
			printf("��������Ҫɾ���û�����\n");
			while (scanf("%s", &k) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");

			}
			dele_message(k); break;
		}
		case 5: 
		{
			printf("��������Ҫ�޸��û�����\n");
			while (scanf("%s", &k) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("������������������\n");

			}
			rectify_message(k); break;
		}
		case 6:sort_byname(); break;
		case 7:show(); break;
		case 8: destory(); break;
		case 9:return;
		}
		system("pause");
		system("cls");
	}


	system("pause");
	return EXIT_SUCCESS;
}
