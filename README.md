# C HashMap Implementation

This is an implementation of a basic HashMap data structure written in C. HashMaps in C are a way of storing data in key-value pairs and provide efficient insertion, deletion and retrieval operations.

## Features

- This HashMap implementation uses chaining to resolve collisions.
- Basic operations such as insertion (`insertToHashMap`), deletion (`removeFromHashMap`), retrieval (`getValueFromHashMap`), and freeing the used memory (`freeHashMap`).
- A function to create a new HashMap (`newHashMap`).

## Functions

- `struct HashMap *newHashMap(int size);`
- `void insertToHashMap(struct HashMap *hashmap, char *key, char *value);`
- `char *getValueFromHashMap(struct HashMap *hashmap, char *key);`
- `void freeHashMap(struct HashMap *hashmap);`
- `int removeFromHashMap(struct HashMap *hashmap, char *key);`

## Example Use

```C
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

```

## How to Build

The HashMap implementation is contained in a single C source file. There are no external dependencies. Compile using your favorite C compiler.

## License

[MIT](https://choosealicense.com/licenses/mit/)
