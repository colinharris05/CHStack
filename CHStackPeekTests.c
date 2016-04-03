#include <stdio.h>

#include "CHStack.h"
#include "CuTest.h"

void TestPeekWithZeroElements(CuTest *tc) {
  CHStack *stack = chstack_new(5);
  void *actual = chstack_peek(stack);
  void *expected = NULL;
  CuAssertPtrEquals(tc, expected, actual);
}

void TestPeekWithOneElement(CuTest *tc) {
  CHStack *stack = chstack_new(5);
  int i = 5;
  chstack_push(stack, &i);

  int *actual = (int *)chstack_peek(stack);
  int expected = 5;
  CuAssertIntEquals(tc, expected, *actual);
}

void TestPeekWithTwoElements(CuTest *tc) {
  CHStack *stack = chstack_new(5);
  int i = 5;
  chstack_push(stack, &i);
  int j = 7;
  chstack_push(stack, &j);

  int *actual = (int *)chstack_peek(stack);
  int expected = 7;
  CuAssertIntEquals(tc, expected, *actual);
}

CuSuite* CHStackPeekGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestPeekWithZeroElements);
  SUITE_ADD_TEST(suite, TestPeekWithOneElement);
  SUITE_ADD_TEST(suite, TestPeekWithTwoElements);
  return suite;
}
