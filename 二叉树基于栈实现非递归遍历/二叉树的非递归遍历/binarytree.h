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
//������ڴ�Ŀ���
binaryTree* my_malloc(datatype val);
//���Ĵ�������ʼ��
void create(binaryTree**root);
binaryTree* create_v1(int arr[], int size, int invalid, int* index);
//���ĵݹ����
void foreach(binaryTree* root);


//��������
void destory(binaryTree* root);
//��������
void test();