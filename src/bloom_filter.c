#include "bloom_filter.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

// Hash functions
static uint32_t djb2_hash(const char* str) {
    uint32_t hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

static uint32_t fnv1a_hash(const char* str) {
    uint32_t hash = 2166136261u;
    int c;
    while ((c = *str++))
        hash = (hash ^ c) * 16777619;
    return hash;
}

// Bloom filter functions
BloomFilter* bloom_filter_create(size_t size_bits, int num_hash_funcs) {
    BloomFilter* bf = malloc(sizeof(BloomFilter));
    if (!bf)
        return NULL;
    bf->bits = calloc((size_bits + 7) / 8, 1);
    if (!bf->bits) {
        free(bf);
        return NULL;
    }
    bf->size_bits = size_bits;
    bf->num_hash_funcs = num_hash_funcs;
    return bf;
}

void bloom_filter_add(BloomFilter* bf, const char* key) {
    for (int i = 0; i < bf->num_hash_funcs; i++) {
        uint32_t hash = djb2_hash(key) + i * fnv1a_hash(key);
        size_t bit_index = hash % bf->size_bits;
        bf->bits[bit_index / 8] |= (1 << (bit_index % 8));
    }
}

bool bloom_filter_check(BloomFilter* bf, const char* key) {
    for (int i = 0; i < bf->num_hash_funcs; i++) {
        uint32_t hash = djb2_hash(key) + i * fnv1a_hash(key);
        size_t bit_index = hash % bf->size_bits;
        if (!(bf->bits[bit_index / 8] & (1 << (bit_index % 8))))
            return false;
    }
    return true;
}

void bloom_filter_destroy(BloomFilter* bf) {
    free(bf->bits);
    free(bf);
}
