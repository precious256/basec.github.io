#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include"Dlist.h"
void test()
{
	LinkNode pheader = init();
	pushfront(pheader, 1);
	pushfront(pheader, 2);
	pushfront(pheader, 3);
	pushfront(pheader, 4);
	pushfront(pheader, 5);
	
	print(pheader);
	rectify(pheader, 5, 6);
	print(pheader);
	printf("当前元素个数为%d\n", cal_num(pheader));
	LinkNode find = search(pheader, 4);
	printf("查找结果为%d\n", find->val);
	popfront(pheader);
	popfront(pheader);
	popfront(pheader);
	print(pheader);
	pushback(pheader, 6);
	pushback(pheader, 7);
	print(pheader);
	popback(pheader);
	popback(pheader);
	popback(pheader);
	print(pheader);
	clean(pheader);
	print(pheader);
}
int main(void)
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}
