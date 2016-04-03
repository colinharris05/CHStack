#include <stdio.h>

#include "CuTest.h"

CuSuite* CHStackPeekGetSuite();
CuSuite* CHStackPushGetSuite();
CuSuite* CHStackPopGetSuite();

void RunAllTests() {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();

  CuSuiteAddSuite(suite, CHStackPeekGetSuite());
  CuSuiteAddSuite(suite, CHStackPushGetSuite());
  CuSuiteAddSuite(suite, CHStackPopGetSuite());

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);
}

int main(void) {
  RunAllTests();
}
