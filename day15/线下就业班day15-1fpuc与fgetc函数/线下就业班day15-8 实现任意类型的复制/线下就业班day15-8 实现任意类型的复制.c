#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>

int main(int argv,char *argc[])
{
	FILE* fp = fopen(argc[1], "rb");
	FILE* fp1 = fopen(argc[2], "wb");
	assert(fp1 != NULL && fp != NULL);
	char buf[128];
	int cont = fread(buf, 1, sizeof(buf), fp);
	while (cont != 0)
	{
		fwrite(buf, 1, sizeof(buf), fp1);
		int cont = fread(buf, 1, sizeof(buf), fp);
	}
	printf("¿½±´Íê³É\n");
	fclose(fp);
	fclose(fp1);
	system("pause");
	return EXIT_SUCCESS;
}
