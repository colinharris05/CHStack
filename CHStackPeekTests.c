#include <stdio.h>

#include "CHStack.h"
#include "CuTest.h"

void TestPeekWithOneElement(CuTest *tc) {
  CHStack *stack = newCHStack(5);
  int i = 5;
  push(stack, &i);

  int *actual = (int *)peek(stack);
  int expected = 5;
  CuAssertIntEquals(tc, expected, *actual);
}

CuSuite* CHStackPeekGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestPeekWithOneElement);
  return suite;
}
