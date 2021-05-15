#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
struct binarytree
{
	char ch;
	struct binarytree* lchild;
	struct binarytree* rchild;
};
int calnum(struct binarytree* root)
{
	if (root == NULL)
	{
		return;
	}
	static int ps = 0;
	if (root->lchild == NULL && root->rchild == NULL)
	{
		ps++;
	}
	calnum(root->lchild);
	calnum(root->rchild);
	return ps;
}
int cal(struct binarytree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	cal(root->lchild);
	cal(root->rchild);
	return cal(root->lchild) > cal(root->rchild) ? cal(root->lchild) + 1 : cal(root->rchild) + 1;

}
struct binarytree* copy(struct binarytree* p1)
{
	if (p1 == NULL)
	{
		return NULL;
	}
	
	struct binarytree* lchild = copy(p1->lchild);
	struct binarytree* rchild = copy(p1->rchild);
	struct binarytree* newnode = malloc(sizeof(struct binarytree));
	newnode->lchild = lchild;
	newnode->rchild = rchild;
	newnode->ch = p1->ch;
	return newnode;
}
void show(struct binarytree* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c\n", root->ch);
	show(root->lchild);
	show(root->rchild);
}
//利用递归来释放二叉树
void freetree(struct binarytree* root)
{
	if (root == NULL)
	{
		return;
	}
	freetree(root->lchild);
	freetree(root->rchild);
	printf("%c去释放了\n", root->ch);
	free(root);
}
void test01()
{
	struct binarytree p1 = { 'A',NULL,NULL };
	struct binarytree p2 = { 'B',NULL,NULL };
	struct binarytree p3 = { 'C',NULL,NULL };
	struct binarytree p4 = { 'D',NULL,NULL };
	struct binarytree p5 = { 'E',NULL,NULL };
	struct binarytree p6 = { 'F',NULL,NULL };
	struct binarytree p7 = { 'G',NULL,NULL };
	struct binarytree p8 = { 'H',NULL,NULL };
	p1.lchild = &p2;
	p1.rchild = &p6;
	p2.rchild = &p3;
	p3.lchild = &p4;
	p3.rchild = &p5;
	p6.rchild = &p7;
	p7.lchild = &p8;
	int ret = calnum(&p1);
	int all = cal(&p1);
	printf("叶子结点共有%d\n", ret);
	printf("总层数为%d\n", all);
	struct binarytree* newnode = copy(&p1);
	show(newnode);
	freetree(newnode);
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}

