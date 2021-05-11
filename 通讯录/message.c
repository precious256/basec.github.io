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
		int n = fwrite(&temp, 1, sizeof(struct message), fp);
		fflush(fp);
		printf("%d\n", n);
		if (n > 0)
		{
			printf("请您选择录入还是退出,0退出\n");
		}

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


	//fseek(fp, 0, SEEK_SET);
	fclose(fp);
}
//查找成员
struct message* search(const char* name)
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
	printf("cont=%d\n", cont);
	while (cont != 0)
	{
		if (strcmp(temp->name, name) == 0)
		{
			break;
		}
		cont = fread(temp, 1, sizeof(struct message), fp);
	}
	if (cont == 0)
	{
		printf("查无此人\n");
		return NULL;
	}
	fclose(fp);
	printf("找到了\n");
	return temp;

}
//删除成员
void dele_message(const char* name)
{
	struct message* p = search(name);
	if (p == NULL)
	{
		return;
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
		if (strcmp(arr[i].name, name) == 0)
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
	struct message* p = search(name);
	if (p == NULL)
	{

		return;
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
	FILE* fp1 = fopen("copy.txt", "wb");
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(arr[i].name, name) == 0)
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

	char* oldname = "G:\\比特科技\\数据结构\\通讯录\\message.txt";
	char* newname = "G:\\比特科技\\数据结构\\通讯录\\copy.txt";
	/*int fd2 = fileno(fp);
	fchmod(fd2, 0777);*/
	if (remove(oldname) == 0)
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
	}	

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
	fread(&(*arr), 1, sizeof(struct message) * size, fp);
	fclose(fp);
	for (size_t i = 0; i < size; i++)
	{
		printf("第%d个用户信息\n", i + 1);
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
	//char* temp =(char*) malloc(sizeof(struct message));
	fread(&(*arr), 1, sizeof(struct message) * size, fp);
	/*for (size_t i = 0; i < size; i++)
	{
		printf("姓名%s\n", arr[i].name);
		printf("性别%s\n", arr[i].sex);
		printf("年龄%d\n", arr[i].age);
		printf("电话号码%d\n", arr[i].pn);
		printf("地址%s\n", arr[i].address);
	}*/

	int max;
	for (size_t i = 0; i < size - 1; i++)
	{
		max = i;
		for (size_t j = i + 1; j < size; j++)
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
			memcpy(arr + i, arr + max, sizeof(struct message));
			memcpy(arr + max, temp, sizeof(struct message));
			/*memcpy(temp, (char*)arr+ i*sizeof(struct message), sizeof(struct message));
			memcpy((char*)arr + i*sizeof(struct message) ,(char*)arr + max*sizeof(struct message) , sizeof(struct message));
			memcpy((char*)arr + max*sizeof(struct message) , temp, sizeof(struct message));	*/
		}
	}
	free(temp);
	temp = NULL;

	fclose(fp);
	FILE* fp1 = fopen("message.txt", "wb");

	fwrite(&(*arr), 1, sizeof(struct message) * size, fp1);

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