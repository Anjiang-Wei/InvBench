#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n, a, b, sum, prod, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100);

    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 1 && a <= 100);

    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 1 && b <= 100);

    sum = 0;
    prod = 1;

    for (i = 0; i < n; ++i) {
        // Random computation of sum and product
        sum += a;
        prod *= b;

        // Ensure the sum does not overflow
        __VERIFIER_assert(sum >= 0);

        // Ensure the product does not overflow

        if (sum > 10000 || prod > 100000) {
            break;
        }
    }

    printf("Final Sum: %d\n", sum);
    printf("Final Product: %d\n", prod);

    return 0;
}