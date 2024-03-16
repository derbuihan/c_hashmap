#include <stdio.h>

#include "hashmap.h"

int main(void) {
  int size = 100;
  struct HashMap *hashmap = newHashMap(size);

  insertToHashMap(hashmap, "key1", "value1");
  insertToHashMap(hashmap, "key1", "value2");
  insertToHashMap(hashmap, "key2", "value1");
  char *value = getValueFromHashMap(hashmap, "key1");
  printf("key1: %s\n", value);  // should be value2

  removeFromHashMap(hashmap, "key1");
  value = getValueFromHashMap(hashmap, "key1");
  printf("key1: %s\n", value);  // should be NULL

  freeHashMap(hashmap);
  return 0;
}
