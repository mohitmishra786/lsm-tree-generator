enable_testing()
find_package(CUnit REQUIRED)

# Test files
file(GLOB TEST_SOURCES "*.c")

# Link each test against the lsm_tree library
foreach(test_src ${TEST_SOURCES})
    get_filename_component(test_name ${test_src} NAME_WE)
    add_executable(${test_name} ${test_src} ../src/memtable.c ../src/sstable.c ../src/lsm_tree.c)
    target_link_libraries(${test_name} ${CUNIT_LIBRARIES})
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()