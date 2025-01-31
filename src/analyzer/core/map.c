#include "map.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "list.h"

struct KeyType {
  long payload;
  long hashed;
};

typedef struct KeyValue {
  KeyType key;
  void *value;
} KeyValue;

struct Map {
  List **buckets;
  long size;
  long (*hash)(KeyType *key, long size);
};

static long def_hash(KeyType *key, long size) {
  const long PRIME = 11400714819323198549ULL;
  long hash = key->payload;

  hash ^= hash >> 33;
  hash *= PRIME;
  hash ^= hash >> 29;
  hash *= PRIME;
  hash ^= hash >> 32;

  return (hash % size);
}

static Map *create_map(long size, long (*hash)(KeyType *key, long size)) {
  Map *map = (Map *)malloc(sizeof(Map));
  if (!map) return NULL;

  ListApi api = get_list_api();
  map->buckets = (List **)malloc(sizeof(List *) * size);
  if (!map->buckets) {
    free(map);
    return NULL;
  }

  for (long i = 0; i < size; i++) {
    map->buckets[i] = api.make_list();
    if (!map->buckets[i]) {
      // Если создание списка провалилось, очищаем уже созданные
      for (long j = 0; j < i; j++) {
        api.delete_list(map->buckets[j]);
      }
      free(map->buckets);
      free(map);
      return NULL;
    }
  }

  map->size = size;
  map->hash = hash ? hash : def_hash;
  return map;
}

static bool key_comparator(void *value1, void *value2) {
  KeyValue *kv = (KeyValue *)value1;
  KeyType *key = (KeyType *)value2;
  return kv->key.payload == key->payload;
}

static void insert(Map *map, long key, void *value) {
  if (!map) return;

  ListApi api = get_list_api();
  KeyType new_key = {key, map->hash(&(KeyType){key}, map->size)};
  List *bucket = map->buckets[new_key.hashed];

  // Проверяем, есть ли уже такой ключ
  if (api.contains(bucket, &new_key, key_comparator)) {
    return;  // Не перезаписываем, если ключ уже есть
  }

  // Создаём новый элемент и добавляем в список
  KeyValue *kv = (KeyValue *)malloc(sizeof(KeyValue));
  if (!kv) return;

  kv->key = new_key;
  kv->value = value;
  api.append(bucket, kv);
}

static void *get(Map *map, long key) {
  if (!map) return NULL;

  ListApi api = get_list_api();
  KeyType search_key = {key, map->hash(&(KeyType){key}, map->size)};
  List *bucket = map->buckets[search_key.hashed];

  List *temp = api.make_list();
  void *found_value = NULL;

  // Перебираем элементы списка и ищем нужный ключ
  while (api.size(bucket) > 0) {
    KeyValue *kv = (KeyValue *)api.pop(bucket);
    if (kv->key.payload == key) {
      found_value = kv->value;
    }
    api.append(temp, kv);
  }

  // Восстанавливаем bucket
  while (api.size(temp) > 0) {
    api.append(bucket, api.pop(temp));
  }

  api.delete_list(temp);
  return found_value;
}

static List *values(Map *map) {
  if (!map) return NULL;

  ListApi api = get_list_api();
  List *result = api.make_list();
  if (!result) return NULL;

  for (long i = 0; i < map->size; i++) {
    List *bucket = map->buckets[i];

    List *temp = api.make_list();

    while (api.size(bucket) > 0) {
      KeyValue *kv = (KeyValue *)api.pop(bucket);
      api.append(result, kv->value);
      api.append(temp, kv);
    }

    // Восстанавливаем bucket
    while (api.size(temp) > 0) {
      api.append(bucket, api.pop(temp));
    }

    api.delete_list(temp);
  }

  return result;
}

static void delete_map(Map *map) {
  if (!map) return;

  ListApi api = get_list_api();
  for (long i = 0; i < map->size; i++) {
    List *bucket = map->buckets[i];
    while (api.size(bucket) > 0) {
      KeyValue *kv = (KeyValue *)api.pop(bucket);
      free(kv);
    }
    api.delete_list(bucket);
  }

  free(map->buckets);
  free(map);
}

MapApi get_map_api() {
  MapApi api;
  api.create_map = create_map;
  api.insert = insert;
  api.get = get;
  api.values = values;
  return api;
}
