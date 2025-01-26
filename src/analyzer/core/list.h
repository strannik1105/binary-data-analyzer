#ifndef CORE_LIST_H
#define CORE_LIST_H

typedef struct List List;

typedef struct ListApi {
  struct List *(*make_list)();
  void (*delete_list)(List *lst);
  void (*append)(List *lst, void *value);
  void *(*pop)(List *lst);
} ListApi;

ListApi get_list_api();

#endif