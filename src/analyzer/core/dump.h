#ifndef CORE_DUMP_H
#define CORE_DUMP_H

#include <stdio.h>

typedef struct List List;

typedef struct DumpApi {
  /**
   * @brief сохранение массива StatData в файл
   * @param data список объектов StatData
   * @param stream файловы поток для вывода
   */
  void (*store_dump)(struct List *data, FILE *stream);
  List *(*load_dump)(FILE *stream);
} DumpApi;

DumpApi get_dump_api();

#endif
