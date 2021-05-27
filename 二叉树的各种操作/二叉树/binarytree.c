
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include"binarytree.h"
#include"queue.h"

//树的创建及初始化
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
			printf("创建失败,返回\n");
			return;
		}
		(*root)->val = val;
		create(&(*root)->left);
		create(&(*root)->right);
	}
}
//树的递归遍历
void foreach(binaryTree* root)
{
	if (root == NULL)
	{
		return;
	}
	//先序
	printf("%d\t", root->val);
	foreach(root->left);
	foreach(root->right);
	////中序
	//foreach(root->left);
	//printf("%d\t", root->val);
	//foreach(root->right);
	//后序遍历
	/*foreach(root->left);
	foreach(root->right);
	printf("%d\t", root->val);*/
}
//查找某个元素
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
//树的层序遍历
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
//返回结点总数
int Node_size(binaryTree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + Node_size(root->left) + Node_size(root->right);
}
//返回叶子结点总数
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
//返回树的高度
int height_tree(binaryTree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return height_tree(root->left) > height_tree(root->right) ? height_tree(root->left) + 1 : height_tree(root->right) + 1;
}
//返回树中某一层的结点个数
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
//树的拷贝
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

//树的销毁
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
//测试用例
void test()
{
	binaryTree* root;
	create(&root);
	foreach(root);
	printf("\n");
	printf("树的结点有%d个\n",Node_size(root));
	printf("树的高度为%d\n", height_tree(root));
	printf("树的叶子结点有%d\n", leaf_size(root));
	printf("第k层共有%d个结点\n", level_size(root,2));
	printf("层序遍历的结果为\n");
	sequence_foreach(root);
	destory(root);

}