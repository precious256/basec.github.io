#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
//�ṹ�壺�û�����ͬ�������͵����ݷ���һ��
//�ڴ��������壺�Կռ任ʱ�䣬�����ڴ�Ķ��ζ�ȡ�������ܼ���cpu�ô�
//1.��һ�����Կ�ʼ����0����ƫ����
//�ڶ�������Ҫ����min�������ԵĴ�С,����ģ��������������
//2.���������Լ�����ɺ�����������ƫ��
// �����е����Լ�����ɺ�ȡmin���ýṹ���е���������ֽڣ�����ģ������������
//3.��������ʼ�ڴ����������������������char a��ռһ���ֽڣ����Ǻ��int�������ݣ����Դ�ʱֻ�ܴ�4����������ʼ������˱�ռһ���ֽڵ�����ռ��4�ֽ�
//4.��ռ���ֽ�������һ�ɲ���ģ�����ͨ���޸�Ĭ������µĶ���ģ�����ﵽ�޸���ռ�ڴ��С��Ŀ�ġ�
struct student
{
	char c;//0-3  4���ֽ�
	int age;//��������ʼ�ڴ���������������� 4-7
	double score;//8-15
};
//δ�����ṹ��ʹ��,�ڴ���ʱ����������������������
//struct
//{
//	int a;
//	char c;
//}s1;
//�ṹ����Ƕ�׽ṹ��
//��δ�����Ľṹ��Ƕ�������У�c������c++���н��һ�£����������ֺ󣬴�ʱc++��Ƕ�׵Ľṹ�岻ռ�ռ�
struct teacher
{
	char c;//4
	struct tt
	{
		int a;//4
		char d;//4
	};
	int age;//4
};
int main(void)
{
	printf("%d\n", sizeof(struct student));
	//printf("%d\n", sizeof(s1));
	printf("%d\n", sizeof(struct teacher));
	system("pause");
	return EXIT_SUCCESS;
}
