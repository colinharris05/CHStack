#include <stdlib.h>

#include "CHStack.h"
#include "CuTest.h"

void TestPoppingWithZeroElements(CuTest *tc) {
  CHStack *stack = chstack_new(5);

  int actual_size = chstack_size(stack);
  int expected_size = 0;
  CuAssertIntEquals(tc, expected_size, actual_size);

  void *actual = chstack_pop(stack);
  void *expected = NULL;
  CuAssertPtrEquals(tc, expected, actual);
}

void TestPoppingWithOneElement(CuTest *tc) {
  CHStack *stack = chstack_new(5);

  int i = 5;
  chstack_push(stack, &i);

  int *actual = (int *)chstack_pop(stack);
  int expected = 5;
  CuAssertIntEquals(tc, expected, *actual);

  int actual_size = chstack_size(stack);
  int expected_size = 0;
  CuAssertIntEquals(tc, expected_size, actual_size);
}

void TestPoppingWithTwoElements(CuTest *tc) {
  CHStack *stack = chstack_new(5);

  int i = 5;
  chstack_push(stack, &i);

  int j = 7;
  chstack_push(stack, &j);

  int *actual = (int *)chstack_pop(stack);
  int expected = 7;
  CuAssertIntEquals(tc, expected, *actual);

  int actual_size = chstack_size(stack);
  int expected_size = 1;
  CuAssertIntEquals(tc, expected_size, actual_size);
}

CuSuite* CHStackPopGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestPoppingWithZeroElements);
  SUITE_ADD_TEST(suite, TestPoppingWithOneElement);
  SUITE_ADD_TEST(suite, TestPoppingWithTwoElements);
  return suite;
}
