#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} MyQueue;

MyQueue* createQueue() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

bool isQueueEmpty(MyQueue* queue) {
    return (queue->front == -1);
}

void enqueue(MyQueue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->data[++queue->rear] = value;
}

int dequeue(MyQueue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
}

typedef struct {
    MyQueue* q1;
    MyQueue* q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q1, x);
}

int myStackPop(MyStack* obj) {
    if (isQueueEmpty(obj->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    while (obj->q1->front != obj->q1->rear) {
        enqueue(obj->q2, dequeue(obj->q1));
    }
    int value = dequeue(obj->q1);
    MyQueue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    return value;
}

int myStackTop(MyStack* obj) {
    if (isQueueEmpty(obj->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    while (obj->q1->front != obj->q1->rear) {
        enqueue(obj->q2, dequeue(obj->q1));
    }
    int value = dequeue(obj->q1);
    enqueue(obj->q2, value);
    MyQueue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    return value;
}

bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

int main() {
    MyStack* obj = myStackCreate();

    myStackPush(obj, 1);
    myStackPush(obj, 2);
    myStackPush(obj, 3);

    printf("Top element: %d\n", myStackTop(obj));
    printf("Pop: %d\n", myStackPop(obj));
    printf("Is the stack empty? %s\n", myStackEmpty(obj) ? "Yes" : "No");

    myStackFree(obj);
    return 0;
}
