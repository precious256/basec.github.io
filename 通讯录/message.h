#pragma once
#include<stdio.h>
struct message
{
	char address[20];
	char name[12];
	char sex[2];
	int age;
	int pn;

};
static int size = 0;
//初始化
void init();
//打开文件
//添加成员
void add();
//查找成员
struct message* search(const char* name);
//删除成员
void dele_message(const char* name);
//修改成员
void rectify_message(const char* name);
//展示成员
void show();
//按姓名对成员排序
void sort_byname();
//情况成员
void destory();

