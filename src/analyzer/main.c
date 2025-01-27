#include <stdio.h>

#include "core/dump.h"
#include "core/list.h"
#include "core/stat_data.h"

int main() {
  FILE *f;
  ListApi list_api = get_list_api();
  DumpApi dump_api = get_dump_api();

  StatData obj1;
  obj1.id = 1;
  obj1.count = 1;
  obj1.cost = 1.1;
  obj1.primary = 0;
  obj1.mode = 1;

  StatData obj2;
  obj2.id = 2;
  obj2.count = 2;
  obj2.cost = 2.2;
  obj2.primary = 0;
  obj2.mode = 1;

  List *lst = list_api.make_list();
  printf("append1\n");
  list_api.append(lst, &obj1);
  printf("append2\n");
  list_api.append(lst, &obj2);
  f = fopen("t.txt", "w");
  dump_api.store_dump(lst, f);
  fclose(f);
  list_api.delete_list(lst);

  f = fopen("t.txt", "r");
  lst = dump_api.load_dump(f);
  fclose(f);
  printf("pop1: %ld\n", ((StatData *)list_api.pop(lst))->id);
  printf("pop2: %ld\n", ((StatData *)list_api.pop(lst))->id);

  return 0;
}