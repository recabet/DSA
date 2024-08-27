#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>


typedef struct {
    int* elements;
    int front;
    int rear;
    int capacity;
} Queue;


Queue* createQueue(int capacity);

void destroyQueue(Queue* queue);

bool isFull(Queue* queue);

bool isEmpty(Queue* queue);

void enqueue(Queue* queue, int val);

int dequeue(Queue* queue);

void printQueue(Queue* queue);


#endif //QUEUE_H
