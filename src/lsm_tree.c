#include "lsm_tree.h"
#include "memtable.h"
#include "sstable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SSTABLE_NAME "sstable_%d.txt"

struct LSMTree {
    MemTable* memtable;
    SSTable** sstables;
    int sstable_count;
};

LSMTree* lsm_tree_init() {
    LSMTree* lsm = malloc(sizeof(LSMTree));
    if (!lsm) return NULL;
    lsm->memtable = memtable_create(100); // Arbitrary capacity
    if (!lsm->memtable) {
        free(lsm);
        return NULL;
    }
    lsm->sstables = NULL;
    lsm->sstable_count = 0;
    return lsm;
}

void lsm_tree_destroy(LSMTree* lsm) {
    memtable_destroy(lsm->memtable);
    for (int i = 0; i < lsm->sstable_count; i++) {
        sstable_destroy(lsm->sstables[i]);
    }
    free(lsm->sstables);
    free(lsm);
}

bool lsm_insert(LSMTree* lsm, const char* key, const char* value) {
    if (lsm->memtable == NULL || memtable_is_full(lsm->memtable)) {
        lsm_compact(lsm);
    }
    return memtable_insert(lsm->memtable, key, value);
}

const char* lsm_get(LSMTree* lsm, const char* key) {
    const char* value = memtable_get(lsm->memtable, key);
    if (value) return value;

    for (int i = lsm->sstable_count - 1; i >= 0; i--) {
        value = sstable_get(lsm->sstables[i], key);
        if (value) return value;
    }
    return NULL;
}

bool lsm_delete(LSMTree* lsm, const char* key) {
    if (memtable_delete(lsm->memtable, key)) return true;
    // Deletion from SSTable is complex and often involves tombstoning which isn't implemented here
    return false; // Placeholder for now
}

void lsm_compact(LSMTree* lsm) {
    char fname[256];
    snprintf(fname, sizeof(fname), SSTABLE_NAME, lsm->sstable_count);
    memtable_flush(lsm->memtable, fname);
    memtable_destroy(lsm->memtable);
    lsm->memtable = memtable_create(100);

    lsm->sstable_count++;
    lsm->sstables = realloc(lsm->sstables, lsm->sstable_count * sizeof(SSTable*));
    lsm->sstables[lsm->sstable_count - 1] = sstable_create(fname);
}