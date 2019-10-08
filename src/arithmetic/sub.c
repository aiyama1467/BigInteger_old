#include "../bigInteger.h"

#include<stdlib.h>
#include<stdint.h>
#include<string.h>


bint sub_bint(bint a, bint b) {
    bint ret;
    ret.len = 0;
    uint32_t x;
    int i;

    INIT(ret);

    int compare = comp_bint(a, b);
    if(compare == -1 || compare == 0) {
        return ret;
    }

    x = 0;
    for(i = 0; i < a.len; i++) {
        if(i < b.len) {
            x += b.digits[i];
        }

        if(a.digits[i] >= x) {
            ret.digits[i] = a.digits[i] - x;
            ret.len++;
            x = 0;
        } else {
            ret.digits[i] = (BASE - x) + a.digits[i];
            ret.len++;
            x = 1;
        }
    }
    i = ret.len - 1;
    while(ret.digits[i] == 0) {
        ret.len--;
        i--;
    }

    return ret;
}
