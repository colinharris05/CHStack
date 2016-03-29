#include "CHStack.h"
 
CHStack *newCHStack() {
  CHStack *stack = malloc(sizeof(CHStack));
  stack->maxElems = 10;
  stack->array = malloc(sizeof(int) * stack->maxElems); // Default of 10 elements
  stack->size = 0;
  printf("%s\n", "Returning new CHStack");
  return stack;
}

void freeCHStack(CHStack *stack) {
  free(stack);
  stack = NULL;
}

int *doubleArraySize(int *array, int size) {
  int doubledSize = size * 2;
  int *newArray = malloc(sizeof(int) * doubledSize);
  int i;
  for (i = 0; i < size; i++) {
    newArray[i] = array[i];
  }
  return newArray;
}

// Used to assure the stack has enough space allocated
void checkSize(CHStack *stack) {
  if ((stack->size + 1) == stack->maxElems) { // If adding one more elm equals maxElems (allocated size)
    printf(" ***--Doubling array--***\n");
    stack->array = doubleArraySize(stack->array, stack->maxElems);
  }
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
  checkSize(stack);
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