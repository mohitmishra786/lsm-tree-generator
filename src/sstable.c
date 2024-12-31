#include "sstable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct SSTable {
//     FILE* file;
//     char fname[256];
// };

SSTable* sstable_create(const char* fname) {
    SSTable* ss = malloc(sizeof(SSTable));
    if (!ss)
        return NULL;
    strncpy(ss->fname, fname, sizeof(ss->fname) - 1);
    ss->fname[sizeof(ss->fname) - 1] = '\0';
    ss->file = fopen(fname, "r");
    if (!ss->file) {
        free(ss);
        return NULL;
    }
    // Initialize Bloom filter parameters
    size_t size_bits = 1000000; // Adjust based on expected number of keys
    int num_hash_funcs = 5;
    ss->bloom_filter = bloom_filter_create(size_bits, num_hash_funcs);
    if (!ss->bloom_filter) {
        fclose(ss->file);
        free(ss);
        return NULL;
    }
    // Populate Bloom filter with keys from SSTable
    char line[256];
    while (fgets(line, sizeof(line), ss->file)) {
        char* value = strchr(line, '\t');
        if (value) {
            *value = '\0';
            bloom_filter_add(ss->bloom_filter, line);
        }
    }
    rewind(ss->file); // Reset file pointer for future reads
    return ss;
}

void sstable_destroy(SSTable* ss) {
    if (ss) {
        fclose(ss->file);
        bloom_filter_destroy(ss->bloom_filter);
        free(ss);
    }
}

const char* sstable_get(SSTable* ss, const char* key) {
    char line[256];
    rewind(ss->file);
    while (fgets(line, sizeof(line), ss->file)) {
        char* value = strchr(line, '\t');
        if (value) {
            *value = '\0';
            value++;
            if (strcmp(line, key) == 0) {
                return strdup(value);
            }
        }
    }
    return NULL;
}

bool sstable_merge(SSTable** ss_list, size_t count, const char* out_file) {
    FILE* out = fopen(out_file, "w");
    if (!out) return false;

    char** keys = malloc(count * sizeof(char*));
    char** values = malloc(count * sizeof(char*));
    if (!keys || !values) {
        fclose(out);
        free(keys);
        free(values);
        return false;
    }

    for (size_t i = 0; i < count; i++) {
        const char* temp_key = sstable_get(ss_list[i], ss_list[i]->fname);
        const char* temp_value = sstable_get(ss_list[i], ss_list[i]->fname);

        if (temp_key) {
            keys[i] = strdup(temp_key);
            if (!keys[i]) {
                for (size_t j = 0; j < i; j++) free(keys[j]);
                free(keys);
                free(values);
                fclose(out);
                return false;
            }
        } else {
            keys[i] = NULL;
        }

        if (temp_value) {
            values[i] = strdup(temp_value);
            if (!values[i]) {
                for (size_t j = 0; j <= i; j++) {
                    if (keys[j]) free(keys[j]);
                }
                free(keys);
                for (size_t j = 0; j < i; j++) free(values[j]);
                free(values);
                fclose(out);
                return false;
            }
        } else {
            values[i] = NULL;
        }
    }

    // Simple merge logic assuming sorted SSTables
    for (size_t i = 0; i < count; i++) {
        if (keys[i] && values[i]) {
            fprintf(out, "%s\t%s\n", keys[i], values[i]);
            free(keys[i]);
            free(values[i]);
        }
    }
    fclose(out);
    free(keys);
    free(values);
    return true;
}
