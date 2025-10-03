/*
 * A program that calculates the factorial of a number using an iterative approach
 * and applies a series of operations to transform each factorial result.
 * Designed for analysis and verification by automated verification tools.
 */

#include <stdio.h>
#include <stdlib.h>

// Abstract verification functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_ops.c", 6, "reach_error"); }
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
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Limiting n to prevent overflow of factorial calculations

    int factorial[1];
    factorial[0] = 1;

    // Calculate factorial of n iteratively
    for (int i = 1; i <= n; i++) {
        factorial[0] *= i;
    }

    // Apply some transformations to factorial results
    int transformed = factorial[0];
    int iterations = __VERIFIER_nondet_int();
    assume_abort_if_not(iterations >= 1 && iterations <= 10); // Limit the number of iterations

    for (int i = 0; i < iterations; i++) {
        if (transformed % 2 == 0) {
            transformed /= 2;
        } else {
            transformed = (transformed * 3) + 1;
        }
    }

    // Verification step to ensure the program runs correctly
    __VERIFIER_assert(transformed >= 0);

    // Output the results
    printf("Factorial of %d = %d\n", n, factorial[0]);
    printf("Transformed result after operations = %d\n", transformed);

    return 0;
}