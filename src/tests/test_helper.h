#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "core/dump.h"
#include "core/list.h"
#include "core/stat_data.h"
#include "processing/processing.h"

typedef struct List List;
typedef struct StatData StatData;

List *to_list(const StatData *data, size_t size);

typedef struct Case {
  StatData *dump1;
  StatData *dump2;
  StatData *result;
} Case;

#define TEST_META   \
  bool case_result; \
  bool has_failed;

bool run_case(const StatData *in1, size_t in1_size, const StatData *in2,
              size_t in2_size, const StatData *out, size_t out_size);

#define RUN_CASE(case)                                                    \
  printf("run case: " #case "\n");                                        \
  case_result =                                                           \
      run_case(case##_in_a, sizeof(case##_in_a) / sizeof(case##_in_a[0]), \
               case##_in_b, sizeof(case##_in_b) / sizeof(case##_in_b[0]), \
               case##_out, sizeof(case##_out) / sizeof(case##_out[0]));   \
  if (case_result)                                                        \
    printf("\t" #case " success\n");                                      \
  else                                                                    \
    fprintf(stderr, #case " fail\n");

#endif
