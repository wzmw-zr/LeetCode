/*************************************************************************
	> File Name: 225.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月27日 星期四 20时51分51秒
 ************************************************************************/

typedef struct {
    int *data;
    int head, tail, size, cnt;
} MyStack;
#define max_n 10000
/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *s = (MyStack *) malloc(sizeof(MyStack));
    s->data = (int *) malloc(sizeof(int) * max_n);
    s->head = s->tail = s->cnt = 0;
    s->size = max_n;
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* s, int x) {
    if (!s) return ;
    if (s->cnt == s->size) return ;
    s->data[s->tail++] = x;
    s->cnt++;
    return ;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* q) {
    if (!q) return 0;
    int ret = q->data[q->tail - 1];
    for (int i = 1; i < q->cnt; i++) q->data[q->tail - i] = q->data[q->tail - i - 1];
    q->cnt--;
    q->head++;
    return ret;
}

/** Get the top element. */
int myStackTop(MyStack* s) {
    return s->data[s->tail - 1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* s) {
    return s->cnt == 0;
}

void myStackFree(MyStack* s) {
    if (!s) return ;
    free(s->data);
    free(s);
    return ;
}

