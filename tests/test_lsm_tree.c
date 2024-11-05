#include <CUnit/Basic.h>
#include "../include/lsm_tree.h"
#include <stdio.h>
#include <stdlib.h>

void test_lsm_create_destroy() {
    LSMTree* lsm = lsm_tree_init();
    CU_ASSERT_PTR_NOT_NULL(lsm);
    lsm_tree_destroy(lsm);
}

void test_lsm_insert_get() {
    LSMTree* lsm = lsm_tree_init();
    CU_ASSERT_TRUE(lsm_insert(lsm, "key1", "value1"));
    CU_ASSERT_STRING_EQUAL(lsm_get(lsm, "key1"), "value1");
    lsm_tree_destroy(lsm);
}

void test_lsm_compact() {
    LSMTree* lsm = lsm_tree_init();
    for (int i = 0; i < 101; i++) { // Assuming memtable size is 100
        char key[10], value[10];
        sprintf(key, "key%d", i);
        sprintf(value, "value%d", i);
        lsm_insert(lsm, key, value);
    }
    lsm_compact(lsm); // This should flush the memtable to an SSTable

    CU_ASSERT_STRING_EQUAL(lsm_get(lsm, "key0"), "value0"); // This should come from the SSTable
    CU_ASSERT_STRING_EQUAL(lsm_get(lsm, "key100"), "value100"); // This should come from the new memtable

    lsm_tree_destroy(lsm);
    remove("sstable_0.txt"); // Clean up
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("LSMTree Suite", NULL, NULL);

    CU_add_test(suite, "test create and destroy lsm tree", test_lsm_create_destroy);
    CU_add_test(suite, "test insert and get from lsm tree", test_lsm_insert_get);
    CU_add_test(suite, "test lsm compaction", test_lsm_compact);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}