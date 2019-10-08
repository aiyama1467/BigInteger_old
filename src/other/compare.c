#include "../bigInteger.h"

#include<stdlib.h>
#include<stdint.h>
#include<string.h>


int comp_bint(bint a, bint b) {
    int al = a.len, bl = b.len;
    int i;

    if(al == 0) {
        if(bl > 0) {
            return -1;
        } else {
            return 0;
        }
    }

    if(al > bl) {
        return 1;
    } else if(al < bl) {
        return -1;
    } else {
        i = al - 1;
        while(i >= 0){
            if(a.digits[i] > b.digits[i]) {
                return 1;
            } else if(a.digits[i] < b.digits[i]) {
                return -1;
            }
            i--;
        }
    }

    return 0;
}