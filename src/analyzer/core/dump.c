#include "dump.h"

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "stat_data.h"

void store_dump(List *data, FILE *stream) {
  ListApi api = get_list_api();
  void *value = api.pop(data);

  while (value != NULL) {
    char *obj = serialize((StatData *)value);
    fprintf(stream, "%s\n", obj);
    value = api.pop(data);
    free(obj);
  }
}

List *load_dump(FILE *stream) {
  ListApi api = get_list_api();
  List *result = api.make_list();

  char *buffer = (char *)malloc(1024);
  while (fgets(buffer, 1024, stream) != 0) {
    StatData *data = deserialize(buffer);
    if (data != NULL) {
      api.append(result, data);
    }
  }

  return result;
}

DumpApi get_dump_api() {
  DumpApi api;
  api.store_dump = store_dump;
  api.load_dump = load_dump;

  return api;
}
