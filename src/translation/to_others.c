#include "../bigInteger.h"

#include<stdlib.h>
#include<stdint.h>
#include<string.h>


unsigned long bint_to_long(bint n) {
    int i;
    unsigned long ret = 0;

    for(i = n.len-1; i >= 0; i--) {
        ret *= BASE;
        ret += n.digits[i];
    }

    return ret;
}

int bint_to_str(char *ret, int size, bint a) {
    char *tmp;
    bint base_10 = long_to_bint(10);
    int len;
    int i, j;
    if((tmp = (char *)malloc(sizeof(char) * size)) == NULL) {
        return -1;
    }

    if(a.len == 0) {
        ret[0] = '0';
        ret[1] = '\n';
        return 0;
    }

    i = 0;
    while(a.len != 0) {
        if(i > size) return -1;
        tmp[i] = mod_bint(a, base_10).digits[0] + '0';
        a = div_bint(a, base_10);
        i++;
    }

    len = i;
    for(i = 0, j = len - 1; i < len; i++, j--) {
        ret[i] = tmp[j];
    }

    ret[len] = '\0';

    return 0;
}