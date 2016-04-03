#include <stdlib.h>

#include "CHStack.h"
#include "CuTest.h"

void TestPushingZeroElements(CuTest *tc) {
  CHStack *stack = chstack_new(5);

  int actual_size = chstack_size(stack);
  int expected_size = 0;
  CuAssertIntEquals(tc, expected_size, actual_size);

  void *actual = chstack_peek(stack);
  void *expected = NULL;
  CuAssertPtrEquals(tc, expected, actual);
}

void TestPushingOneElement(CuTest *tc) {
  CHStack *stack = chstack_new(5);

  int i = 5;
  chstack_push(stack, &i);

  int actual_size = chstack_size(stack);
  int expected_size = 1;
  CuAssertIntEquals(tc, expected_size, actual_size);

  int *actual = (int *)chstack_peek(stack);
  int expected = 5;
  CuAssertIntEquals(tc, expected, *actual);
}

void TestPushingTwoElements(CuTest *tc) {
  CHStack *stack = chstack_new(5);

  int i = 5;
  chstack_push(stack, &i);

  int j = 7;
  chstack_push(stack, &j);

  int actual_size = chstack_size(stack);
  int expected_size = 2;
  CuAssertIntEquals(tc, expected_size, actual_size);

  int *actual = (int *)chstack_peek(stack);
  int expected = 7;
  CuAssertIntEquals(tc, expected, *actual);
}

CuSuite* CHStackPushGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestPushingZeroElements);
  SUITE_ADD_TEST(suite, TestPushingOneElement);
  SUITE_ADD_TEST(suite, TestPushingTwoElements);
  return suite;
}
