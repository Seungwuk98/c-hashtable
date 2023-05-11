#include "hashtable.h"
#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0

static uint16_t HASH_KEY_SIZE_TABLE[30];
static uint16_t HASH_VALUE_SIZE_TABLE[30];

static int HASH_TABLE_SIZE[] = {
    53, 107, 223, 449, 907, 1823, 3659, 7321, 14653, 29311, 
    58631, 117269, 234539, 469099, 938207, 1876417, 3752839, 7505681,
};

__attribute__ ((constructor)) 
void __set_hash_key_size_table() {
    HASH_KEY_SIZE_TABLE[INT8]           = sizeof(int8_t); 
    HASH_KEY_SIZE_TABLE[UINT8]          = sizeof(uint8_t);
    HASH_KEY_SIZE_TABLE[INT16]          = sizeof(int16_t);         
    HASH_KEY_SIZE_TABLE[UINT16]         = sizeof(uint16_t);     
    HASH_KEY_SIZE_TABLE[INT32]          = sizeof(int32_t);     
    HASH_KEY_SIZE_TABLE[UINT32]         = sizeof(uint32_t);     
    HASH_KEY_SIZE_TABLE[INT64]          = sizeof(int64_t);     
    HASH_KEY_SIZE_TABLE[UINT64]         = sizeof(uint64_t);     
    HASH_KEY_SIZE_TABLE[CHAR_POINTER]   = sizeof(char *);   
    HASH_KEY_SIZE_TABLE[STRING]         = sizeof(NULL); // not yet          
}

__attribute__((constructor))
void __set_hash_value_size_table() {
    HASH_VALUE_SIZE_TABLE[INT8]         = sizeof(int8_t); 
    HASH_VALUE_SIZE_TABLE[UINT8]        = sizeof(uint8_t);
    HASH_VALUE_SIZE_TABLE[INT16]        = sizeof(int16_t);
    HASH_VALUE_SIZE_TABLE[UINT16]       = sizeof(uint16_t);
    HASH_VALUE_SIZE_TABLE[INT32]        = sizeof(int32_t);
    HASH_VALUE_SIZE_TABLE[UINT32]       = sizeof(uint32_t);
    HASH_VALUE_SIZE_TABLE[INT64]        = sizeof(int64_t);
    HASH_VALUE_SIZE_TABLE[UINT64]       = sizeof(uint64_t);
    HASH_VALUE_SIZE_TABLE[CHAR_POINTER] = sizeof(char *);
    HASH_VALUE_SIZE_TABLE[STRING]       = sizeof(NULL); // NOT YET
    HASH_VALUE_SIZE_TABLE[VECTOR]       = sizeof(vector);
    HASH_VALUE_SIZE_TABLE[HASH_TABLE]   = sizeof(hashtable);
}

uint16_t hash_key_size(valuetype type) {
    return HASH_KEY_SIZE_TABLE[type];
}

uint16_t hash_value_size(valuetype type) {
    return HASH_VALUE_SIZE_TABLE[type];
}

void init_hashtable(hashtable *ht) {
    ht->_size = 0;
    ht->_cap_idx = 0;
    ht->_cap = HASH_TABLE_SIZE[0];
    ht->_table = malloc(sizeof(vector) * ht->_cap);
}

int should_be_closed(valuetype type) {
    switch (type)
    {
    case VECTOR:
        return 1;
        break;
    case HASH_TABLE:
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

void close_hashtable(hashtable *ht) {
    for (int i=0; i<ht->_cap; ++i) {
        vector *vec = ht->_table + i;
    }

}


#undef true
#undef false