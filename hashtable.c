#include "hashtable.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
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
    for (int i=0; i<ht->_cap; ++i) {
        init_vector(ht->_table + i, sizeof(hashitem));
    }
}

int close_hashitem(hashitem *item) {
    switch (item->key.type)
    {
    case STRING:
        // TODO
        fprintf(stderr, "Not yet string");
        exit(1);
        break;

    case INT8:
    case UINT8:
    case INT16:
    case UINT16:
    case INT32:
    case UINT32:
    case INT64:
    case UINT64:
    case CHAR_POINTER:
        free(item->key.key);
        break;
    default:
        fprintf(stderr, "Undefined Type");
        exit(1);
        break;
    }

    switch (item->value.type)
    {
    case STRING:
        // TODO
        fprintf(stderr, "Not yet string");
        exit(1);
        break;

    case INT8:
    case UINT8:
    case INT16:
    case UINT16:
    case INT32:
    case UINT32:
    case INT64:
    case UINT64:
    case CHAR_POINTER:
        free(item->value.value);
        break;
    
    case VECTOR:
        close_vector((vector *)item->value.value);
        break;
    
    case HASH_TABLE:
        close_hashtable((hashtable *)item->value.value);
        break;

    default:
        fprintf(stderr, "Undefined Type");
        exit(1);
        break;
    }
}

void close_hashtable(hashtable *ht) {
    for (int i=0; i<ht->_cap; ++i) {
        vector *chain = ht->_table + i;
        hashitem item;
        for (int i=0; i<size_vector(chain); ++i) {
            get_vector(chain, i, (void *) &item);
            close_hashitem(&item);
        }
        close_vector(chain);
    }
    free(ht->_table);
}

int size_hashtable(hashtable *ht) {
    return ht->_size;
}

int is_same_key_hashitem(hashitem *A, hashitem *B) {
    return is_same_key_hashable(&A->key, &B->key);
}

int is_same_key_hashable(hashable *A, hashable *B) {
    if (A->type != B->type) return false;
    switch (A->type)
    {
    case INT8:
        return *(int8_t *)A->key == *(int8_t *)B->key;
    case UINT8:
        return *(uint8_t *)A->key == *(uint8_t *)B->key;
    case INT16:
        return *(int16_t *)A->key == *(int16_t *)B->key;
    case UINT16:
        return *(uint16_t *)A->key == *(uint16_t *)B->key;
    case INT32:
        return *(int32_t *)A->key == *(int32_t *)B->key;
    case UINT32:
        return *(uint32_t *)A->key == *(uint32_t *)B->key;
    case INT64:
        return *(int64_t *)A->key == *(int64_t *)B->key;
    case UINT64:
        return *(uint64_t *)A->key == *(uint64_t *)B->key;
    case CHAR_POINTER:
        return strcmp(A->key, B->key) == 0;
    case STRING:
        fprintf(stderr, "Not yet");
        exit(1);
        break;
    default:
        break;
    }
}

uint64_t get_hash(hashable *key) {
    switch (key->type)
    {
    case INT8:
        return int_hash((uint64_t) *(int8_t *)key->key);
    case UINT8:
        return int_hash((uint64_t) *(uint8_t *)key->key);
    case INT16:
        return int_hash((uint64_t) *(int16_t *)key->key);
    case UINT16:
        return int_hash((uint64_t) *(uint16_t *)key->key);
    case INT32:
        return int_hash((uint64_t) *(int32_t *)key->key);
    case UINT32:
        return int_hash((uint64_t) *(uint32_t *)key->key);
    case INT64:
    case UINT64:
        return int_hash(*(uint64_t *)key->key);
    
    case CHAR_POINTER:
        return char_pointer_hash((char *)key->key);

    default:
        fprintf(stderr, "un hashable error");
        exit(1);
        break;
    }
}


int get_item_hashtable(hashtable *ht, hashable *key, hashitem *ret) {
    uint64_t hash_value = get_hash(ht);
    int idx = hash_value % ht->_cap;
    vector *chain = ht->_table + idx;
    for (int i=0; i<size_vector(chain); ++i) {
        hashitem hi;
        get_vector(chain, i, &hi);
        if (is_same_key_hashable(key, &hi.key)) {
            *ret = hi;
            return 1;
        }
    }
    return 0;
}

int set_item_hashtable(hashtable *ht, hashable *key, hashitem *item) {
    uint64_t hash_value = get_hash(ht);
    int idx = hash_value % ht->_cap;
    vector *chain = ht->_table + idx;
    for (int i=0; i<size_vector(chain); ++i) {
        hashitem hi;
        get_vector(chain, i, &hi);
        if (is_same_key_hashable(key, &hi.key)) 
            return 0;
    }
    push_back_vector(chain, (void *)item);
    ht->_size += 1;
}



#undef true
#undef false