#include <stdlib.h>
#include <stdio.h>

typedef struct CHStack {
  void **elements;
  int maxElems;
  int size;
} CHStack;

CHStack *newCHStack(const int maxElems);
void freeCHStack(CHStack *stack);
void print(CHStack *stack);
void *peek(CHStack *stack);
void *pop(CHStack *stack);
void push(CHStack *stack, void *p);
