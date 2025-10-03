/*
 * This is a C program featuring a loop that applies simple arithmetic computations
 * and conditional logic. It involves a nondeterministic input and uses a pattern
 * similar to the provided examples for verification purposes.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_example.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int n, z;
    long long sum, product;

    // Nondeterministic input
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1);

    sum = 0;
    product = 1;

    // Loop with arithmetic computations and conditional logic
    for (z = 1; z <= n; z++) {
        if (z % 2 == 0) {
            sum += z;
        } else {
            product *= z;
        }
    }

    // Verification condition
    __VERIFIER_assert(sum >= 0);

    printf("Sum of even numbers: %lld\n", sum);
    printf("Product of odd numbers: %lld\n", product);

    return 0;
}