#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include<assert.h>
#include"student.h"
void test01()
{
	LinkList pheader = init();
	Link_insert(pheader);
	Link_show(pheader);
	Link_insert(pheader);
	Link_show(pheader);
	Link_insertbyheade(pheader, 10);
	Link_show(pheader);
	Link_insertbypos(pheader, 1, 20);
	Link_show(pheader);
	Getelem(pheader, 3);
	Dele_pos(pheader, 3);
	Link_show(pheader);
	Dele_val(pheader, 3);
	Link_show(pheader);
	reverse_Linklist(pheader);
	Link_show(pheader);
	LinkList p = find_middle(pheader);
	printf("中间结点为%d\n", p->age);
	LinkList middle=find_endnumber(pheader, 3);
	printf("倒数第三个元素为%d\n", middle->age);
	Clean(pheader);
	Link_show(pheader);
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
