#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* createStack(const int capacity)
{
    Stack* stack = (Stack *) malloc(sizeof(Stack));
    if (!stack)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->elements = (int *) malloc(capacity * sizeof(int));
    if (!stack->elements)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(stack);
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void destroyStack(Stack* stack)
{
    free(stack->elements);
    free(stack);
}

bool isFull(const Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

bool isEmpty(const Stack* stack)
{
    return stack->top == -1;
}

void push(Stack* stack, const int val)
{
    if (isFull(stack))
    {
        fprintf(stderr, "Stack is full\n");
        return;
    }
    stack->elements[++stack->top] = val;
}

int pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->elements[stack->top--];
}

int peek(const Stack* stack)
{
    if (isEmpty(stack))
    {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->elements[stack->top];
}

void printStack(const Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}
