#include <stdlib.h>
#include <stdio.h>

struct CHStack;
typedef struct CHStack CHStack;

CHStack *newCHStack(const int maxElems);
void freeCHStack(CHStack *stack);
void print(CHStack *stack);
void *peek(CHStack *stack);
void *pop(CHStack *stack);
void push(CHStack *stack, void *p);
int stackSize(CHStack *stack);
