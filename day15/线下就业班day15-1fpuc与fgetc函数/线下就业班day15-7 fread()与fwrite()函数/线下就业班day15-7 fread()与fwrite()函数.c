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
//���ܣ������ݿ�ķ�ʽ���ļ�д������
//������
//ptr��׼��д���ļ����ݵĵ�ַ
//size�� size_t Ϊ unsigned int���ͣ��˲���ָ��д���ļ����ݵĿ����ݴ�С
//nmemb��д���ļ��Ŀ�����д���ļ������ܴ�СΪ��size* nmemb
//stream���Ѿ��򿪵��ļ�ָ��
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
		printf("����������\n");
		scanf("%s", &temp[i].name);
		printf("����������\n");
		scanf("%d", &temp[i].age);
		printf("������ɼ�\n");
		scanf("%lf", &temp[i].score);
		fwrite(&temp[i], 1, sizeof(struct student), fp);
		printf("��%d ������Ϣ¼�����\n", i + 1);
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
	//	printf("��%d��ѧ����Ϣ\n", i++);
	//	printf("����%s\n", temp[k].name);
	//	printf("����%d\n", temp[k].age);
	//	printf("�ɼ�%lf\n", temp[k].score);
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
