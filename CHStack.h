#include <stdlib.h>
#include <stdio.h>

typedef struct CHStack {
  int *array;
  int size;
} CHStack;

CHStack *newCHStack();
void freeCHStack(CHStack *stack);
void print(CHStack *stack);
int peek(CHStack *stack);
int pop(CHStack *stack);
void push(CHStack *stack, int p);