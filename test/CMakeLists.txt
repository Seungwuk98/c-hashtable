set(HASH_TABLE_KEY_VALUE_SIZE_TEST HashTableKeyValueSizeTest)

add_executable(${HASH_TABLE_KEY_VALUE_SIZE_TEST} 
    hashtable_key_value_size_test.c
    )


target_link_libraries(${HASH_TABLE_KEY_VALUE_SIZE_TEST} PUBLIC ${HASH_TABLE_LIBRARY})

add_test(NAME ${HASH_TABLE_KEY_VALUE_SIZE_TEST} COMMAND HashTableKeyValueSizeTest)