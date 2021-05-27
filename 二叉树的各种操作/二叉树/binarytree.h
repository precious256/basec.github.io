#pragma once
typedef int datatype;
typedef struct binary
{
	datatype val;
	struct binary* left;
	struct binary* right;
}binaryTree;
//树结点内存的开辟
//binaryTree* my_malloc(datatype val);
//树的创建及初始化
void create(binaryTree**root);
//树的递归遍历
void foreach(binaryTree* root);
//查找某个元素
binaryTree* find(binaryTree* root,datatype val);
//树的层序遍历
void sequence_foreach(binaryTree* root);
//树的拷贝
binaryTree* copy(binaryTree* root);
//返回结点总数
int Node_size(binaryTree* root);
//返回叶子结点总数
int leaf_size(binaryTree* root);
//返回树的高度
int height_tree(binaryTree* root);
//返回树中某一层的结点个数
int level_size(binaryTree* root, int k);

//树的销毁
void destory(binaryTree* root);
//测试用例
void test();