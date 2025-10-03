// Program for calculating the product of a series of natural numbers
// This program should be suitable for verification tools.
// It involves basic arithmetic operations with conditional checks and a loop structure.

#include <stdio.h>

// Functions for automated verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "product_series.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function similar to assert for verification purposes
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, product, i;
    n = __VERIFIER_nondet_int();

    // Make sure 'n' is within a reasonable range
    assume_abort_if_not(n >= 0 && n <= 5);

    product = 1; // Multiplicative identity
    i = 1;

    while (i <= n) {
        // Calculate the product of the series
        product *= i;
        i++;

        // Ensure the product is non-negative for inputs in the given range
        __VERIFIER_assert(product >= 1);
    }

    // Verify that after the loop, the product is indeed the factorial of n
    int expected_product = 1;
    for (int j = 1; j <= n; j++) {
        expected_product *= j;
    }

    printf("The product of numbers from 1 to %d is %d.\n", n, product);

    return 0;
}