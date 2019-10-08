#include "../bigInteger.h"

#include<stdlib.h>
#include<stdint.h>
#include<string.h>


bint power_bint(bint base, int exp) {
    bint ret = long_to_bint(1);
    bint t = base;

    while(exp){
        if(exp & 1) {
            ret = mul_bint(ret, t);
        }
        t = mul_bint(t, t);
        exp /= 2;
    }

    return ret;
}