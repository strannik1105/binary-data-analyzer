#ifndef PROCESSING_H
#define PROCESSING_H

typedef struct List List;

typedef struct ProcessingApi {
  List *(*join_list)(List *lst1, List *lst2);
} ProcessingApi;

ProcessingApi get_processing_api();

#endif
