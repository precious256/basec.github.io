#pragma once
typedef int eletype;
struct dlist
{
	eletype val;
	struct dlist* prev;//记录的是结点的前一个元素
	struct dlist* next;//记录的是结点的后一个元素
};
typedef struct dlist* LinkNode;
typedef struct dlist Node;

//此处写的是带头结点
//初始化头结点
LinkNode init();
//执行的是开辟内存函数
LinkNode my_malloc(eletype data);
//执行的是头插操作
void pushfront(LinkNode header, eletype data);
//执行的是头删的操作
void popfront(LinkNode pheader);
//执行的是尾插操作
void pushback(LinkNode pheader, eletype data);
//执行的是尾删的操作
void popback(LinkNode pheader);
//执行的是任意元素的删除
void delete_num(LinkNode pheader);
//执行的是任意元素的插入
void insert_num(LinkNode pheader, eletype data);
//链表的有效元素个数的统计
int cal_num(LinkNode pheader);
//查找某一元素首次出现的结点
LinkNode search(LinkNode pheader,eletype data);
//双向循环链表的修改
void rectify(LinkNode p, eletype olddata, eletype newdata);
//链表的清空
void clean(LinkNode pheader);
//链表的销毁
void destory(LinkNode pheader);
//链表的打印
void print(LinkNode pheader);




