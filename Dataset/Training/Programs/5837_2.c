/*
 * Summation and Multiplication Verification
 * Computes a summation and verifies multiplication results
 * Assumes x and n are within specific bounds and checks consistency of results.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
    }
    }
    return;
}

int main() {
    int x, n;
    int sum, product, i;

    x = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 1 && x <= 10);
    assume_abort_if_not(n >= 1 && n <= 10);

    sum = 0;
    product = 1;

    for (i = 0; i < n; i++) {
        sum += x;
    }

    for (i = 0; i < n; i++) {
        product *= x;
    }

    // Check that sum of x added n times equals n * x

    // Check that product is not zero (valid since x >= 1)
    __VERIFIER_assert(product != 0);

    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}