#include"../src/bigInteger.h"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_OF_TEST 10

int32_t fermat_test(int n) {
    int i;
    int a;

    srand((unsigned)time(NULL));

    for(i = 0; i < NUM_OF_TEST; i++) {
        a = 2 + (rand() % (n - 2));
        if(bint_to_long(mod_bint(power_bint(long_to_bint(a), n-1), long_to_bint(n))) != 1) {
            return 0;
        }
    }
    return 1;
}

void main() {
    long n = 1;
    int ret;
    clock_t start, end;

    while(1){
        printf("素数判定を行います(終了->0)："); scanf("%ld", &n);
        if(n == 0) {
            break;
        } else if(n == 1) {
            printf("1は素数ではありません。\n");
            continue;
        } else if(n == 2) {
            printf("2は素数です。\n");
            continue;
        }

        start = clock();
        ret = fermat_test(n);
        end = clock();

        if(ret) {
            printf("%ldは確率的素数です。\n", n);
            printf("time:%.10lf\n", (double)(end - start) / CLOCKS_PER_SEC);
        } else {
            printf("%ldは素数ではありません。\n", n);
        }
    }
}