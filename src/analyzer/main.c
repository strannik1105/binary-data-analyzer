#include <stdio.h>

#include "core/list.h"
#include "core/stat_data.h"

int main() {
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

  ListApi api = get_list_api();
  List *lst = api.make_list();
  printf("append1\n");
  api.append(lst, &obj1);
  printf("append2\n");
  api.append(lst, &obj2);

  printf("pop1: %ld\n", ((StatData *)api.pop(lst))->id);
  printf("pop2: %ld\n", ((StatData *)api.pop(lst))->id);

  api.delete_list(lst);
  return 0;
}