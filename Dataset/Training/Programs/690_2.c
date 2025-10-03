#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, n, sum, product;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 50);

    sum = 0;
    product = 1;
    int i = 0;

    while (i < n) {
        sum += a;
        product *= b;

        if (product > 1000) {
            product = 1000; // saturation
        }

        i++;
    }

    __VERIFIER_assert(product <= 1000);

    return 0;
}