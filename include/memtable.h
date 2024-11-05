#ifndef MEMTABLE_H
#define MEMTABLE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct MemTable {
    char** keys;
    char** values;
    size_t size;
    size_t capacity;
} MemTable;

MemTable* memtable_create(size_t capacity);
void memtable_destroy(MemTable* mt);
bool memtable_insert(MemTable* mt, const char* key, const char* value);
const char* memtable_get(MemTable* mt, const char* key);
bool memtable_delete(MemTable* mt, const char* key);
bool memtable_is_full(MemTable* mt);
void memtable_flush(MemTable* mt, const char* fname);

#endif // MEMTABLE_H