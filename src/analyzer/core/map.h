#ifndef CORE_MAP_H
#define CORE_MAP_H

#include <stddef.h>

typedef struct KeyType KeyType;

typedef struct Map Map;

typedef struct List List;

/**
 * @brief апи map. На данный момент представляет из себя упрощённый
 * std::unordered_map
 * @param create_map создание маппы, если hash не передан, то используеся
 * функция по-умолчанию
 * @param insert вставка значения
 * @param get получение значения по ключу
 * @param values получение всех значений списка
 */
typedef struct MapApi {
  Map *(*create_map)(long size, long (*hash)(KeyType *key, long size));
  void (*insert)(Map *map, long key, void *value);
  void *(*get)(Map *map, long key);
  List *(*values)(Map *map);
} MapApi;

MapApi get_map_api();

#endif
