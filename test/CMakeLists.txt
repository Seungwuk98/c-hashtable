set(HASH_TABLE_KEY_VALUE_SIZE_TEST HashTableKeyValueSizeTest)
set(HASH_TABLE_GET_ITEM_TEST HashTableGetItemTest)
set(JSON_PRINT_TEST JsonPrintTest)

add_executable(${HASH_TABLE_KEY_VALUE_SIZE_TEST} 
    hashtable_key_value_size_test.c
    )
add_executable(${HASH_TABLE_GET_ITEM_TEST}
    hashtable_get_item_test.c
    )
add_executable(${JSON_PRINT_TEST} 
    jsonprint_test.c)



target_link_libraries(${HASH_TABLE_KEY_VALUE_SIZE_TEST} PUBLIC ${HASH_TABLE_LIBRARY})
target_link_libraries(${HASH_TABLE_GET_ITEM_TEST} PUBLIC ${HASH_TABLE_LIBRARY})
target_link_libraries(${JSON_PRINT_TEST} PUBLIC ${HASH_TABLE_LIBRARY})

add_test(NAME ${HASH_TABLE_KEY_VALUE_SIZE_TEST} COMMAND HashTableKeyValueSizeTest)
add_test(NAME ${HASH_TABLE_GET_ITEM_TEST} COMMAND HashTableGetItemTest)
add_test(NAME ${JSON_PRINT_TEST} COMMAND JsonPrintTest)