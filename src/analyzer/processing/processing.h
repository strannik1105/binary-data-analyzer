#ifndef PROCESSING_H
#define PROCESSING_H

typedef struct List List;

typedef struct ProcessingApi {
  List *(*join_dump)(List *lst1, List *lst2);
  List *(*sort_dump)(List *lst);
} ProcessingApi;

ProcessingApi get_processing_api();

#endif
