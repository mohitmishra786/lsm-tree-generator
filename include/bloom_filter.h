#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct {
    unsigned char* bits;
    size_t size_bits;
    int num_hash_funcs;
} BloomFilter;

BloomFilter* bloom_filter_create(size_t size_bits, int num_hash_funcs);
void bloom_filter_add(BloomFilter* bf, const char* key);
bool bloom_filter_check(BloomFilter* bf, const char* key);
void bloom_filter_destroy(BloomFilter* bf);

#endif
