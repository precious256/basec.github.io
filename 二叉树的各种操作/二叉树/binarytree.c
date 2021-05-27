
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include"binarytree.h"
#include"queue.h"

//���Ĵ�������ʼ��
void create(binaryTree**root)
{
	datatype val;
	scanf("%d", &val);
	if (val == -1)
	{
		*root = NULL;
	}
	else
	{
		*root = (binaryTree*)malloc(sizeof(binaryTree));
		if (*root == NULL)
		{
			printf("����ʧ��,����\n");
			return;
		}
		(*root)->val = val;
		create(&(*root)->left);
		create(&(*root)->right);
	}
}
//���ĵݹ����
void foreach(binaryTree* root)
{
	if (root == NULL)
	{
		return;
	}
	//����
	printf("%d\t", root->val);
	foreach(root->left);
	foreach(root->right);
	////����
	//foreach(root->left);
	//printf("%d\t", root->val);
	//foreach(root->right);
	//�������
	/*foreach(root->left);
	foreach(root->right);
	printf("%d\t", root->val);*/
}
//����ĳ��Ԫ��
binaryTree* find(binaryTree* root,datatype val)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == val)
	{
		return root;
	}
	find(root->left, val);
	find(root->right, val);
}
//���Ĳ������
void sequence_foreach(binaryTree* root)
{
	Queue p;
	if (root == NULL)
	{
		return;
	}
	init(&p);
	push_queue(&p, root);
	while (!is_empty(&p))
	{
		binaryTree* cur = return_top(&p);
		printf("%d\t", cur->val);
		if (cur->left != NULL)
		{
			push_queue(&p, cur->left);
		}
		if (cur->right != NULL)
		{
			push_queue(&p, cur->right);
		}
		pop_queue(&p);
	}
	destory1(&p);
	

}
//���ؽ������
int Node_size(binaryTree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + Node_size(root->left) + Node_size(root->right);
}
//����Ҷ�ӽ������
int leaf_size(binaryTree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return leaf_size(root->left) + leaf_size(root->right);
}
//�������ĸ߶�
int height_tree(binaryTree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return height_tree(root->left) > height_tree(root->right) ? height_tree(root->left) + 1 : height_tree(root->right) + 1;
}
//��������ĳһ��Ľ�����
int level_size(binaryTree* root, int k)
{
	if (root == NULL || k <= 0)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return level_size(root->left, k - 1) + level_size(root->right, k - 1);
}
//���Ŀ���
binaryTree* copy(binaryTree* root)
{
	if (root == NULL)
	{
		return NULL;

	}
	binaryTree* left = copy(root->left);
	binaryTree* right = copy(root->right);
	binaryTree* newnode = (binaryTree*)malloc(sizeof(binaryTree));
	newnode->left = left;
	newnode->right = right;
	return newnode;
}

//��������
void destory(binaryTree* root)
{
	if (root == NULL)
	{
		return;
	}
	destory(root->left);
	destory(root->right);
	free(root);
}
//��������
void test()
{
	binaryTree* root;
	create(&root);
	foreach(root);
	printf("\n");
	printf("���Ľ����%d��\n",Node_size(root));
	printf("���ĸ߶�Ϊ%d\n", height_tree(root));
	printf("����Ҷ�ӽ����%d\n", leaf_size(root));
	printf("��k�㹲��%d�����\n", level_size(root,2));
	printf("��������Ľ��Ϊ\n");
	sequence_foreach(root);
	destory(root);

}