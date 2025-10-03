#include <stdio.h>
#include <stdlib.h>

// Generate error if condition is false
extern void abort(void);
void reach_error() { abort(); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Verify a condition
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// Entry point
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n, sum = 0, product = 1;

    assume_abort_if_not(a >= 0 && b >= 0); // Ensure non-negative inputs

    // Read a non-deterministic value for n
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100); // Assumed range for n

    // Compute the sum of numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    // Calculate the product of a range reduced by b within the range [1, n]
    for (int i = 1; i <= n - b; i++) {
        product *= (a + i);
    }

    printf("Sum: %d, Product: %d\n", sum, product);

    // Assert that the product is never zero for valid non-zero inputs
    if (a > 0) {
        __VERIFIER_assert(product != 0);
    }

    return 0;
}