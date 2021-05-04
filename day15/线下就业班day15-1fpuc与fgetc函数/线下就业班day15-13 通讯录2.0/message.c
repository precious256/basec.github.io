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
//初始化
void init()
{
	FILE* fp = fopen("message.txt", "wb");
	assert(fp != NULL);
	fclose(fp);
	printf("文件创建成功\n");
}
//打开文件

//添加成员
void add()
{
	FILE* fp = fopen("message.txt", "ab");
	if (fp == NULL)
	{
		perror("");
		return;
	}
	printf("欢迎来到录入系统\n");
	int choice = 0;
	
	
	while (1)
	{
		struct message temp;
		
		printf("请输入姓名\n");
		while (scanf("%s", &temp.name) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("输入有误，请重新输入\n");

		}
		printf("请输入性别\n");
		while (scanf("%s", &temp.sex) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("输入有误，请重新输入\n");
		}
		printf("请输入年龄\n");
		while (scanf("%d", &temp.age) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("输入有误，请重新输入\n");
		}
		printf("请输入你的电话号码\n");
		while (scanf("%d", &temp.pn) != 1)
		{
			while (getchar() != '\n')
			{

			}

			printf("输入有误，请重新输入\n");
		}
		printf("请输入你的地址\n");
		while (scanf("%s", &temp.address) != 1)
		{
			while (getchar() != '\n')
			{

			}
			printf("输入有误，请重新输入\n");
		}
		size++;
		printf("第%d个用户已经完成信息录入\n", size);
		Sleep(3000);
		system("cls");
	    fwrite(&temp, 1, sizeof(struct message), fp);
		 fflush(fp);
		 printf("请您选择录入还是退出,0退出\n");
		
		
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
//查找成员
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
		printf("通讯录为空，请先录入\n");
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
//删除成员
void dele_message(const char* name)
{
	int result = search(name);
	if (result == -1)
	{
		printf("通讯录中没有%s这个人\n", name);
		return;
	}
	else
	{
		printf("姓名为%s的联系人位于该通讯表的第%d位", name, result + 1);
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
	printf("删除成功\n");
	fclose(fp1);
}
//修改成员
void rectify_message(const char* name)
{
	int result = search(name);
	if (result == -1)
	{
		printf("通讯录中没有%s这个人\n", name);
		return;
	}
	else
	{
		printf("姓名为%s的联系人位于该通讯表的第%d位", name, result + 1);
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
			printf("用户已找到，请按提示重新录入信息\n");
			printf("请输入姓名\n");
			while (scanf("%s", &arr[i].name) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");
			}
			printf("请输入性别\n");
			while (scanf("%s", &arr[i].sex) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");
			}
			printf("请输入年龄\n");
			while (scanf("%d", &arr[i].age) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");
			}
			printf("请输入你的电话号码\n");
			while (scanf("%d", &arr[i].pn) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");
			}
			printf("请输入你的地址\n");
			while (scanf("%s", &arr[i].address) != 1)
			{
				while (getchar() != '\n')
				{

				}
				printf("输入有误，请重新输入\n");
			}
			//break;
		}
		
		fwrite(&arr[i], 1, sizeof(struct message), fp1);

	}
	free(arr);
	arr = NULL;
	fclose(fp1);
	
	//char* oldname = "G:\\比特科技\\c语言\\day15\\线下就业班day15-1fpuc与fgetc函数\\线下就业班day15-13 通讯录2.0\\message.txt";
	//char* newname = "G:\\比特科技\\c语言\\day15\\线下就业班day15-1fpuc与fgetc函数\\线下就业班day15-13 通讯录2.0\\copy.txt";
	//int fd2 = fileno(fp);
	//fchmod(fd2, 0777);
	/*if (remove(oldname) == 0)
	{
		printf("已删除\n");
	}
	else
	{
		perror("删除失败\n");
	}
	int ret=rename(newname, oldname);
	if (ret == 0)
	{
		printf("修改成功\n");
	}
	else
	{
		perror("修改失败\n");
	}	*/
	
	printf("修改成功\n");
	
}
//展示成员
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
		printf("目前无用户\n");
		return;
	}
	printf("欢迎来到仓库系统\n");
	printf("size=%d\n", size);
	struct message* arr = (struct message*)malloc(sizeof(struct message) * size);
	fread(&(*arr), 1, sizeof(struct message)*size, fp);	
	fclose(fp);
	for (size_t i = 0; i < size; i++)
	{
		printf("第%d个用户信息\n", i+1);
		printf("姓名%s\n", arr[i].name);
		printf("性别%s\n", arr[i].sex);
		printf("年龄%d\n", arr[i].age);
		printf("联系方式%d\n", arr[i].pn);
		printf("地址%s\n", arr[i].address);
	}
	free(arr);
	arr = NULL;

}
//按姓名对成员排序
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
		printf("请先录入数据，再进行排序\n");
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
	printf("按名字排序成功\n");
	fclose(fp1);
}
//清理成员
void destory()
{
	init();
	size = 0;
}