#include "../bigInteger.h"

#include<stdlib.h>
#include<stdint.h>
#include<string.h>


bint left_shift(bint a, int n) {
    bint ret;
    ret.len = a.len + n;
    int i;

    INIT(ret);

    if(a.len == 0) {
        return a;
    }

    i = a.len - 1;
    while(i >= 0){
        ret.digits[i + n] = a.digits[i];
        i--;
    }
    i = n - 1;
    while(i >= 0){
        ret.digits[i] = 0;
        i--;
    }

    return ret;
}


bint right_shift(bint a, int n) {
    bint ret;
    int i;

    INIT(ret);

    if(a.len <= n) {
        return a;
    } else {
        ret.len = a.len - n;
    }

    i = ret.len - 1;
    while(i >= 0){
        ret.digits[i] = a.digits[i + n];
        i--;
    }

    return ret;
}
