#include <CUnit/Basic.h>
#include "../include/memtable.h"

void test_create_destroy() {
    MemTable* mt = memtable_create(10);
    CU_ASSERT_PTR_NOT_NULL(mt);
    memtable_destroy(mt);
}

void test_insert_get() {
    MemTable* mt = memtable_create(10);
    CU_ASSERT_TRUE(memtable_insert(mt, "key1", "value1"));
    CU_ASSERT_STRING_EQUAL(memtable_get(mt, "key1"), "value1");
    memtable_destroy(mt);
}

void test_delete() {
    MemTable* mt = memtable_create(10);
    memtable_insert(mt, "key", "value");
    CU_ASSERT_TRUE(memtable_delete(mt, "key"));
    CU_ASSERT_PTR_NULL(memtable_get(mt, "key"));
    memtable_destroy(mt);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("MemTable Suite", NULL, NULL);

    CU_add_test(suite, "test create and destroy", test_create_destroy);
    CU_add_test(suite, "test insert and get", test_insert_get);
    CU_add_test(suite, "test delete", test_delete);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}