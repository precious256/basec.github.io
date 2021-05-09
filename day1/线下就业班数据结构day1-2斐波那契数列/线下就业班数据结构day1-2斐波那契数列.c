#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
int fab(int n)
{
	// 0 1 1 2 3
	if (n < 3)
	{
		return 1;
	}
	static int i = 2;
	return i + fab(n - 1);
}
void test01()
{

}
int main(void)
{

	system("pause");
	return EXIT_SUCCESS;
}
