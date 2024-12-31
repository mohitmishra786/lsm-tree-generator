#ifndef LSM_TREE_H
#define LSM_TREE_H

#include <stdbool.h>
#include "memtable.h"
#include "sstable.h"

typedef struct LSMTree {
    MemTable* memtable;
    SSTable** sstables;
    int sstable_count;
    int compact_count;
} LSMTree;

LSMTree* lsm_tree_init();
void lsm_tree_destroy(LSMTree* lsm);
bool lsm_insert(LSMTree* lsm, const char* key, const char* value);
const char* lsm_get(LSMTree* lsm, const char* key);
bool lsm_delete(LSMTree* lsm, const char* key);
void lsm_compact(LSMTree* lsm);

#endif // LSM_TREE_H
