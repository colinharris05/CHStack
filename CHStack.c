#include "CHStack.h"

 CHStack *newCHStack() {
  CHStack *stack = malloc(sizeof(CHStack));
  stack->array = malloc(sizeof(int) * 10); // Default of 10 elements
  stack->size = 0;
  printf("%s\n", "Returning new CHStack");
  return stack;
}

void freeCHStack(CHStack *stack) {
  free(stack->array);
  free(stack);
}

int peek(CHStack *stack) {
  return stack->array[stack->size - 1];
}

int pop(CHStack *stack) {
  if (stack->size == 0) {
    fprintf(stderr, "%s\n", "Cannot pop from empty stack!");
    return -1;
  }  
  int result = stack->array[stack->size - 1];
  printf("Popping %i from position %i\n", result, stack->size - 1);
  stack->size--;
  return result;
}

void push(CHStack *stack, int p) {
  if (stack->size == 0) {
    printf("Push %i at position %i\n", p, 0);
    stack->array[0] = p;
    stack->size = 1;
    return;
  }
  printf("Push %i at position %i\n", p, stack->size);
  stack->array[stack->size] = p;
  stack->size++;
}

void print(CHStack *stack) {
  printf("Bottom--> ");
  int i;
  for (i = 0; i < stack->size; i++) {
    printf("%i ", stack->array[i]);
  }
  printf(" <--Top\n");
}