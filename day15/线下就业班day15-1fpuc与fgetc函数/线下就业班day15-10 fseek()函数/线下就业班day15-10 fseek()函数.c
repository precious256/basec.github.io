
//fseek
//#include <stdio.h>
//int fseek(FILE* stream, long offset, int whence);
//功能：移动文件流（文件光标）的读写位置。
//参数：
//stream：已经打开的文件指针
//offset：根据whence来移动的位移数（偏移量），可以是正数，也可以负数，如果正数，则相对于whence往右移动，如果是负数，
// 则相对于whence往左移动。如果向前移动的字节数超过了文件开头则出错返回，如果向后移动的字节数超过了文件末尾，再次写入时将增大文件尺寸。
//whence：其取值如下：
//SEEK_SET：从文件开头移动offset个字节
//
//SEEK_CUR：从当前位置移动offset个字节
//SEEK_END：从文件末尾移动offset个字节
//返回值：
//成功：0
//失败： - 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
int main()
{
    FILE* fp = NULL;
    fp = fopen("fseek.txt", "wb");
    if (!fp)
    {
        perror("");
        return -1;
    }
    fputs("helloworld", fp);
    fseek(fp, 0, SEEK_SET);//移动光标到头
    fputs("seek", fp);
    fseek(fp, -20, SEEK_END);//？超过怎么办？
    fputs("abc", fp);
    fclose(fp);
    system("pause");
    return 0;
}