#pragma once
#include<stdbool.h>
typedef int datatype;
typedef struct {
    datatype* val;
    int front;
    int rear;
    int capacity;
    int len;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k);
int myCircularQueueEnQueue(MyCircularQueue* obj, datatype value); 
int myCircularQueueDeQueue(MyCircularQueue* obj);

int myCircularQueueFront(MyCircularQueue* obj); 
int myCircularQueueRear(MyCircularQueue* obj);
int myCircularQueueIsEmpty(MyCircularQueue* obj); 
int  myCircularQueueIsFull(MyCircularQueue* obj); 
void myCircularQueueFree(MyCircularQueue* obj);
void test();

