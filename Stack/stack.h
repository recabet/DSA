#ifndef MYLIBS_STACK_H
#define MYLIBS_STACK_H

#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 202300L
#include<stdbool.h>
#endif

typedef struct
{
	int *elements;
	int top;
	int capacity;
} Stack;

// Function prototypes
Stack *createStack(int capacity);

void destroyStack(Stack *stack);

bool isFull(Stack *stack);

bool isEmpty(Stack *stack);

void push(Stack *stack, int val);

int pop(Stack *stack);

int peek(Stack *stack);

void printStack(Stack *stack);

#endif //MYLIBS_STACK_H
