#include "bigInteger.h"

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

bint div_mod_bint(bint a, bint b, int mode) {
    int32_t d;
    bint u, u_tmp, v;
    bint tmp;
    bint ret;
    int32_t q_, r_;
    bint base = long_to_bint(BASE);
    int i;
    int m = a.len - b.len, n = b.len;

    INIT(ret);

    if(comp_bint(a, b) == -1) {
        if(mode == MOD) {
            return a;
        } else {
            return long_to_bint(0);
        }
    } else if(comp_bint(a, b) == 0) {
        if(mode == MOD) {
            return long_to_bint(0);
        } else {
            return long_to_bint(1);
        }
    } else if(b.len == 0) {
        return long_to_bint(0);
    }

    // 正規化(割られる数の桁が割る数の桁より大きくなるように調整する)
    d = BASE / (b.digits[b.len - 1] + 1);
    u = mul_bint(a, long_to_bint(d));
    v = mul_bint(b, long_to_bint(d));

    v.digits[v.len] = 0;
    ret.len = m + 1;
    for(i = m; i >= 0; i--) {
        q_ = u.digits[n + i] * BASE + u.digits[n + i - 1];
        q_ = q_ / v.digits[n - 1];

        r_ = u.digits[n + i] * BASE + u.digits[n + i - 1] - q_ * v.digits[n - 1];

        while(q_ == BASE || ((n - 2 >= 0) && (q_ * v.digits[n - 2]) > (BASE * r_ + u.digits[i + n - 2]))) {
            q_--;
            r_ += v.digits[n - 2];
            if(r_ >= BASE) {
                break;
            }
        }

        u_tmp = right_shift(u, i);
        tmp = mul_bint(long_to_bint(q_), v);

        if(comp_bint(u_tmp, tmp) != -1) {
            u = sub_bint(u, left_shift(tmp, i));
        } else {
            q_--;
            tmp = mul_bint(long_to_bint(q_), v);
            u = sub_bint(u, left_shift(tmp, i));
        }

        ret.digits[i] = q_;
    }

    if(ret.digits[m] == 0) {
        ret.len--;
    }

    if(mode == MOD) {
        return div_bint(u, long_to_bint(d));
    } else {
        return ret;
    }
}

bint div_bint(bint a, bint b) {
    return div_mod_bint(a, b, DIV);
}

bint mod_bint(bint a, bint b) {
    return div_mod_bint(a, b, MOD);
}

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