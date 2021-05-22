

#include"circlequeue.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>



MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* ms = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (NULL == ms)
    {
        return NULL;
    }
    ms->val = (datatype*)malloc(sizeof(datatype) * k);
    if (ms->val == NULL)
    {
        return NULL;
    }
    ms->front = 0;
    ms->rear = 0;
    ms->len = 0;
    ms->capacity = k;
    return ms;
}

int myCircularQueueEnQueue(MyCircularQueue* obj, datatype value) {
    if (myCircularQueueIsFull(obj))
    {
        return 0;
    }
    else
    {

        if (obj->rear == obj->capacity )
        {
            obj->rear = 0;
            obj->val[obj->rear++] = value;
        }
        else
            obj->val[obj->rear++] = value;

    }
    obj->len += 1;
    return 1;
}

int myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        printf("出队失败\n");
        return 0;
    }
    else
    {

        if (obj->front == obj->capacity - 1 )
        {
            obj->front = 0;

        }
        else
        {
            obj->front += 1;
        }


    }
    obj->len -= 1;
    return 1;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        return obj->val[obj->front];
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
    {
        return obj->val[obj->rear - 1];
    }
}

int myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->len != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int  myCircularQueueIsFull(MyCircularQueue* obj) {

    if (obj->len == obj->capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    assert(obj);
    if (obj->val)
    {
        free(obj->val);
    }
    free(obj);
}
void test()
{
    MyCircularQueue* head = myCircularQueueCreate(3);
	//myCircularQueueEnQueue(head, 1);
	//myCircularQueueEnQueue(head, 2);
	//myCircularQueueEnQueue(head, 3);
 //   //出队
 //   int ret = myCircularQueueFront(head);
 //   printf("队头为%d\n", ret);
	//myCircularQueueDeQueue(head);
 //   myCircularQueueDeQueue(head);
 //   myCircularQueueDeQueue(head);
	//myCircularQueueEnQueue(head, 4);
 //   myCircularQueueDeQueue(head);
  
    myCircularQueueEnQueue(head, 1);
    myCircularQueueEnQueue(head, 2);
    myCircularQueueEnQueue(head, 3);
    myCircularQueueEnQueue(head, 3);
    int   ret = myCircularQueueFront(head);
    printf("队头为%d\n",ret );
 
}
