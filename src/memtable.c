#include "memtable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
    for (size_t i = 0; i < mt->size; i++) {
        if (strcmp(mt->keys[i], key) == 0) {
            free(mt->values[i]);
            mt->values[i] = strdup(value);
            return true;
        }
    }
    if (mt->size >= mt->capacity) {
        mt->capacity *= 2;
        mt->keys = realloc(mt->keys, mt->capacity * sizeof(char*));
        mt->values = realloc(mt->values, mt->capacity * sizeof(char*));
        if (!mt->keys || !mt->values) {
            return false;
        }
    }
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
            for (size_t j = i; j < mt->size - 1; j++) {
                mt->keys[j] = mt->keys[j + 1];
                mt->values[j] = mt->values[j + 1];
            }
            mt->size--;
            i--;
        }
    }
    return true;
}

bool memtable_is_full(MemTable* mt) {
    return mt->size >= mt->capacity;
}

void memtable_sort(MemTable* mt) {
    for (size_t i = 0; i < mt->size - 1; i++) {
        for (size_t j = 0; j < mt->size - i - 1; j++) {
            if (strcmp(mt->keys[j], mt->keys[j + 1]) > 0) {
                char* temp_key = mt->keys[j];
                char* temp_value = mt->values[j];
                mt->keys[j] = mt->keys[j + 1];
                mt->values[j] = mt->values[j + 1];
                mt->keys[j + 1] = temp_key;
                mt->values[j + 1] = temp_value;
            }
        }
    }
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
