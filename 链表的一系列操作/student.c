#include"student.h"
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
LinkList init()
{
	NODE* pheader = (LinkList)malloc(sizeof(NODE));
	if (pheader == NULL)
	{
		return;
	}
	//头结点只起到一个标识作用，方便之后调用，并未存在有效数据，当然也可以设置为有效数据
	pheader->age = -1;
	pheader->next = NULL;
	return pheader;

}
//尾插
void Link_insert(LinkList pheader)
{
	if (pheader == NULL)
	{
		return;
	}
	LinkList pre, pcur;
	int temp;
	pre = pheader;
	pcur = pheader->next;
	while (pcur != NULL)
	{
		pre = pcur;//用来记录的是NULL值前面的第一个有效位
		pcur = pcur->next;
	}
	while (1)
	{
		printf("请输入年龄，-1退出\n");
		scanf("%d", &temp);
		if (temp == -1)
		{
			break;
		}
		LinkList newnode = (LinkList)malloc(sizeof(NODE));
		newnode->age = temp;
		newnode->next = NULL;
		pre->next = newnode;
		pre = newnode;
		

	}
	printf("尾插已完成\n");
}
//打印函数
void Link_show(LinkList pheader)
{
	if (pheader == NULL)
	{
		return;
	}
	LinkList pcur = pheader->next;
	
	
	while (pcur != NULL)
	{
		printf("年龄%d\n", pcur->age);
		pcur = pcur->next;
	}
	printf("打印完成\n");
}
//头插
void Link_insertbyheade(LinkList pheader, int data)
{
	if (pheader == NULL)
	{
		return;
	}
	LinkList newnode = (LinkList)malloc(sizeof(NODE));
	newnode->age = data;
	newnode->next = pheader->next;
	pheader->next = newnode;
}
//按位置插入
void Link_insertbypos(LinkList pheader, int pos, int data)
{
	if (pheader == NULL)
	{
		return;
	}
	int j = 1;
	LinkList pcur = pheader->next;
	LinkList pre = pheader;
	while (j < pos && pcur)
	{
		pre = pcur;//为了避免插入位置不合理，采取强制插入所设立的保护结点
		pcur = pcur->next;
		++j;
	}
	//插入位置不合理，当插入位置小于1时，此时采取头插插入，否则采取尾插
	//应对插入位置不合理情况的尾插
	if (pcur == NULL)
	{
		LinkList newnode = (LinkList)malloc(sizeof(NODE));
		newnode->age = data;
		newnode->next = NULL;
		pre->next = newnode;
	}
	//既可以执行正常插入，也可执行当位置小于1时的头插
	else
	{
		LinkList newnode = (LinkList)malloc(sizeof(NODE));
		newnode->age = data;
		newnode->next = pre->next;
		pre->next = newnode;
	}

}
//获取某一位置的元素
int Getelem(LinkList pheader, int pos)
{
	if (pheader == NULL)
	{
		return;
	}
	int j = 1;
	LinkList pcur = pheader->next;
	while (pcur != NULL && j < pos)
	{
		pcur = pcur->next;
		++j;
	}
	if (pcur == NULL)
	{
		printf("位置为%d的元素不存在\n", pos);
	}
	else
	{
		printf("位置为%d的元素的值为%d\n", pos, pcur->age);
	}
}
//删除某一位置的值
void Dele_pos(LinkList pheader, int pos)
{
	if (pheader == NULL)
	{
		return;
	}
	int j = 1;
	LinkList pcur = pheader;
	while (pcur != NULL && j < pos)
	{
		pcur = pcur->next;
		++j;
	}
	if (pcur == NULL)
	{
		printf("位置为%d的元素不存在\n", pos);
	}
	else
	{
		LinkList del = pcur->next;
		pcur->next = del->next;
		free(del);

	}
}
//删除链表中特定元素的值
void Dele_val(LinkList pheader, int data)
{
	if (pheader == NULL)
	{
		return;
	}
	LinkList pre, pcur;
	pre = pheader;
	pcur = pheader->next;
	while (pcur)
	{
		if (pcur->age == data)
		{
			LinkList pnext = pcur->next;
			free(pcur);
			pre->next = pnext;
			pcur = pnext;


		}
		else
		{
		pre = pcur;
		pcur = pcur->next;
		}
		
	}
}
//寻找中间结点
LinkList find_middle(LinkList pheader)
{
	//解法：快慢指针的办法
	//做法：先定义一个fast(快)和slow(慢)结点
	//首先都让它指向头结点，然后slow每次指向下一个，fast跨指向每次比fast多走一个
	if (pheader == NULL)
	{
		return;
	}
	LinkList fast, slow;
	//因为我的头结点并未使用有效值,所以此时指向的是头结点的下一个结点
	fast = pheader->next;
	slow = pheader->next;
	while (fast != NULL&&fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//原理：因为快指针每次比慢指针多走一个，所以当快指针走到结尾时，此时恰好慢指针指向链表的中间结点。
	return slow;
}
//寻找倒数第几个的元素
LinkList find_endnumber(LinkList pheader, int k)
{
	if (pheader == NULL)
	{
		return;
	}
	LinkList fast,slow ;
	slow = pheader->next;
	fast = pheader->next;
	while (k--)
	{
		if (fast)
		{
			fast = fast->next;
		}
		else
		{
			return NULL;
		}

	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
void reverse_Linklist(LinkList pheader)
{
	if (pheader == NULL)
	{
		return;
	}
	//三指针法：pre记录操作链表元素前一结点 pcur记录的是当前操作结点 pnext 记录下一结点
	LinkList pre, pcur, pnext;
	pre = NULL;
	pnext = NULL;
	pcur = pheader->next;
	while (pcur)
	{
		pnext = pcur->next;
		pcur->next = pre;
		pre = pcur;
		pcur = pnext;
	}
	pheader->next = pre;
}
//清空链表,与销毁的区别是此时保留头结点，程序可利用头结点接着写入
void Clean(LinkList pheader)
{
	if (pheader == NULL)
	{
		return;
	}
	LinkList pcur = pheader->next;
	while (pcur)
	{
		LinkList pnext = pcur->next;
		free(pcur);
		pcur = pnext;
	}
	pheader->next = NULL;
}
//销毁链表,将链表仅剩的头结点删除，此时在想写入，就只能重新开辟
void Destory(LinkList pheader)
{
	Clean(pheader);//在销毁前必须先进行链表清空，否则会造成内存泄露的情况
	if (pheader == NULL)
	{
		return;
	}
	free(pheader);
	pheader = NULL;
}