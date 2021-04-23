//通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
//添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人
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
struct message* init()//初始化
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
		printf("该空间尚未开辟\n");
		return;
	}
	if (number >= 1000)
	{
		printf("内存已满，无法写入\n");
	}
	
	int choice = 0;
	while (1)
	{
		printf("请输入姓名\n");
		while (scanf("%s", &t1->name) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("输入有误，请重新输入\n");
			
		}
		printf("请输入性别\n");
		while (scanf("%s", &t1->sex) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("输入有误，请重新输入\n");
		}
		printf("请输入年龄\n");
		while (scanf("%d", &t1->age) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("输入有误，请重新输入\n");
		}
		printf("请输入你的电话号码\n");
		while (scanf("%d", &t1->pn) != 1)
		{
			while (getchar() != '\n')
			{

			}
			
			printf("输入有误，请重新输入\n");
		}
		printf("请输入你的地址\n");
		while (scanf("%s", &t1->address) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("输入有误，请重新输入\n");
		}
		number++;
		printf("第%d个用户已经完成信息录入\n", number);
		t1++;
		printf("请您选择录入还是退出,0退出\n");
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
		printf("该空间尚未录入数据\n");
		return;
	}
	for (size_t i = 0; i < number; i++)
	{
		printf("姓名%s\n", t1->name);
		printf("性别%s\n", t1->sex);
		printf("年龄%d\n", t1->age);
		printf("联系方式%d\n", t1->pn);
		printf("地址%s\n", t1->address);
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
		printf("该空间尚未录入数据\n");
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
		printf("该空间尚未录入数据\n");
		return;
	}
	struct message* temp = p;
	for (size_t i = 0; i < number; i++)
	{
		if (temp->pn - n == 0)
		{
			printf("已找到\n");
			printf("姓名%s\n", temp->name);
			printf("性别%s\n", temp->sex);
			printf("年龄%d\n", temp->age);
			printf("联系方式%d\n", temp->pn);
			printf("地址%s\n", temp->address);
			break;
		}
		temp++;
		if (i+1 == number)
		{
			printf("未找到\n");
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
		printf("该空间尚未录入数据\n");
		return;
	}
	struct message* temp = p;
	for (size_t i = 0; i < number; i++)
	{
		if (temp->pn - n == 0)
			
		{
			printf("用户已找到，请按提示重新录入信息\n");
			printf("请输入姓名\n");
			while (scanf("%s", &temp->name) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");
			}
			printf("请输入性别\n");
			while (scanf("%s", &temp->sex) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");
			}
			printf("请输入你的电话号码\n");
			while (scanf("%d", &temp->pn) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");
			}
			printf("请输入你的地址\n");
			while (scanf("%s", &temp->address) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");
			}
			break;
		}
		
		temp++;
		if (i+1 == number)
		{
			printf("未找到该用户\n");
		}
	}

}
void dele(struct message* p,int n)
{
	assert(p != NULL);
	if (number == 0)
	{
		printf("该空间尚未录入数据\n");
		return;
	}
	struct message* temp = p;
	for (size_t i = 0; i < number; i++)
	{
		if (temp->pn - n == 0)
		{
			printf("该用户已删除\n");
			for (size_t j = i; j < number; j++)
			{
				temp = temp+1;
				temp++;
			}
			number--;
		}
		else if (i + 1 == number)
		{
			printf("未找到\n");
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
		printf("欢迎来到电话簿系统\n");
		printf("************************\n");
		printf("请选择你所需要的操作\n");
		printf("1.录入信息\t");
		printf("2.查找用户\n");
		printf("3.删除用户\t");
		printf("4.修改用户\n");
		printf("5.按姓名排序\t");
		printf("6.销毁该记录表\n");
		printf("7.输出该记录表\n");
		printf("8.退出该系统\n");
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
			printf("请输入需要查询用户手机号\n");
			while (scanf("%d", &k) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");
				
			}
			search(t, k); break;
		}
		case 3:
		{
			printf("请输入需要删除用户手机号\n");
			while (scanf("%d", &k) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");

			}
			dele(t, k); break;
		}
		case 4:
		{
			printf("请输入需要修改用户手机号\n");
			while (scanf("%d", &k) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");

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
