#include "../bigInteger.h"

#include<stdlib.h>
#include<stdint.h>
#include<string.h>


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