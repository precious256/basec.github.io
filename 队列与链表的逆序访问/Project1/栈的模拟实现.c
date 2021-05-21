#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include"stack.h"

void test01()
{
	Stack s;
	init(&s);
	pushStack(&s, 5);
	pushStack(&s, 4);
	pushStack(&s, 3);
	pushStack(&s, 2);
	pushStack(&s, 1);
    pushStack(&s, 1);
	printf("元素的有效个数为%d\n", return_num(&s));
	popStack(&s);
	popStack(&s);
	popStack(&s);
	printf("元素的有效个数为%d\n", return_num(&s));
}
bool isValid()
{
   
    char s[] = "(])";
    Stack p;
    init(&p);
    bool flag = true;
    //printf("%d\n", strlen(s));
    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            pushStack(&p, s[i]);
        }
        else
        {
            if (!(is_empty(&p)))
            {
                char top = return_top(&p);
                if ((top == '(' && s[i] == ')') ||
                    (top == '[' && s[i] == ']') ||
                    (top == '{' && s[i] == '}'))
                {
                    popStack(&p);
                }
                else
                {
                    destory(&p);
                    return false;
                }
            }
            else
            {
                destory(&p);
                return false;
            }
        }
    }
    if (!is_empty(&p))
    {
        destory(&p);
        flag = false;
    }
    else
    {
        destory(&p);
        flag = true;
    }
    return flag;
}

int main(void)
{
	test01();
    
    //test_list();
	system("pause");
	return EXIT_SUCCESS;
}
