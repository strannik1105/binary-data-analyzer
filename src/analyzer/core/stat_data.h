#ifndef CORE_STAT_DATA_H
#define CORE_STAT_DATA_H

#include <stdio.h>

#include "optional.h"

typedef struct StatData {
  long id;
  int count;
  float cost;
  unsigned int primary : 1;
  unsigned int mode : 3;
} StatData;

void serialize(const StatData obj, FILE *stream);

OPTIONAL(StatData) deserialize(FILE *stream);

#endif
