#ifndef __STUDENT_H__
#define __STUDENT_H__
//#include<stdio.h>

typedef struct student
{
	int age;
	
	struct student* next;

}NODE;
typedef NODE* LinkList;
//创立一个头结点
LinkList init();
//尾插
void Link_insert(LinkList pheader);
//头插
void Link_insertbyheade(LinkList pheader,int data);
//按位置插入
void Link_insertbypos(LinkList pheader,int pos,int data);
//打印函数
void Link_show(LinkList pheader);
//获取某一位置的元素
int Getelem(LinkList pheader, int pos);
//删除某一位置的值
void Dele_pos(LinkList pheader, int pos);
//删除链表中特定元素的值
void Dele_val(LinkList pheader, int data);
//寻找中间结点
LinkList find_middle(LinkList pheader);
//寻找倒数第几个的元素
LinkList find_endnumber(LinkList pheader, int k);
void reverse_Linklist(LinkList pheader);
//清空链表
void Clean(LinkList pheader);
//销毁链表
void Destory(LinkList pheader);
#endif 

