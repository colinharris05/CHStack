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
  CHStack *stack = newCHStack(10);
  int i;
  for (i = 1; i < argc; i++) {
    char *c = argv[i];
    push(stack, c);
  }
  print(stack); 
  pop(stack);
  pop(stack);
  pop(stack);
  print(stack);

  void *peekedValue = peek(stack);
  printf("peekedValue: %s\n", (char *)peekedValue);
  print(stack);

  freeCHStack(stack);
}
