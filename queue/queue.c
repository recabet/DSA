#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


Queue* createQueue(const int capacity)
{
    Queue* queue = (Queue *) malloc(sizeof(Queue));
    if (!queue)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue->elements = (int *) malloc(capacity * sizeof(int));
    if (!queue->elements)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(queue);
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}


void destroyQueue(Queue* queue)
{
    free(queue->elements);
    free(queue);
}


bool isFull(const Queue* queue)
{
    return (queue->rear + 1) % queue->capacity == queue->front;
}


bool isEmpty(const Queue* queue)
{
    return queue->front == -1;
}


void enqueue(Queue* queue, const int val)
{
    if (isFull(queue))
    {
        fprintf(stderr, "Queue is full\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    queue->elements[queue->rear] = val;
}


int dequeue(Queue* queue)
{
    if (isEmpty(queue))
    {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    const int val = queue->elements[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return val;
}


void printQueue(const Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity)
    {
        printf("%d ", queue->elements[i]);
    }
    printf("%d\n", queue->elements[i]);
}
