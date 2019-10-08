#include "../bigInteger.h"

#include<stdlib.h>
#include<stdint.h>
#include<string.h>


bint add_bint(bint a, bint b) {
    int i;
    int len;
    bint ret;
    ret.len = 0;
    uint32_t x = 0;

    INIT(ret);

    if(a.len >= b.len) {
        len = a.len;
    } else {
        len = b.len;
    }

    for(i = 0; i <= len; i++) {
        if(i < a.len) {
            x += a.digits[i];
        }
        if(i < b.len) {
            x += b.digits[i];
        }

        if(x < BASE) {
            ret.digits[i] = x;
            ret.len++;
            x = 0;
        } else {
            ret.digits[i] = x - BASE;
            ret.len++;
            x = 1;
        }
    }
    if(ret.digits[i - 1] == 0) {
        ret.len--;
    }

    return ret;
}
