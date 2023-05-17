#ifndef __JSON_PRINT_H__
#define __JSON_PRINT_H__
#include "hashtable.h"

void json_print(hashtable *ht);
void json_print_data(void *data, valuetype type);

#endif