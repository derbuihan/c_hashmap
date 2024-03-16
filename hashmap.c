#include "hashmap.h"

#include <stdlib.h>
#include <string.h>

struct HashMap *newHashMap(const int size) {
  struct HashMap *hashmap = malloc(sizeof(struct HashMap));
  hashmap->size = size;

  // initialize entries
  hashmap->entries = malloc(sizeof(struct Entry) * size);
  for (int i = 0; i < size; i++) {
    hashmap->entries[i] = NULL;
  }

  return hashmap;
}

static unsigned int hash(const char *key, const int size) {
  unsigned int hash = 0;
  for (int i = 0; key[i] != '\0'; i++) {
    hash = 31 * hash + key[i];
  }
  return hash % size;
}

void insertToHashMap(const struct HashMap *hashmap, const char *key,
                     const char *value) {
  int index = hash(key, hashmap->size);

  // check if key already exists
  struct Entry *entry = hashmap->entries[index];
  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      free(entry->value);
      entry->value = strdup(value);
      return;
    }
    entry = entry->next;
  }

  // create new entry
  entry = malloc(sizeof(struct Entry));
  entry->key = strdup(key);
  entry->value = strdup(value);
  entry->next = hashmap->entries[index];  // for chaining
  hashmap->entries[index] = entry;
}

char *getValueFromHashMap(const struct HashMap *hashmap, const char *key) {
  int index = hash(key, hashmap->size);

  struct Entry *entry = hashmap->entries[index];
  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      return entry->value;
    }
    entry = entry->next;
  }

  return NULL;
}

static void freeEntry(struct Entry *entry) {
  while (entry != NULL) {
    struct Entry *next = entry->next;
    free(entry->key);
    free(entry->value);
    free(entry);
    entry = next;
  }
}

void freeHashMap(struct HashMap *hashmap) {
  for (int i = 0; i < hashmap->size; i++) {
    freeEntry(hashmap->entries[i]);
  }
  free(hashmap->entries);
  free(hashmap);
}

int removeFromHashMap(const struct HashMap *hashmap, const char *key) {
  int index = hash(key, hashmap->size);
  struct Entry *entry = hashmap->entries[index];

  // find the entry and its predecessor
  struct Entry *pred = NULL;
  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      break;
    }
    pred = entry;
    entry = entry->next;
  }

  if (entry == NULL) return -1;
  if (pred == NULL) {  // entry is the first in the list
    hashmap->entries[index] = entry->next;
  } else {  // entry is not the first in the list
    pred->next = entry->next;
  }

  free(entry->key);
  free(entry->value);
  free(entry);

  return 0;
}