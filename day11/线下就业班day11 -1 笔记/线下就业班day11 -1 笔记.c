/*****************�ַ�����ṹ��****************************
*1.�ַ�������strstr()����(kmp)�㷨
*2.strtok()����  �ַ����ضϺ���   2.�Ӳ��Ƿָ���ĵ�һ���ַ���ʼ�����ж� 3.�ڷָ��ڲ����¼��һ�������зָ��λ�ã�������ʽʵ��ƥ��
*3.strerror()����
*4.memcpy()����
*5.memset����
*6.memcmp����
*7.memmove()����//�����memcpy���������Խ���ڴ��ص����
*/
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>
//#include <Windows.h>
//void test01()
//{
//	int arr[][2] = { 1,2,3,4,5,6 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", len);
//	for (size_t i = 0; i < len; i++)
//	{
//		for (size_t j= 0; j < 2; j++)
//		{
//			printf("%d\t", *(*(arr + i ) + j));//
//		}
//	}
//}
//int main(void)
//{
//	test01();
//	system("pause");
//	return EXIT_SUCCESS;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#pragma pack(1)
struct student
{
	char a;
	int c;
	double b;

};
int main(void)
{
	struct student t1;
	/*printf("%d\n", sizeof(t1));*/
	printf("%d\n", sizeof(struct student));
	system("pause");
	return EXIT_SUCCESS;
}
