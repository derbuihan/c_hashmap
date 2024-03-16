#ifndef HASHMAP_H
#define HASHMAP_H

struct Entry {
  char *key;
  char *value;
  struct Entry *next;  // for chaining
};

struct HashMap {
  struct Entry **entries;
  int size;  // size of entries
};

struct HashMap *newHashMap(const int size);
void insertToHashMap(const struct HashMap *hashmap, const char *key,
                     const char *value);
char *getValueFromHashMap(const struct HashMap *hashmap, const char *key);
void freeHashMap(struct HashMap *hashmap);
int removeFromHashMap(const struct HashMap *hashmap, const char *key);

#endif  // HASHMAP_H
