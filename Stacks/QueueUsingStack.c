#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100000

typedef struct {
    int stack1[MAX_SIZE];
    int stack2[MAX_SIZE];
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->top1 = -1;
    queue->top2 = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->top1 == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    obj->stack1[++obj->top1] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        if (obj->top1 == -1) {
            printf("Queue is empty\n");
            return -1;
        } else {
            while (obj->top1 != -1) {
                obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
            }
        }
    }
    return obj->stack2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        if (obj->top1 == -1) {
            printf("Queue is empty\n");
            return -1;
        } else {
            while (obj->top1 != -1) {
                obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
            }
        }
    }
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

int main() {
    MyQueue* obj = myQueueCreate();

    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    printf("Peek: %d\n", myQueuePeek(obj));
    printf("Pop: %d\n", myQueuePop(obj));
    printf("Empty: %s\n", myQueueEmpty(obj) ? "true" : "false");

    myQueueFree(obj);
    return 0;
}
