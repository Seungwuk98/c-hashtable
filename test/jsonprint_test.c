#include "jsonprint.h"
#include <stdio.h>

int main() {
    hashtable _ht, _ht2;
    hashtable *ht = &_ht, *ht2 = &_ht2;
    init_hashtable(ht);
    init_hashtable(ht2);

    int data = 8;
    const char *str = "abcd";
    set_item_by_key_value(ht, (void *)&data, INT32, (void *)&str, CHAR_POINTER);
    set_item_by_key_value(ht, (void *)&str, CHAR_POINTER, (void *)&data, INT32);    


    int t = 735235;
    const char *str2 = "uubd";
    set_item_by_key_value(ht2, (void *)&t, INT32, (void *)&str2, CHAR_POINTER);
    set_item_by_key_value(ht2, (void *)&str2, CHAR_POINTER, (void *)&t, INT32);

    const char *str3 = "data";

    set_item_by_key_value(ht, (void *)&str3, CHAR_POINTER, (void *)ht2, HASH_TABLE);

    json_print(ht);

    close_hashtable(ht);
}