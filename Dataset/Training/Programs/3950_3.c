#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
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

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    unsigned int m, n;
    long long a, b, sum;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m > 0 && n > 0 && m <= 10 && n <= 10);

    a = 0;
    b = 1;
    sum = 0;

    while (a < m) {

        sum += b;
        b += 1;
        a += 1;
    }

    long long product = 1;
    for (unsigned int i = 1; i <= n; i++) {
        product *= i;
        __VERIFIER_assert(product > 0);
    }

    printf("Final sum: %lld\n", sum);
    printf("Final product: %lld\n", product);

    return 0;
}