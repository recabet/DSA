#ifndef MYLIBS_QUEUE_H
#define MYLIBS_QUEUE_H


#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 202300L

#include <stdbool.h>
#endif


typedef struct
{
	int *elements;
	int front;
	int rear;
	int capacity;
} Queue;

// Function prototypes
Queue *createQueue (int capacity);

void destroyQueue (Queue *queue);

bool isFull (Queue *queue);

bool isEmpty (Queue *queue);

void enqueue (Queue *queue, int val);

int dequeue (Queue *queue);

void printQueue (Queue *queue);


#endif //MYLIBS_QUEUE_H
