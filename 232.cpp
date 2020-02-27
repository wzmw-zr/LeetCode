/*************************************************************************
	> File Name: 232.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月27日 星期四 20时48分16秒
 ************************************************************************/

typedef struct MyStack {
    int *data;
    int top, size;
} MyStack;

MyStack *MyStackCreate(int size) {
    MyStack *s = (MyStack *) malloc(sizeof(MyStack));
    s->data = (int *) malloc(sizeof(int) * size);
    s->top = -1;
    s->size = size;
    return s;
}

void MyStackPush(MyStack *obj, int x) {
    if (!obj) return ;
    if (obj->top + 1 == obj->size) return ;
    obj->data[++obj->top] = x;
}

int MyStackPop(MyStack *obj) {
    return obj->data[(obj->top)--];
}

int MyStackTop(MyStack *obj) {
    return obj->data[obj->top];
}

int MyStackEmpty(MyStack *obj) {
    return obj->top == -1;
}

void MyStackFree(MyStack *obj) {
    if(!obj) return ;
    free(obj->data);
    free(obj);
}

typedef struct {
    MyStack *s1, *s2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    int size = 1024;
    MyQueue *q = (MyQueue *) malloc(sizeof(MyQueue));
    q->s1 = MyStackCreate(size);
    q->s2 = MyStackCreate(size);
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    MyStackPush(obj->s1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    while (!MyStackEmpty(obj->s1)) {
        MyStackPush(obj->s2, MyStackPop(obj->s1));
    }
    int ret = MyStackTop(obj->s2);
    MyStackPop(obj->s2);
    while (!MyStackEmpty(obj->s2)) {
        MyStackPush(obj->s1, MyStackPop(obj->s2));
    }
    return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    while (!MyStackEmpty(obj->s1)) {
        MyStackPush(obj->s2, MyStackPop(obj->s1));
    }
    int ret = MyStackTop(obj->s2);
    while (!MyStackEmpty(obj->s2)) {
        MyStackPush(obj->s1, MyStackPop(obj->s2));
    }
    return ret;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return MyStackEmpty(obj->s1);
}

void myQueueFree(MyQueue* obj) {
    if (!obj) return ;
    free(obj->s1);
    free(obj->s2);
    free(obj);
}

