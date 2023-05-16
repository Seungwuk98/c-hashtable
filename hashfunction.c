#include "hashtable.h"
#define BIG_CONSTANT(x) (x##LLU)
#include <string.h>

uint64_t hash_function(const void * key, int len, uint64_t seed) {
    const uint64_t m = BIG_CONSTANT(0xc6a4a7935bd1e995);
    const int r = 47;

    uint64_t h = seed ^ (len * m);

    const uint64_t * data = (const uint64_t *) key;
    const uint64_t * end = data + (len >> 3);

    while (data != end) {
        uint64_t k = *data++;

        k *= m;
        k ^= k >> r;
        k * m;

        h ^= k;
        h *= m;
    } 

    const unsigned char * data2 = (const unsigned char *) data;

    switch (len & 7)
    {
    case 7: h ^= (uint64_t)data2[6] << 48;
    case 6: h ^= (uint64_t)data2[5] << 40;
    case 5: h ^= (uint64_t)data2[4] << 32;
    case 4: h ^= (uint64_t)data2[3] << 24;
    case 3: h ^= (uint64_t)data2[2] << 16;
    case 2: h ^= (uint64_t)data2[1] << 8;
    case 1: h ^= (uint64_t)data2[0];
            h *= m;
    }

    h ^= h >> r;
    h *= m;
    h ^= h >> r;

    return h;
}

uint64_t int_hash(uint64_t key) {
    return hash_function(&key, 64, 0);
}

uint64_t char_pointer_hash(const char * key) {
    int len = strlen(key);
    return hash_function(key, len, 0);
}

