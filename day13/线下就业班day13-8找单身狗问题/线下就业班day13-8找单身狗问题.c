#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
int mp(void* num1, void* num2)
{
	return*(int*)num1 - *(int*)num2;
}
void find_dog(int* arr, int* dog, int len)
{
	qsort(arr, len, 4, mp);

	int z = 0;
	
	int i = 0;
	while (i < len)

	{
		if ((z == 1) && ((i) == (len - 1)))
		{
			arr[z] = arr[i];
		}
		if (arr[i] == arr[i + 1])
		{
			i += 2;
		}
		else
		{
			dog[z] = arr[i];
			z += 1;
			if (z == 2)
			{
				break;
			}
			i += 1;
		}

	}

}
//void findTwoNum(int arr[], int n, int* pnum1, int* pnum2)
//{
//	int i;
//	int sum = 0;
//	for (i = 0; i < n; i++)
//	{
//		sum ^= arr[i];
//	} //先找到两个数互相异或的结果
//	printf("sum=%d\n", sum);
//	int pos=0;
//	for (i = 0; i < 32; i++)
//	{
//		if (sum & 1 << i)
//		{
//			pos = i;
//
//			break;
//		}
//	}
//	//再找到有分歧的一位。在这一位上，两个数一定是一个1一个0
//	//*pnum1 = *pnum2 = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] & 1 << pos)
//		{
//			*pnum1 ^= arr[i]; //这一位是1的，放在数1里
//		}
//		else
//		{
//			*pnum2 ^= arr[i]; //这一位是0的，放在数2里
//		}
//	}
//}
void test01()
{
	int arr[] = { 1,2,1,2,3,4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int sum = 0;
	int p[2] = { 0 };
	find_dog(arr, &p, len);
	//findTwoNum(arr, len, p[0], p[1]);
	for (size_t i = 0; i < 2; i++)
	{
		printf("dog:\t%d\n", p[i]);
	}

	
}
int main(void)
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
