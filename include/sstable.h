#ifndef SSTABLE_H
#define SSTABLE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h> // Add this include for FILE
#include "bloom_filter.h"

typedef struct SSTable {
    FILE* file;
    char fname[256];
    BloomFilter* bloom_filter;
} SSTable;

SSTable* sstable_create(const char* fname);
void sstable_destroy(SSTable* ss);
const char* sstable_get(SSTable* ss, const char* key);
bool sstable_merge(SSTable** ss_list, size_t count, const char* out_file);

#endif // SSTABLE_H
