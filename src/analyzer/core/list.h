#ifndef CORE_LIST_H
#define CORE_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct List List;

/**
 * @brief апи списка, содержит функции для работы с ним
 * @param make_list создание списка
 * @param delete_list деструктор
 * @param append добавление значения в список
 * @param pop достаёт верхний элемент их списка. Значение из списка удаляется
 * @param contains проверяет содержится ли элемент в списке
 * @param size поулчение размера списка
 */
typedef struct ListApi {
  struct List *(*make_list)();
  void (*delete_list)(List *lst);
  void (*append)(List *lst, void *value);
  void (*sort_list)(struct List *list, bool (*gt)(void *value1, void *value2));
  void *(*pop)(List *lst);
  bool (*contains)(List *lst, void *value,
                   bool (*comparator)(void *value1, void *value2));
  size_t (*size)(List *lst);
} ListApi;

ListApi get_list_api();

#endif