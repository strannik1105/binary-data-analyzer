#include "stat_data.h"

#include <stdio.h>
#include <stdlib.h>

char *serialize(const StatData *obj) {
  char *buffer = (char *)malloc(sizeof("%ld;%d;%f;%u\n"));
  union {
    struct {
      unsigned int primary : 1;
      unsigned int mode : 3;
    };
    unsigned int value;
  } bf;
  bf.primary = obj->primary;
  bf.mode = obj->mode;

  sprintf(buffer, "%ld;%d;%f;%u", obj->id, obj->count, obj->cost, bf.value);
  return buffer;
}

StatData *deserialize(char *buffer) {
  union {
    struct {
      unsigned int primary : 1;
      unsigned int mode : 3;
    };
    unsigned int value;
  } bf;

  // struct OptionalStatData result;
  StatData *obj = malloc(sizeof(StatData));

  if (!sscanf(buffer, "%ld;%d;%f;%u", &obj->id, &obj->count, &obj->cost,
              &bf.value))
    return NULL;

  obj->primary = bf.primary;
  obj->mode = bf.mode;
  return obj;
}
