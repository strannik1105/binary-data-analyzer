
#include <stdio.h>
#include <time.h>

#include "cases.h"
#include "test_helper.h"

// TODO: макрос TEST_MAIN() в параметрах которого перечисление тест-кейсов
int main() {
  clock_t begin = clock();
  TEST_META;

  // кейсы для запуска
  RUN_CASE(case1);
  RUN_CASE(case2);

  clock_t end = clock();
  if (has_failed) {
    printf("Has failed cases\n");
  }
  printf("Time spent %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
}
