#include "CHStack.h"
#include "CHLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

struct _CHStack {
  CHLinkedList *elements;
  int maxElems;
};

CHStack *chstack_new(const unsigned int maxElems) {
  CHStack *stack = malloc(sizeof(CHStack));
  stack->maxElems = maxElems;
  stack->elements = chlinkedlist_new();
  return stack;
}

void chstack_free(CHStack *stack) {
  free(stack);
  stack = NULL;
}

void *chstack_peek(CHStack *stack) {
  if (chstack_size(stack) > 0) {
    return chlinkedlist_get(stack->elements, chstack_size(stack) - 1);
  } else {
    return NULL;
  }
}

void *chstack_pop(CHStack *stack) {
  if (chstack_size(stack) == 0) {
    return NULL;
  }
  void *result = chlinkedlist_pop(stack->elements);
  return result;
}

void chstack_push(CHStack *stack, void *p) {
  chlinkedlist_append(stack->elements, p);  
}

int chstack_size(CHStack *stack) {
  return chlinkedlist_size(stack->elements);
}
