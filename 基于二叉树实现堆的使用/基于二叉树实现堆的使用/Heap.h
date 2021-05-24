#pragma once

typedef int datatype;
typedef int(*My_comcare)(datatype num1,datatype  num2);
typedef struct Heap
{
	datatype* val;
	int capacity;
	int size;
	My_comcare m1;

}Heap;

//��������
void swap(datatype* num1, datatype* num2);
//�ӿ�һ�����
int Big_heap(datatype num1, datatype num2);
//�ӿڶ���С��
int Small_heap(datatype num1, datatype num2);
//�ѵĳ�ʼ��
void Heap_init(Heap* p, datatype arr[], int size, My_comcare mp);
//�ѵĲ���
void Heap_insert(Heap* p, datatype data);
//�ѵ�ɾ��,Ĭ��ɾ�����ǶѶ�Ԫ��
void Heap_delete(Heap* p);
//�ж϶��Ƿ�Ϊ��
int is_empty(Heap* p);
//�ѵĿ��ٿռ�
void check(Heap* p);
//�ѵ����µ���
void adjust_down(Heap* p, int root);
//�ѵ����ϵ���
void adjust_up(Heap* p, int root);
//�ѵ�����
void sort_myHeap(Heap* p, int root);
//���ضѶ�Ԫ��
datatype Heap_top(Heap* p);
//��ȡ��ЧԪ�صĸ���
int Heap_size(Heap* p);
//�ѵ�����
void Heap_destory(Heap* p);
//���Խӿ�
void test();