#ifndef CDS_HASHMAP_H_
#define CDS_HASHMAP_H_

#include <stdlib.h>

typedef struct HashEntry {
  void* key;
  void value;
} HashEntry;

typedef struct HashMap {
  size_t map_size;
  size_t value_size;
  size_t key_size;

  size_t table_size;
  HashEntry* table;
} HashMap;

HashMap* hashmap_create();

int hashmap_insert(void* key, void* value);
void* hashmap_get(void* key);
int hashmap_remove(void* key);

#endif // CDS_HASHMAP_H_
