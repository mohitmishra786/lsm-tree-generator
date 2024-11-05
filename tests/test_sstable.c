#include <CUnit/Basic.h>
#include "../include/sstable.h"
#include <stdio.h>
#include <stdlib.h>

void test_create_sstable() {
    FILE* temp = fopen("test_sstable.txt", "w");
    fprintf(temp, "key1\tvalue1\nkey2\tvalue2\n");
    fclose(temp);

    SSTable* ss = sstable_create("test_sstable.txt");
    CU_ASSERT_PTR_NOT_NULL(ss);
    sstable_destroy(ss);
    remove("test_sstable.txt");
}

void test_get_sstable() {
    FILE* temp = fopen("test_sstable.txt", "w");
    fprintf(temp, "key1\tvalue1\nkey2\tvalue2\n");
    fclose(temp);

    SSTable* ss = sstable_create("test_sstable.txt");
    CU_ASSERT_STRING_EQUAL(sstable_get(ss, "key1"), "value1");
    CU_ASSERT_STRING_EQUAL(sstable_get(ss, "key2"), "value2");
    CU_ASSERT_PTR_NULL(sstable_get(ss, "key3"));
    sstable_destroy(ss);
    remove("test_sstable.txt");
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("SSTable Suite", NULL, NULL);

    CU_add_test(suite, "test create sstable", test_create_sstable);
    CU_add_test(suite, "test get from sstable", test_get_sstable);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}