#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
//����ԭ�� void*malloc(size_t);
//��Ϊ����ֵδvoid*���ͣ������ڽ���malloc()����ֵʱӦ�ü���ǿת���ͣ���c����������ν�����ǻ���Ӧ���ֺ�һ���ϰ��
//malloc()���ٵĿռ䲻��������ٵĿռ�����ݽ��г�ʼ�������ٳ��������ݾ������ֵ
//malloc()������free()һ����֣����ܲ��ͷſ��ٳ��Ŀռ䣬����������������俪�ٵĿռ�Ҳ�����ų������һ���ͷ��ˡ�
//free()������費��Ҫ��ԭָ���ÿգ�ָ��NULLֵ����
//��Ҫ��1.���Ա����û�����ʹ���ͷŵĿռ� 2.��������ͷŴ����Ĵ��󣬽�ͬһ�ռ��ͷ����Σ���Ϊfree(NULL)ֵ�ǲ��ᱨ���
struct student
{
	int id;
	char name[15];
	int age;
	double score;
};
void test01()
{
	struct student* t1 = (struct student*)malloc(sizeof(struct student));
	//�жϿ��ٳɹ������ַ���
	//1.����if���
	if (t1 == NULL)
	{
		perror(" ");//��ӡ������Ϣ
		return;
	}
	//2.���ö��Ժ���
	assert(t1 != NULL);
	t1->age = 18;
	t1->id = 18060102;
	strcpy(t1->name, "����");
	t1->score = 90.0;
	printf("����%s\tѧ��%d\t����%d\t�ɼ�%f\n", t1->name, t1->id, t1->age, t1->score);
	free(t1);
	t1 = NULL;
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
