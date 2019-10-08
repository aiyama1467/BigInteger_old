#include "../bigInteger.h"

#include<stdlib.h>
#include<stdint.h>
#include<string.h>


bint long_to_bint(long n) {
    bint ret;
    ret.len = 0;
    int i;

    INIT(ret);

    i = 0;
    while(n != 0){
        ret.len++;
        ret.digits[i] = n % BASE;
        n /= BASE;
        i++;
    }

    return ret;
}


bint str_to_bint(char *str) {
    int s_length = strlen(str);
    bint ret;
    ret.len = 0;
    bint base = long_to_bint(10);
    bint digit = long_to_bint(1);
    int i;

    INIT(ret);

    for(i = 0; i < s_length; i++) {
        if('0' < str[i] && str[i] <= '9') {
            digit.digits[0] = str[i] - '0';
            digit.len = 1;
        } else if(str[i] == '0') {
            digit.digits[0] = '0';
            digit.len = 0;
        } else {
            continue;
        }
        ret = mul_bint(ret, base);
        ret = add_bint(ret, digit);
    }

    return ret;
}
