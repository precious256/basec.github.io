#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
//void* memcpy(void* destin, void* source, unsigned n);//����ԭ��
// ���ʣ����ֽڽ��п���
//���⣺������������ڴ��ص������󣬹�������д��İ취��
void* my_memcpy(void* destin, void* source, int n)
{
	n = (int)n;
	assert(destin != NULL && source != NULL);
	char* pdes = (char*)destin;
	const char* psrc = (const char*)source;
	//û�з����ڴ��ص�������
	if (pdes > psrc || pdes > psrc + n)
	{
		while (n-- != 0)
		{
			*pdes++ = *psrc++;
		}
	}
	//�������ڴ��ص������ʱ����Ŀ��ռ��ɺ���ǰ���п������������ڴ渲�ǵ����
	else
	{
		pdes += n - 1;
		psrc += n - 1;
		while (n-- != 0)
		{
			*pdes = *psrc;
		}
		
	}
	return destin;
}

void test01()
{
	char buf[12] = "hello";
	char buf1[10] = "world";
	
	printf("����ǰ%s\n", buf);
	my_memcpy(buf, buf1, 3);

	printf("���ƺ�%s\n", buf);
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
