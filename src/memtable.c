#include "memtable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct MemTable {
    char** keys;
    char** values;
    size_t size;
    size_t capacity;
};

MemTable* memtable_create(size_t capacity) {
    MemTable* mt = malloc(sizeof(MemTable));
    if (!mt) return NULL;
    mt->keys = malloc(capacity * sizeof(char*));
    mt->values = malloc(capacity * sizeof(char*));
    if (!mt->keys || !mt->values) {
        free(mt->keys);
        free(mt->values);
        free(mt);
        return NULL;
    }
    mt->size = 0;
    mt->capacity = capacity;
    return mt;
}

void memtable_destroy(MemTable* mt) {
    for (size_t i = 0; i < mt->size; i++) {
        free(mt->keys[i]);
        free(mt->values[i]);
    }
    free(mt->keys);
    free(mt->values);
    free(mt);
}

bool memtable_insert(MemTable* mt, const char* key, const char* value) {
    if (mt->size >= mt->capacity || !key || !value) return false;
    mt->keys[mt->size] = strdup(key);
    mt->values[mt->size] = strdup(value);
    if (!mt->keys[mt->size] || !mt->values[mt->size]) {
        free(mt->keys[mt->size]);
        free(mt->values[mt->size]);
        return false;
    }
    mt->size++;
    return true;
}

const char* memtable_get(MemTable* mt, const char* key) {
    for (size_t i = 0; i < mt->size; i++) {
        if (strcmp(mt->keys[i], key) == 0) {
            return mt->values[i];
        }
    }
    return NULL;
}

bool memtable_delete(MemTable* mt, const char* key) {
    for (size_t i = 0; i < mt->size; i++) {
        if (strcmp(mt->keys[i], key) == 0) {
            free(mt->keys[i]);
            free(mt->values[i]);
            mt->keys[i] = mt->keys[mt->size - 1];
            mt->values[i] = mt->values[mt->size - 1];
            mt->size--;
            return true;
        }
    }
    return false;
}

bool memtable_is_full(MemTable* mt) {
    return mt->size >= mt->capacity;
}

void memtable_flush(MemTable* mt, const char* fname) {
    FILE* file = fopen(fname, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    for (size_t i = 0; i < mt->size; i++) {
        fprintf(file, "%s\t%s\n", mt->keys[i], mt->values[i]);
    }
    fclose(file);
}