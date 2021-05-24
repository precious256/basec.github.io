#include"Heap.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
//交换函数
void swap(datatype* num1, datatype* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
//接口一，小堆接口
int Big_heap(datatype num1, datatype num2)
{
	return num1 > num2;
}
//接口二，大堆接口
int Small_heap(datatype num1, datatype num2)
{
	return num1 < num2;
}
//堆的向下调整
void adjust_down(Heap* p, int root)
{
	assert(p);
	int child = 2 * root + 1;
	while (child < p->size)
	{
		if (child + 1 < p->size && p->m1(p->val[child], p->val[child + 1]))
		{
			child += 1;
		}
		if (p->val[child] > p->val[root])
		{
			swap(&p->val[child], &p->val[root]);
			root = child;
			child = root * 2 + 1;
			
		}
		else
		{
			return;
		}

	}
}
//堆的初始化
void Heap_init(Heap* p, datatype arr[], int size, My_comcare mp)
{
	assert(p);
	p->val = (datatype*)malloc(sizeof(datatype) * size);
	if (p->val == 0)
	{
		printf("内存开辟失败\n");
		return;
	}
	p->size = size;
	p->capacity = size;
	memcpy(p->val, arr, sizeof(datatype) * size);
	int root = (size - 1) / 2;
	p->m1 = mp;
	for (; root >= 0; root--)
	{
		adjust_down(p, root);
	}

}
//堆的向上调整
void adjust_up(Heap* p, int root)
{
	assert(p);
	int child = root;
	int parent = (root-1)>>1;
	while (root)
	{
		if (p->val[root] > p->val[parent])
		{
			swap(&p->val[root], &p->val[parent]);
			root = parent;
			parent = (root - 1) >> 2;
		}
		else
		{
			return;
		}
	}
}
//堆的插入
void Heap_insert(Heap* p, datatype data)
{
	assert(p->val);
	check(p);
	p->val[p->size++] = data;
	int root = p->size - 1;
    adjust_up(p, root);
	
	
}
//堆的删除,默认删除的是堆顶元素
void Heap_delete(Heap* p)
{
	assert(p&&p->val!=NULL);
	//先交换元素
	swap(&p->val[0], &p->val[p->size - 1]);
	//将元素个数减一
	p->size--;
	int root = (p->size - 1) / 2;
	//然后重新利用向下调整方法
	for (; root >= 0; root--)
	{
		adjust_down(p, root);
	}
	

}
//判断堆是否为空
int is_empty(Heap* p)
{
	assert(p);
	return p->size == 0;
}
//堆的开辟空间
void check(Heap* p)
{
	assert(p);
	if (p->size == p->capacity)
	{
		p->val = (datatype*)realloc(p->val, sizeof(datatype) * p->capacity * 2);
		if (p->val == NULL)
		{
			return;
		}
		p->capacity *= 2;

	}
}

void adjust(int arr[],int size,int root)
{
	if (arr == NULL)
	{
		return;
	}
	int child = root * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child+1] > arr[child ])
		{
			child+=1;
		}
		if (arr[child] > arr[root])
		{
			swap(&arr[child], &arr[root]);
		}
		else
		{
			return;
		}
	}
}
//堆的排序
void sort_myHeap(int arr[], int size)
{
	
	int end = size - 1;
	//首先先构建堆
	for(int root = (size-2)/2; root >=0; root--)
	{
		adjust(arr, size, root);
	}
	while (end)
	{
		swap( &arr[end],&arr[0]);
		adjust(arr, end, 0);
		end--;
	}

	
}
//返回堆顶元素
datatype Heap_top(Heap* p)
{
	assert(p->val);
	return p->val[0];
}
//获取有效元素的个数
int Heap_size(Heap* p)
{
	assert(p);
	return p->size;
}
//堆的销毁
void Heap_destory(Heap* p)
{
	assert(p);
	if (p->val != NULL)
	{
		free(p->val);
		p->val = NULL;
	}
}
//测试接口
void test()
{
	int arr[] = { 3,4,5,1,0,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Heap p;
	Heap_init(&p, arr, len, Small_heap);
	printf("堆顶元素为%d\n", Heap_top(&p));
	printf("有效元素个数为%d\n", Heap_size(&p));
	Heap_insert(&p, 9);
	printf("堆顶元素为%d\n", Heap_top(&p));
	printf("有效元素个数为%d\n", Heap_size(&p));
	Heap_delete(&p);
	sort_myHeap(&arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
	printf("堆顶元素为%d\n", Heap_top(&p));
	printf("有效元素个数为%d\n", Heap_size(&p));
	
}