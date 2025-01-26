#ifndef CORE_LIST_H
#define CORE_LIST_H

typedef struct List List;

/*
@brief апи списка, содержит функции для работы с ним
@param make_list создание списка
@param delete_list деструктор
@param append добавление значения в список
@param pop достаёт верхний элемент их списка. Значение из списка удаляется
*/
typedef struct ListApi {
  struct List *(*make_list)();
  void (*delete_list)(List *lst);
  void (*append)(List *lst, void *value);
  void *(*pop)(List *lst);
} ListApi;

ListApi get_list_api();

#endif