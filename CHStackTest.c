#include "CHStack.h"

void printSize(CHStack *stack) {
  printf("Size: %i\n", stack->size);
}

void printUsageExit() {
  fprintf(stderr, "Please enter arguments to push onto the stack\n");
  exit(-1);
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printUsageExit();
  }
  CHStack *stack = newCHStack();
  int i;
  for (i = 1; i < argc; i++) {
    push(stack, atoi(argv[i]));
  }
  print(stack); 
  pop(stack);
  pop(stack);
  pop(stack);
  print(stack);

  int peekedValue = peek(stack);
  printf("peekedValue: %i\n", peekedValue);
  print(stack);

  freeCHStack(stack);
}