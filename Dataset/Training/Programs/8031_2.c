#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error() { assert(0); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int m, n, sum, product;
    m = __VERIFIER_nondet_int();
    assume_abort_if_not(m > 0);

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    sum = 0;
    product = 1;

    while (__VERIFIER_nondet_bool()) {
        if (m <= 0 || n <= 0) {
            break;
        }

        // Simple arithmetic operations
        sum += m + n;
        product *= m;

        // Decrement m and n to eventually end the loop
        m--;
        n--;
    }

    // Final checks to ensure sums and products are within expected bounds
    __VERIFIER_assert(product >= 1);

    // Additional debug print statements
    printf("Final sum: %d\n", sum);
    printf("Final product: %d\n", product);

    return 0;
}