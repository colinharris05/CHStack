#include <stdio.h>

#include "CHStack.h"
#include "CuTest.h"

void TestPeekWithZeroElements(CuTest *tc) {
  CHStack *stack = newCHStack(5);
  void *actual = peek(stack);
  void *expected = NULL;
  CuAssertPtrEquals(tc, expected, actual);
}

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
  SUITE_ADD_TEST(suite, TestPeekWithZeroElements);
  SUITE_ADD_TEST(suite, TestPeekWithOneElement);
  return suite;
}
