#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* arr;
    int size;
    int front;
    int back;
    int cap;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* circularQueue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    circularQueue->arr = (int*)malloc(sizeof(int) * k);
    circularQueue->front = 0;
    circularQueue->back = 0;
    circularQueue->size = 0;
    circularQueue->cap = k;
    return circularQueue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->cap) return false;
    obj->arr[obj->back] = value;
    obj->back = (obj->back + 1) % obj->cap;
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0) return false;
    obj->front = (obj->front + 1) % obj->cap;
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    return (obj->size == 0) ? -1 : obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0) return -1;
    return obj->arr[(obj->back + obj->cap - 1) % obj->cap];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->size == 0);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->size == obj->cap);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}
int main(){
    MyCircularQueue* q = myCircularQueueCreate(5);

}