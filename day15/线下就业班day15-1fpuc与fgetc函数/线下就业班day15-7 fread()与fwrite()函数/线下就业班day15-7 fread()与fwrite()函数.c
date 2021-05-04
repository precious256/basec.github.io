#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#define MAlloc1(type,len) ((type *)malloc(sizeof(type)*len))
//#define MALLOC(num, type)\
//	(type *)malloc(num * sizeof(type))
// fwrite
//#include <stdio.h>
//size_t fwrite(const void* ptr, size_t size, size_t nmemb, FILE * stream);
//功能：以数据块的方式给文件写入内容
//参数：
//ptr：准备写入文件数据的地址
//size： size_t 为 unsigned int类型，此参数指定写入文件内容的块数据大小
//nmemb：写入文件的块数，写入文件数据总大小为：size* nmemb
//stream：已经打开的文件指针
struct student
{
	char name[15];
	int age;
	double score;
};
void test01()
{
	struct student* temp = MAlloc1(struct student,5 );
	if (temp == NULL)
	{
		return;
	}
	FILE* fp = fopen("fwrite.txt", "wb");
	for (size_t i = 0; i < 5; i++)
	{
		printf("请输入姓名\n");
		scanf("%s", &temp[i].name);
		printf("请输入年龄\n");
		scanf("%d", &temp[i].age);
		printf("请输入成绩\n");
		scanf("%lf", &temp[i].score);
		fwrite(&temp[i], 1, sizeof(struct student), fp);
		printf("第%d 个人信息录入完成\n", i + 1);
	}
	free(temp);
	temp = NULL;
	fclose(fp);
	
	
}
void test02()
{
	FILE* fp = fopen("fwrite.txt", "rb");
	if (fp == NULL)
	{
		return;
	}
	int k = 0;
	struct student temp[5];
	int cont;
	cont = fread(&temp, 1, sizeof(struct student)*5, fp);
	for (int i = 0; i < 5; i++)
	{
		//cont = fread( &temp[i] ,1,sizeof(struct student),fp );
		printf("cont =%d\n",cont);
		printf("%d %s %lf\n", temp[i].age, temp[i].name,temp[i].score);

	}
	//int cont = fread(&temp, 1, sizeof(struct student)*5, fp);
	//int i = 1;
	//while (cont != 0)
	//{
	//	printf("第%d个学生信息\n", i++);
	//	printf("姓名%s\n", temp[k].name);
	//	printf("年龄%d\n", temp[k].age);
	//	printf("成绩%lf\n", temp[k].score);
	//	//memset(temp, 0, sizeof(struct student));
	//	k = k + 1;
	//	
	//}
	fclose(fp);
}
int main(void)
{
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
