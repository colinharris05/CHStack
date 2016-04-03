#include "CHStack.h"

#include <stdlib.h>
#include <stdio.h>

struct _CHStack {
  void **elements;
  int maxElems;
  int size;
};

CHStack *chstack_new(const unsigned int maxElems) {
  CHStack *stack = malloc(sizeof(CHStack));
  stack->maxElems = maxElems;
  stack->elements = malloc(sizeof(void *) * maxElems); // Default to size 10
  stack->size = 0;
  return stack;
}

void chstack_free(CHStack *stack) {
  free(stack);
  stack = NULL;
}

void **doubleArraySize(void **elements, const int size) {
  void **newArray = malloc(sizeof(void *) * 2*size);
  int i;
  for (i = 0; i < size; i++) {
    newArray[i] = elements[i];
  }
  return newArray;
}

// Used to assure the stack has enough space allocated
void checkSize(CHStack *stack) {
  if ((stack->size + 1) == stack->maxElems) {
    printf(" ***--Doubling array--***\n");
    stack->elements = doubleArraySize(stack->elements, stack->maxElems);
  }
}

void *chstack_peek(CHStack *stack) {
  if (stack->size > 0) {
    return stack->elements[stack->size - 1];
  } else {
    return NULL;
  }
}

void *chstack_pop(CHStack *stack) {
  if (stack->size == 0) {
    return NULL;
  }
  void *result = stack->elements[stack->size - 1];
  stack->size--;
  return result;
}

void chstack_push(CHStack *stack, void *p) {
  if (stack->size == 0) {
    stack->elements[0] = p;
    stack->size = 1;
  } else {
    checkSize(stack);
    stack->elements[stack->size] = p;
    stack->size++;
  }
}

int chstack_size(CHStack *stack) {
  return stack->size;
}
