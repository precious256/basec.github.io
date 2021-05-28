
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include"binarytree.h"
#include"stack.h"

binaryTree* my_malloc(datatype val)
{
	binaryTree* newnode = (binaryTree*)malloc(sizeof(binaryTree));
	if (NULL == newnode)
	{
		return NULL;
	}
	newnode->left = newnode->right = NULL;
	newnode->val = val;
	newnode->flag = 0;
}
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
binaryTree* create_v1(int arr[],int size,int invalid,int *index)//invalid 记录的是为NULL的那些结点
{
	binaryTree* root = NULL;//先定义出一个根节点，让其指向空
	if ((*index) < size && invalid != arr[(*index)])
	{
		root = my_malloc(arr[(*index)]);
		++(*index);
		root->left = create_v1(arr, size, invalid, index);
		++(*index);
		root->right = create_v1(arr, size, invalid, index);
	}
	return root;
}

//树的递归遍历
void foreach(binaryTree* root)
{
	if (root == NULL)
	{
		return;
	}
	//构建一个栈
	Stack p;
	init1(&p);
	pushStack(&p, root);
	while (!is_empty(&p))
	{
		binaryTree* cur = return_top(&p);
		popStack(&p);
		if (cur->flag == 1)
		{
			printf("%d\t", cur->val);
			continue;
		}
		cur->flag = 1;
		if (cur->right != NULL)
		{
			pushStack(&p, cur->right);
		}
		if (cur->left != NULL)
		{
			pushStack(&p, cur->left);
		}
		
		pushStack(&p, cur);
	}
	destory1(&p);
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
	 
	//create(&root);
	int arr[] = { 1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,-1 };
	int index = 0;
	binaryTree*root=create_v1(arr, sizeof(arr) / sizeof(arr[0]), -1, &index);
	//binaryTree* root = create_v1(arr, sizeof(arr) / sizeof(arr[0]), -1, 0);
	foreach(root);
	destory(root);

}