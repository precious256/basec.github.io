#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

void test01()
{
	int arr[] = { 1,3,4,5,2,3,0,9,10 ,11, 7,20 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int gap = len;
	while (gap > 1)
	{
		gap = gap / 3+1;
		int i = 0;
		for (; i < len - gap; i++)
		{
			int end = i;
			int temp = arr[end + gap];
			while (end >= 0)
			{
				if (temp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = temp;
		   
		}
		for (int i = 0; i < len; i++)
		{
			printf("%d\t", arr[i]);
		}
		printf("\n");
		
	}
        
}
void test02()
{
	int arr[] = { 1,3,4,5,2,3,0,9,10 ,11, 7,20 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int key,i,j;
	int gap = len;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for ( i = gap; i < len; i++)
		{
			key = arr[i];
			for ( j = i; j >= gap && key < arr[j - gap]; j -= gap)
			{
				arr[j] = arr[j - gap]; 
			}
			arr[j] = key;
		}
	}
	for (int z = 0; z < len; z++)
	{
		printf("%d\t", arr[z]);
	}
	printf("\n");
}
int main(void)
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
