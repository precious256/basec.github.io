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

//交换函数
void swap(datatype* num1, datatype* num2);
//接口一，大堆
int Big_heap(datatype num1, datatype num2);
//接口二，小堆
int Small_heap(datatype num1, datatype num2);
//堆的初始化
void Heap_init(Heap* p, datatype arr[], int size, My_comcare mp);
//堆的插入
void Heap_insert(Heap* p, datatype data);
//堆的删除,默认删除的是堆顶元素
void Heap_delete(Heap* p);
//判断堆是否为空
int is_empty(Heap* p);
//堆的开辟空间
void check(Heap* p);
//堆的向下调整
void adjust_down(Heap* p, int root);
//堆的向上调整
void adjust_up(Heap* p, int root);
//堆的排序
void sort_myHeap(Heap* p, int root);
//返回堆顶元素
datatype Heap_top(Heap* p);
//获取有效元素的个数
int Heap_size(Heap* p);
//堆的销毁
void Heap_destory(Heap* p);
//测试接口
void test();