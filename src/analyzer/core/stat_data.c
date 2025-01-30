#include "stat_data.h"

#include <stdio.h>
#include <stdlib.h>

char *serialize(const StatData *obj) {
  char *buffer = (char *)malloc(100);

  sprintf(buffer, "%ld;%d;%f;%u;%u;", obj->id, obj->count, obj->cost,
          obj->primary, obj->mode);
  return buffer;
}

StatData *deserialize(char *buffer) {
  StatData *obj = malloc(sizeof(StatData));
  unsigned int primary, mode;

  if (!sscanf(buffer, "%ld %d %f %u %u", &obj->id, &obj->count, &obj->cost,
              &primary, &mode))
    return NULL;

  obj->primary = primary;
  obj->mode = mode;

  return obj;
}
