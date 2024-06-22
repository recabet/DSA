#ifndef STACK_H
#define STACK_H

#include<stdbool.h>


typedef struct {
	int* elements;
	int top;
	int capacity;
} Stack;

Stack* createStack(int capacity);

void destroyStack(Stack* stack);

bool isFull(Stack* stack);

bool isEmpty(Stack* stack);

void push(Stack* stack, int val);

int pop(Stack* stack);

int peek(Stack* stack);

void printStack(Stack* stack);

#endif //STACK_H
