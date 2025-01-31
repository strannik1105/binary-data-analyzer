#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include <stddef.h>

typedef struct List List;
typedef struct StatData StatData;

List *to_list(const StatData *data, size_t size);

typedef struct Case {
  StatData *dump1;
  StatData *dump2;
  StatData *result;
} Case;

#endif
