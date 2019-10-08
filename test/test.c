#include "../src/bigInteger.h"

#include<stdio.h>

void main() {
    bint n1, n2, ans_add, ans_sub, ans_mul, ans_div, mod, check, lshift, rshift, ans_pow;
    unsigned long a, b, c;
    char str1_r[10000]; // , str2_r[50], ans2[100];

    char str1[] = "451";// "1234567898765432123456789";
    char str2[] = "12345678987654321234567898765432123456788";// "12345678987654321";
    int ex = 100;

    printf("base:%s\n", str1);
    printf("exp:%d\n", ex);
    // printf("%s\n", str2);

    // 文字列->bint
    n1 = str_to_bint(str1);
    n2 = str_to_bint(str2);

    // long型->bint型変換
    // a = 12345;
    // n1 = long_to_bint(a);
    // b = 0;
    // n2 = long_to_bint(b);

    // a = bint_to_long(n1);
    // b = bint_to_long(n2);
    // printf("a:%d\n", a);
    // printf("b:%d\n", b);

    // for(int i = 0; i < 3; i++) {
    //     if(comp_bint(n1, n2) == 0) {
    //         puts("equal");
    //     } else if(comp_bint(n1, n2) == 1) {
    //         puts("a > b");
    //     } else if(comp_bint(n1, n2) == -1) {
    //         puts("b > a");
    //     }
    //     n2 = add_bint(n2, long_to_bint(1));
    // }

    // シフト演算
    // printf("左シフト前:");
    // for(int i = n1.len - 1; i >= 0 ; i--) {
    //     printf("%lu ", (uint32_t)n1.digits[i]);
    // }
    // putchar('\n');
    // printf("左シフト後:");
    // lshift = left_shift(n1, 2);
    // for(int i = lshift.len - 1; i >= 0 ; i--) {
    //     printf("%lu ", (uint32_t)lshift.digits[i]);
    // }
    // putchar('\n');
    // printf("右シフト前:");
    // for(int i = n2.len - 1; i >= 0 ; i--) {
    //     printf("%lu ", (uint32_t)n2.digits[i]);
    // }
    // putchar('\n');
    // rshift = right_shift(n1, 2);
    // printf("右シフト後:");
    // for(int i = rshift.len - 1; i >= 0 ; i--) {
    //     printf("%lu ", (uint32_t)rshift.digits[i]);
    // }
    // putchar('\n');

    // 四則演算
    // ans_add = add_bint(n1, n2);
    // ans_sub = sub_bint(n1, n2);
    // ans_mul = mul_bint(n1, n2);
    // ans_div = div_bint(n1, n2);
    // mod = mod_bint(n1, n2);

    // 除算、剰余の検算
    // check = add_bint(mul_bint(n2, ans_div), mod);

    ans_pow = power_bint(n1, ex);

    // 計算結果表示
    // if(bint_to_str(str1_r, 100, ans_add) == -1) {
    //     puts("領域確保失敗");
    // } else {
    //     printf("ans_add:%s\n", str1_r);
    // }
    // if(bint_to_str(str1_r, 100, ans_sub) == -1) {
    //     puts("領域確保失敗");
    // } else {
    //     printf("ans_sub:%s\n", str1_r);
    // }
    // if(bint_to_str(str1_r, 100, ans_mul) == -1) {
    //     puts("領域確保失敗");
    // } else {
    //     printf("ans_mul:%s\n", str1_r);
    // }
    // if(bint_to_str(str1_r, 100, ans_div) == -1) {
    //     puts("領域確保失敗");
    // } else {
    //     printf("ans_div:%s\n", str1_r);
    // }
    // if(bint_to_str(str1_r, 100, mod) == -1) {
    //     puts("領域確保失敗");
    // } else {
    //     printf("mod:%s\n", str1_r);
    // }
    // if(bint_to_str(str1_r, 100, check) == -1) {
    //     puts("領域確保失敗");
    // } else {
    //     printf("check:%s\n", str1_r);
    // }
    if(bint_to_str(str1_r, 10000, ans_pow) == -1) {
        puts("領域確保失敗");
    } else {
        printf("power:%s\n", str1_r);
    }
}
