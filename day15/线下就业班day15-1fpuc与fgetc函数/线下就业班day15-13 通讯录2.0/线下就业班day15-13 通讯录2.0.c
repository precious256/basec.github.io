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
		printf("欢迎来到电话簿系统\n");
		printf("************************\n");
		printf("请选择你所需要的操作\n");
		printf("1.创建文件(在创建和清空时使用)\n");
		printf("2.录入信息\t");
		printf("3.查找用户\n");
		printf("4.删除用户\t");
		printf("5.修改用户\n");
		printf("6.按姓名排序\t");
		printf("7.输出该记录表\n");
		printf("8.销毁该记录表\n");
		printf("9.退出该系统\n");
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
			printf("请输入需要查找用户姓名\n");
			while (scanf("%s", &k) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");

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
				printf("姓名%s\n", temp1[result].name);
				printf("性别%s\n", temp1[result].sex);
				printf("年龄%d\n", temp1[result].age);
				printf("联系方式%d\n", temp1[result].pn);
				printf("地址%s\n", temp1[result].address);
			}
			else
			{
				printf("姓名为%s\t的联系人并不存在\n", k);
			}
			fclose(fp);
			free(temp1);
			temp1 = NULL;
			break;
		}
		case 4:
		{
			printf("请输入需要删除用户姓名\n");
			while (scanf("%s", &k) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");

			}
			dele_message(k); break;
		}
		case 5: 
		{
			printf("请输入需要修改用户姓名\n");
			while (scanf("%s", &k) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");

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
