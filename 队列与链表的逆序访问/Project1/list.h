#pragma once
typedef int datatype;
typedef struct list
{
	datatype val;
	struct list* next;
}Node;
typedef Node* LinkNode;
LinkNode init();
LinkNode my_malloc(datatype val);
void insert(LinkNode pheader, datatype val);
void show(LinkNode pheader);
void destory(LinkNode pheader);
