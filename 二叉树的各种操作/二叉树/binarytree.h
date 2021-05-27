#pragma once
typedef int datatype;
typedef struct binary
{
	datatype val;
	struct binary* left;
	struct binary* right;
}binaryTree;
//������ڴ�Ŀ���
//binaryTree* my_malloc(datatype val);
//���Ĵ�������ʼ��
void create(binaryTree**root);
//���ĵݹ����
void foreach(binaryTree* root);
//����ĳ��Ԫ��
binaryTree* find(binaryTree* root,datatype val);
//���Ĳ������
void sequence_foreach(binaryTree* root);
//���Ŀ���
binaryTree* copy(binaryTree* root);
//���ؽ������
int Node_size(binaryTree* root);
//����Ҷ�ӽ������
int leaf_size(binaryTree* root);
//�������ĸ߶�
int height_tree(binaryTree* root);
//��������ĳһ��Ľ�����
int level_size(binaryTree* root, int k);

//��������
void destory(binaryTree* root);
//��������
void test();