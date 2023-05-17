#include "hashtable.h"
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
int main() {
    fprintf(stderr, "%d\n", hash_key_size(INT8));
    assert(hash_key_size(INT8)          == sizeof(int8_t));
    assert(hash_key_size(UINT8)         == sizeof(uint8_t));
    assert(hash_key_size(INT16)         == sizeof(int16_t));
    assert(hash_key_size(UINT16)        == sizeof(uint16_t));
    assert(hash_key_size(INT32)         == sizeof(int32_t));
    assert(hash_key_size(UINT32)        == sizeof(uint32_t));
    assert(hash_key_size(INT64)         == sizeof(int64_t));
    assert(hash_key_size(UINT64)        == sizeof(uint64_t));
    assert(hash_key_size(CHAR_POINTER)  == sizeof(char **));
    assert(hash_key_size(STRING)        == sizeof(NULL)); // not yet
    
    assert(hash_value_size(INT8)        == sizeof(int8_t));
    assert(hash_value_size(UINT8)       == sizeof(uint8_t));
    assert(hash_value_size(INT16)       == sizeof(int16_t));
    assert(hash_value_size(UINT16)      == sizeof(uint16_t));
    assert(hash_value_size(INT32)       == sizeof(int32_t));
    assert(hash_value_size(UINT32)      == sizeof(uint32_t));
    assert(hash_value_size(INT64)       == sizeof(int64_t));
    assert(hash_value_size(UINT64)      == sizeof(uint64_t));
    assert(hash_value_size(CHAR_POINTER)== sizeof(char **));
    assert(hash_value_size(STRING)      == sizeof(NULL)); // not yet
    assert(hash_value_size(HASH_TABLE)  == sizeof(hashtable));
    assert(hash_value_size(VECTOR)      == sizeof(vector));

}