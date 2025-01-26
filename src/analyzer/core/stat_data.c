#include "stat_data.h"

void serialize(const StatData obj, FILE *stream) {
  union {
    struct {
      unsigned int primary : 1;
      unsigned int mode : 3;
    };
    unsigned int value;
  } bf;
  bf.primary = obj.primary;
  bf.mode = obj.mode;

  fprintf(stream, "%ld;%d;%f;%u\n", obj.id, obj.count, obj.cost, bf.value);
}

struct OptionalStatData deserialize(FILE *stream) {
  union {
    struct {
      unsigned int primary : 1;
      unsigned int mode : 3;
    };
    unsigned int value;
  } bf;

  struct OptionalStatData result;
  StatData obj;

  if (fscanf(stream, "%ld;%d;%f;%u", &obj.id, &obj.count, &obj.cost,
             &bf.value)) {
    obj.primary = bf.primary;
    obj.mode = bf.mode;

    result.has_value = true;
    result.value = obj;
  }

  return result;
}
