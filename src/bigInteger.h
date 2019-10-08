#pragma once

#ifndef _STDINT
// 他のヘッダのインクルード
#include<stdint.h>
#endif

#ifndef BIGINTEGER_H_
#define BIGINTEGER_H_

// 定数定義
#define DIGIT 1500
// 2^15より大きくすると除算がおかしくなる
#define BASE 32768 // 32768 = 2^15
// 除算、剰余の指定子
#define DIV 0
#define MOD 1

// マクロ
// bint変数初期化
#define INIT(x) for(int i = 0; i < DIGIT; i++) (x).digits[i] = 0

// 構造体
typedef struct natutal_number {
    int len;
    uint32_t digits[DIGIT];
} bint;

// 関数
// bint->long変換   return:変換後の値
unsigned long bint_to_long(bint n);
// long->bint変換   return:変換後の値
bint long_to_bint(long n);
// 文字列->bint変換   return:変換後の値
bint str_to_bint(char *str);
// bint->文字列変換   return:-1->失敗, 0->成功
int bint_to_str(char *ret, int size, bint a);

// bint加算   return:計算結果
bint add_bint(bint a, bint b);
// bint減算   return:計算結果
bint sub_bint(bint a, bint b);
// bint乗算   return:計算結果
bint mul_bint(bint a, bint b);
// bint除算   return:計算結果
bint div_bint(bint a, bint b);
// bint剰余   return:計算結果
bint mod_bint(bint a, bint b);
// bint左シフト   return:計算結果
bint left_shift(bint a, int n);
// bint右シフト   return:計算結果
bint right_shift(bint a, int n);
// baseのexp乗   return:計算結果
bint power_bint(bint base, int exp);

// bint比較   return: a>b -> 1, a=b -> 0, a<b -> -1
int comp_bint(bint a, bint b);

#endif
