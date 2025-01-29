#include "list.h"

#include <stdlib.h>

struct ListNode {
  void *value;
  struct ListNode *prev;
};

typedef struct ListNode ListNode;

struct List {
  ListNode *head;
  size_t size;
};

/*
@brief создание узла списка
@param value указатель на значение узла
@param prev указатель на предыдущий узел, может быть NULL
*/
static ListNode *make_node(void *value, ListNode *prev) {
  ListNode *node = (struct ListNode *)malloc(sizeof(struct List));
  node->value = value;
  node->prev = prev;
}

static List *make_list() {
  List *lst = (List *)malloc(sizeof(List));
  lst->head = NULL;
  lst->size = 0;

  return lst;
}

static void delete_list(List *lst) {
  ListNode *cur = lst->head;
  while (cur != NULL) {
    ListNode *prev = cur->prev;
    void *value = cur->value;

    free(cur);
    // TODO: передавать deleter для value
    // if (value != NULL)
    //     free(value);
    cur = prev;
  }
}

static void append(List *lst, void *value) {
  lst->size += 1;
  if (lst->head == NULL) {
    lst->head = make_node(value, NULL);
    return;
  }

  ListNode *new = make_node(value, lst->head);
  lst->head = new;
}

static void *pop(List *lst) {
  if (lst->head == NULL) return NULL;

  void *value = lst->head->value;
  ListNode *prev = lst->head->prev;
  free(lst->head);
  lst->head = prev;
  lst->size -= 1;

  return value;
}

static bool contains(List *lst, void *value,
                     bool (*comparator)(void *value1, void *value2)) {
  if (lst->head == NULL) return false;

  ListNode *cur = lst->head;
  while (cur != NULL) {
    if (comparator(cur->value, value)) {
      return true;
    }
    cur = cur->prev;
  }

  return false;
}

static size_t size(List *lst) { return lst->size; }

ListApi get_list_api() {
  ListApi api;
  api.make_list = make_list;
  api.delete_list = delete_list;
  api.append = append;
  api.pop = pop;
  api.contains = contains;
  api.size = size;

  return api;
}
