#include "../bigInteger.h"

#include<stdlib.h>
#include<stdint.h>
#include<string.h>


bint mul_bint(bint a, bint b) {
    bint zero, ret, tmp;
    zero.len = 0; ret.len = 0;
    int i, j;

    INIT(ret);

    if(a.len == 0 || b.len == 0) {
        INIT(zero);
        return zero;
    }

    for(i = 0; i < b.len; i++) {
        for(j = 0; j < a.len; j++) {
            tmp = long_to_bint(a.digits[j] * b.digits[i]);
            tmp = left_shift(tmp, i + j);
            ret = add_bint(ret, tmp);
        }
    }

    return ret;
}