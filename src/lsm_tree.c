#include "lsm_tree.h"
#include "memtable.h"
#include "sstable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DELETED_VALUE "__DELETED__"

// struct LSMTree {
//     MemTable* memtable;
//     SSTable** sstables;
//     int sstable_count;
//     int compact_count; // New counter for compacted SSTables
// };

LSMTree* lsm_tree_init() {
    LSMTree* lsm = malloc(sizeof(LSMTree));
    if (!lsm) return NULL;
    lsm->memtable = memtable_create(100);
    if (!lsm->memtable) {
        free(lsm);
        return NULL;
    }
    lsm->sstables = NULL;
    lsm->sstable_count = 0;
    lsm->compact_count = 0; // Initialize compact counter
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
    if (memtable_is_full(lsm->memtable)) {
        lsm_compact(lsm);
    }
    return memtable_insert(lsm->memtable, key, value);
}

const char* lsm_get(LSMTree* lsm, const char* key) {
    const char* value = memtable_get(lsm->memtable, key);
    if (value) {
        if (strcmp(value, DELETED_VALUE) == 0) {
            return NULL;
        }
        return value;
    }
    for (int i = lsm->sstable_count - 1; i >= 0; i--) {
        value = sstable_get(lsm->sstables[i], key);
        if (value) return value;
    }
    return NULL;
}

bool lsm_delete(LSMTree* lsm, const char* key) {
    return memtable_insert(lsm->memtable, key, DELETED_VALUE);
}

void lsm_compact(LSMTree* lsm) {
    MemTable* temp_mt = memtable_create(1000);
    if (!temp_mt) {
        return;
    }
    // Merge existing SSTables
    for (int i = 0; i < lsm->sstable_count; i++) {
        SSTable* ss = lsm->sstables[i];
        char line[256];
        rewind(ss->file);
        while (fgets(line, sizeof(line), ss->file)) {
            char* value = strchr(line, '\t');
            if (value) {
                *value = '\0';
                value++;
                size_t len = strlen(value);
                if (len > 0 && value[len - 1] == '\n') {
                    value[len - 1] = '\0';
                }
                memtable_insert(temp_mt, line, value);
            }
        }
    }
    // Merge memtable, excluding deletions
    for (size_t i = 0; i < lsm->memtable->size; i++) {
        if (strcmp(lsm->memtable->values[i], DELETED_VALUE) != 0) {
            memtable_insert(temp_mt, lsm->memtable->keys[i], lsm->memtable->values[i]);
        }
    }
    // Sort the merged memtable
    memtable_sort(temp_mt);
    // Flush to a new compacted SSTable with unique name
    char new_sstable_name[256];
    snprintf(new_sstable_name, sizeof(new_sstable_name), "sstable_compacted_%d.txt", lsm->compact_count);
    memtable_flush(temp_mt, new_sstable_name);
    memtable_destroy(temp_mt);
    // Remove old SSTables and update pointers
    for (int i = 0; i < lsm->sstable_count; i++) {
        fclose(lsm->sstables[i]->file);
        remove(lsm->sstables[i]->fname);
        free(lsm->sstables[i]);
    }
    free(lsm->sstables);
    lsm->sstables = NULL;
    lsm->sstable_count = 0;
    // Create a new SSTable from the compacted file
    SSTable* new_ss = sstable_create(new_sstable_name);
    if (!new_ss) {
        fprintf(stderr, "Failed to create new SSTable from compacted file.\n");
        return;
    }
    lsm->sstables = malloc(sizeof(SSTable*));
    lsm->sstables[0] = new_ss;
    lsm->sstable_count = 1;
    lsm->compact_count++; // Increment compact counter
    memtable_destroy(lsm->memtable);
    lsm->memtable = memtable_create(100);
}
