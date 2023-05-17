#include "jsonprint.h"
#include <stdio.h>

void json_print(hashtable *ht) {
    hashitem item;
    printf("{");
    for (int i=0; i<ht->_cap; ++i) {
        vector *chain = ht->_table + i;
        for (int j=0; j<size_vector(chain); ++j) {
            get_vector(chain, j, &item);
            json_print_data(item.key.key, item.key.type);
            printf(":");
            json_print_data(item.value.value, item.value.type);
            printf(",");
        }
    }
    printf("}");
}

void json_print_vector(vector *vec) {
    // TODO
}

void json_print_data(void *data, valuetype type) {
    switch (type)
    {
    case INT8:
        printf("%d", *(int8_t *)data);
        break;
    case UINT8:
        printf("%u", *(uint8_t *)data);
        break;
    case INT16:
        printf("%d", *(int16_t *)data);
        break;
    case UINT16:
        printf("%u", *(uint16_t *)data);
        break;
    case INT32:
        printf("%d", *(int32_t *)data);
        break;
    case UINT32:
        printf("%u", *(uint32_t *)data);
        break;
    case INT64:
        printf("%lld", *(int64_t *)data);
        break;
    case UINT64:
        printf("%llu", *(uint64_t *)data);
        break;
    case CHAR_POINTER:
        printf("\"%s\"", *(char **)data);
        break;
    case VECTOR:
        json_print_vector((vector *)data);
        break;
    case HASH_TABLE:
        json_print((hashtable *)data);
        break;

    default:
        break;
    }

}