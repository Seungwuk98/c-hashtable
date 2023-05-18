#include "hashtable.h"
#include <assert.h>
#include <stdio.h>

int main() {
    hashtable _ht;
    hashtable *ht = &_ht;
    init_hashtable(ht);
    /** Test1 */
    int a = 1, b = 2;
    set_item_by_key_value(ht, &a, INT32, &b, INT32);
    
    int c = 1;
    hashvalue value;
    get_item_by_key(ht, &c, INT32, &value);
    
    assert(value.type == INT32);
    assert(*(int32_t *)value.value == b);
    /** Test1 */

    /** Test2 */
    const char * str = "my string";
    int k = 3;
    set_item_by_key_value(ht, (void *)&str, CHAR_POINTER, &k, INT32);
    
    get_item_by_key(ht, (void *)&str, CHAR_POINTER, &value);
    assert(value.type == INT32);
    printf("value.value : %d, k : %d\n", *(int32_t *)value.value, k);
    // assert(*(int32_t *)value.value == k);

    // const char * str2 = "my string";
    // k = 8;
    // set_item_by_key_value(ht, (void *)&str2, CHAR_POINTER, &k, INT32);

    // get_item_by_key(ht, (void *)&str, CHAR_POINTER, &value);
    // assert(value.type == INT32);
    // assert(*(int32_t *)value.value == k);

    // get_item_by_key(ht, (void *)&str2, CHAR_POINTER, &value);
    // assert(value.type == INT32);
    // assert(*(int32_t *)value.value == k);
    /** End Test2 */

    close_hashtable(ht);
}