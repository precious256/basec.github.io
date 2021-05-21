#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include"list.h"
void test_list()
{
	LinkNode pheader = init();
	insert(pheader, 5);
	insert(pheader, 4);
	insert(pheader, 3);
	insert(pheader, 2);
	insert(pheader, 1);
	Stack s;
	init1(&s);
	show(pheader->next, &s);
	
	
	stack_show(&s);
	destory(pheader);
}
int main(void)
{
	test_list();
	system("pause");
	return EXIT_SUCCESS;
}
