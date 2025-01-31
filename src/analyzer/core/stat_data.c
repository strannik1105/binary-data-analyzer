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

  if (!sscanf(buffer, "%ld;%d;%f;%u;%u;", &obj->id, &obj->count, &obj->cost,
              &primary, &mode))
    return NULL;

  obj->primary = primary;
  obj->mode = mode;

  return obj;
}

bool eq(const void *_obj1, const void *_obj2) {
  StatData *obj1 = (StatData *)_obj1;
  StatData *obj2 = (StatData *)_obj2;
  if ((obj1->id == obj2->id) && 
      (obj1->cost == obj2->cost) &&
      (obj1->count == obj2->count) &&
      (obj1->primary == obj2->primary) &&
      (obj1->mode == obj2->mode))
    return true;

  return false;
}
