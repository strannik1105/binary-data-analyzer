#include "stat_data.h"

#include <stdio.h>
#include <stdlib.h>

char *serialize(const StatData *obj) {
  char *buffer = (char *)malloc(100);

  sprintf(buffer, "%lx;%d;%f;%c;%x;", obj->id, obj->count, obj->cost,
          obj->primary ? 'y' : 'n', obj->mode);
  return buffer;
}

StatData *deserialize(char *buffer) {
  StatData *obj = malloc(sizeof(StatData));
  char primary;
  unsigned int mode;

  if (!sscanf(buffer, "%lx;%d;%f;%c;%x;", &obj->id, &obj->count, &obj->cost,
              &primary, &mode))
    return NULL;

  obj->primary = (primary == 'y') ? 1 : 0;;
  obj->mode = mode;

  return obj;
}

bool eq(const void *_obj1, const void *_obj2) {
  StatData *obj1 = (StatData *)_obj1;
  StatData *obj2 = (StatData *)_obj2;
  if ((obj1->id == obj2->id) && (obj1->cost == obj2->cost) &&
      (obj1->count == obj2->count) && (obj1->primary == obj2->primary) &&
      (obj1->mode == obj2->mode))
    return true;

  return false;
}
