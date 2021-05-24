#include"Heap.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
//��������
void swap(datatype* num1, datatype* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
//�ӿ�һ��С�ѽӿ�
int Big_heap(datatype num1, datatype num2)
{
	return num1 > num2;
}
//�ӿڶ�����ѽӿ�
int Small_heap(datatype num1, datatype num2)
{
	return num1 < num2;
}
//�ѵ����µ���
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
//�ѵĳ�ʼ��
void Heap_init(Heap* p, datatype arr[], int size, My_comcare mp)
{
	assert(p);
	p->val = (datatype*)malloc(sizeof(datatype) * size);
	if (p->val == 0)
	{
		printf("�ڴ濪��ʧ��\n");
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
//�ѵ����ϵ���
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
//�ѵĲ���
void Heap_insert(Heap* p, datatype data)
{
	assert(p->val);
	check(p);
	p->val[p->size++] = data;
	int root = p->size - 1;
    adjust_up(p, root);
	
	
}
//�ѵ�ɾ��,Ĭ��ɾ�����ǶѶ�Ԫ��
void Heap_delete(Heap* p)
{
	assert(p&&p->val!=NULL);
	//�Ƚ���Ԫ��
	swap(&p->val[0], &p->val[p->size - 1]);
	//��Ԫ�ظ�����һ
	p->size--;
	int root = (p->size - 1) / 2;
	//Ȼ�������������µ�������
	for (; root >= 0; root--)
	{
		adjust_down(p, root);
	}
	

}
//�ж϶��Ƿ�Ϊ��
int is_empty(Heap* p)
{
	assert(p);
	return p->size == 0;
}
//�ѵĿ��ٿռ�
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
//�ѵ�����
void sort_myHeap(int arr[], int size)
{
	
	int end = size - 1;
	//�����ȹ�����
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
//���ضѶ�Ԫ��
datatype Heap_top(Heap* p)
{
	assert(p->val);
	return p->val[0];
}
//��ȡ��ЧԪ�صĸ���
int Heap_size(Heap* p)
{
	assert(p);
	return p->size;
}
//�ѵ�����
void Heap_destory(Heap* p)
{
	assert(p);
	if (p->val != NULL)
	{
		free(p->val);
		p->val = NULL;
	}
}
//���Խӿ�
void test()
{
	int arr[] = { 3,4,5,1,0,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Heap p;
	Heap_init(&p, arr, len, Small_heap);
	printf("�Ѷ�Ԫ��Ϊ%d\n", Heap_top(&p));
	printf("��ЧԪ�ظ���Ϊ%d\n", Heap_size(&p));
	Heap_insert(&p, 9);
	printf("�Ѷ�Ԫ��Ϊ%d\n", Heap_top(&p));
	printf("��ЧԪ�ظ���Ϊ%d\n", Heap_size(&p));
	Heap_delete(&p);
	sort_myHeap(&arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
	printf("�Ѷ�Ԫ��Ϊ%d\n", Heap_top(&p));
	printf("��ЧԪ�ظ���Ϊ%d\n", Heap_size(&p));
	
}