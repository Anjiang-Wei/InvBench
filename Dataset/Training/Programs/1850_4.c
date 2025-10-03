// SPDX-License-Identifier: Apache-2.0
#include <assert.h>
#include <stdio.h>

// Verification-related functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, i;
    long long sum, product;

    // Initialize variables
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    sum = 0;
    product = 1;

    // Loop structure
    for (i = 1; i <= n; i++) {
        sum += i;
        product *= i;

        // Invariant: At every step, the sum should be the sum of the first i natural numbers

        // Invariant: Check for overflow condition, product should not be negative
    }

    // Post condition
    __VERIFIER_assert(product > 0);

    printf("Sum of first %d natural numbers: %lld\n", n, sum);
    printf("Product of first %d natural numbers: %lld\n", n, product);

    return 0;
}