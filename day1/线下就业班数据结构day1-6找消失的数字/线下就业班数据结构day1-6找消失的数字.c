#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>



int main()
{
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    int i = 0;
    while (scanf("%d", &arr[i++]) && i < n);
    while (getchar() != '\n');
    int target;
    scanf("%d", &target);
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (target == arr[i])
        {
            cont++;
        }
    }
    printf("%d\n", cont);
    return 0;
}
//int missingNumber(int* nums, int len)
//{
//
//    int sum1 = ((len+1) * len ) >> 1;
//    int sum = 0;
//    for (int i = 0; i < len; i++)
//    {
//        sum += nums[i];
//    }
//
//    return sum1 - sum;
//}
//void test01()
//{
//    int arr[] = { 1,3,4,0,5,6,7 };
//
//    int len = sizeof(arr) / sizeof(arr[0]);
//    int missing_nuuber=missingNumber(arr, len);
//    printf("missing number is %d\n", missing_nuuber);
//}
//int main(void)
//{
//    test01();
//	system("pause");
//	return EXIT_SUCCESS;
//}
