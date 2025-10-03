#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error(void) { assert(0); }

// Custom assert function
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // Declare variables
    int a = 0, b = 0, n;
    long long factorial = 1, power_sum = 1;

    // Input: n is non-deterministically assigned and constrained
    n = __VERIFIER_nondet_int();

    // Assume n is within a reasonable range for calculations
    if (n < 0 || n > 15) {
        return 0; // Exit if the assumption doesn't hold
    }

    // Loop to calculate factorial of a and power sum of b
    for (a = 1; a <= n; a++) {
        factorial *= a; // Calculate a!
    }

    for (b = 1; b <= n; b++) {
        power_sum += b * b; // Calculate sum of squares (1^2 + 2^2 + ... + b^2)
    }

    // Additional constraint after the loop
    __VERIFIER_assert(factorial > 0);

    // Output results
    printf("Factorial of %d: %lld\n", n, factorial);
    printf("Sum of squares up to %d: %lld\n", n, power_sum);

    return 0;
}