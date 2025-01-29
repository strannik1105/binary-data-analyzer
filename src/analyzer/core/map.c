#include "map.h"

#include <stddef.h>
#include <stdlib.h>

#include "list.h"

struct KeyType {
  long payload;
};

struct Map {
  void **values;
  List *keys;
  long size;

  long (*hash)(KeyType *key, long size);
};

static long def_hash(KeyType *key, long size) { return key->payload; }

static Map *create_map(long size, long (*hash)(KeyType *key, long size)) {
  Map *map = (Map *)malloc(sizeof(Map));
  map->values = malloc(sizeof(void *) * size);
  map->size = size;
  map->keys = get_list_api().make_list();
  if (hash == NULL)
    map->hash = def_hash;
  else
    map->hash = hash;
  return map;
}

static void insert(Map *map, long key, void *value) {
  ListApi api = get_list_api();
  KeyType *_key = malloc(sizeof(KeyType));
  _key->payload = key;

  long hashed_key = map->hash(_key, map->size);

  api.append(map->keys, _key);
  map->values[hashed_key] = value;
}

static bool comparator(void *value1, void *value2) {
  if (*(int *)value1 == *(int *)value2) return true;
  return false;
}

static void *get(Map *map, long key) {
  ListApi api = get_list_api();
  KeyType _key;
  _key.payload = key;

  long hashed_key = map->hash(&_key, map->size);

  if (api.contains(map->keys, &hashed_key, comparator)) {
    return map->values[hashed_key];
  }
  return NULL;
}

static List *values(Map *map) {
  ListApi api = get_list_api();
  List *lst = api.make_list();

  KeyType *key = api.pop(map->keys);
  while (key != NULL) {
    api.append(lst, map->values[key->payload]);
    key = api.pop(map->keys);
  }

  return lst;
}

MapApi get_map_api() {
  MapApi api;
  api.create_map = create_map;
  api.insert = insert;
  api.get = get;
  api.values = values;

  return api;
}
