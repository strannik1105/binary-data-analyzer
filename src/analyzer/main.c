#include <stdio.h>

#include "core/dump.h"
#include "core/list.h"
#include "core/stat_data.h"
#include "processing/processing.h"

int main() {
  FILE *f;
  ListApi list_api = get_list_api();
  DumpApi dump_api = get_dump_api();
  ProcessingApi processing_api = get_processing_api();

  StatData obj1;
  obj1.id = 1;
  obj1.count = 1;
  obj1.cost = 1.1;
  obj1.primary = 0;
  obj1.mode = 1;

  StatData obj2;
  obj2.id = 3;
  obj2.count = 2;
  obj2.cost = 2.2;
  obj2.primary = 0;
  obj2.mode = 1;

  StatData obj3;
  obj3.id = 4;
  obj3.count = 1;
  obj3.cost = 1.1;
  obj3.primary = 0;
  obj3.mode = 1;

  StatData obj4;
  obj4.id = 2;
  obj4.count = 2;
  obj4.cost = 2.2;
  obj4.primary = 0;
  obj4.mode = 1;

  List *lst1 = list_api.make_list();
  list_api.append(lst1, &obj1);
  list_api.append(lst1, &obj2);
  list_api.append(lst1, &obj3);
  list_api.append(lst1, &obj4);

  List *lst2 = list_api.make_list();

  StatData obj5;
  obj5.id = 1;
  obj5.count = 1;
  obj5.cost = 1.1;
  obj5.primary = 0;
  obj5.mode = 1;

  StatData obj6;
  obj6.id = 2;
  obj6.count = 2;
  obj6.cost = 2.2;
  obj6.primary = 0;
  obj6.mode = 1;

  list_api.append(lst2, &obj5);
  list_api.append(lst2, &obj6);

  List *joined_lst = processing_api.join_dump(lst1, lst2);
  processing_api.sort_dump(joined_lst);

  f = fopen("result.txt", "w");
  dump_api.store_dump(joined_lst, f);
  fclose(f);

  list_api.delete_list(joined_lst);

  return 0;
}