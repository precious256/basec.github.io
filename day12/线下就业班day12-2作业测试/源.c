#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#pragma pack(4)
int main(int argc, char* argv[])
{
    struct tagTest1
    {
        short a;//2
        char d;//2
        long b;//4
        long c;//4
    };
    struct tagTest2
    {
        long b;//4
        short c;//2
        char d;//2
        long a;//4
    };
    struct tagTest3
    {
        short c;//4
        long b;//4
        char d;//4
        long a;//4
    };
    struct tagTest1 stT1;
    struct tagTest2 stT2;
    struct tagTest3 stT3;

    printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
    return 0;
}
