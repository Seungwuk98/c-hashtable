#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__
#include "vector.h"
#include <stdint.h>

typedef struct _hashtable {
    vector *_table;
    int _size;
    int _cap;
    int _cap_idx;
} hashtable;

typedef enum _type {
    INT8 = 0,
    UINT8,
    INT16,
    UINT16,
    INT32,
    UINT32,
    INT64,
    UINT64,
    CHAR_POINTER,
    STRING,
    VECTOR,
    HASH_TABLE,
} valuetype;

typedef struct _hashable {
    valuetype type;
    void * key;
} hashable;

typedef struct _hashvalue {
    valuetype type;
    void * value;
} hashvalue;

typedef struct _hashitem {
    hashable key;
    hashvalue value;
} hashitem;

uint64_t int_hash(uint64_t key);
uint64_t char_pointer_hash(const char * key);
uint16_t hash_value_size(valuetype type);
uint16_t hash_key_size(valuetype type);

void init_hashtable(hashtable *ht);
void close_hashtable(hashtable *ht);

int is_same_key_hashitem(hashitem *A, hashitem *B);
int is_same_key_hashable(hashable *A, hashable *B);

int get_item_hashtable(hashtable *ht, hashable *key, hashitem *ret);
int set_item_hashtable(hashtable *ht, hashable *key, hashitem *item);

int set_item_by_key_value(hashtable *ht, void * key, valuetype key_type, void * value, valuetype value_type);
int get_item_by_key(hashtable *ht, void * key, valuetype type, hashvalue *ret);

int size_hashtable(hashtable *ht);
int copy_hashtable(hashtable *ret, hashtable *ht);


#endif