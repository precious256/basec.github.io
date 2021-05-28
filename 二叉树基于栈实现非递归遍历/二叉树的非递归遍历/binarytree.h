#pragma once
#include"stack.h"
typedef int datatype;
typedef struct binary
{
	datatype val;
	struct binary* left;
	struct binary* right;
	int flag;
}binaryTree;
//树结点内存的开辟
binaryTree* my_malloc(datatype val);
//树的创建及初始化
void create(binaryTree**root);
binaryTree* create_v1(int arr[], int size, int invalid, int* index);
//树的递归遍历
void foreach(binaryTree* root);


//树的销毁
void destory(binaryTree* root);
//测试用例
void test();