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
			printf("请输入需要查找用户姓名\n");
			while (scanf("%s", &k) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");

			}
			struct message* temp = search(k);
			if (temp != NULL)
			{
				printf("姓名%s\n", temp->name);
				printf("性别%s\n", temp->sex);
				printf("年龄%d\n", temp->age);
				printf("联系方式%d\n", temp->pn);
				printf("地址%s\n", temp->address);
			}
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
