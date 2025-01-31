#include "processing.h"

#include <stdlib.h>

#include "core/list.h"
#include "core/map.h"
#include "core/stat_data.h"

static List *join_dump(List *list1, List *list2) {
  ListApi lst_api = get_list_api();
  MapApi map_api = get_map_api();

  if (!list1 || !list2) return NULL;  // Проверка входных параметров

  Map *map =
      map_api.create_map(lst_api.size(list1) + lst_api.size(list2) + 1, NULL);
  if (!map) return NULL;

  List *result = lst_api.make_list();
  if (!result) {
    free(map);
    return NULL;
  }

  StatData *data1;
  while ((data1 = lst_api.pop(list1)) != NULL) {
    StatData *value = (StatData *)map_api.get(map, data1->id);
    if (value) {
      value->cost += data1->cost;
    } else {
      map_api.insert(map, data1->id, data1);
    }
  }

  StatData *data2;
  while ((data2 = lst_api.pop(list2)) != NULL) {
    StatData *value = (StatData *)map_api.get(map, data2->id);
    if (value) {
      value->cost += data2->cost;
    } else {
      map_api.insert(map, data2->id, data2);
    }
  }

  result = map_api.values(map);
  free(map);  // Освобождаем Map после извлечения значений
  return result;
}

static bool gt(void *val1, void *val2) {
  if (((StatData *)val1)->cost > ((StatData *)val2)->cost) return true;
  return false;
}

static List *sort_dump(List *lst) {
  ListApi api = get_list_api();
  api.sort_list(lst, gt);
  return lst;
}

ProcessingApi get_processing_api() {
  ProcessingApi api;
  api.join_dump = join_dump;
  api.sort_dump = sort_dump;

  return api;
}
