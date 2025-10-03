/*
Factorial Calculation and Verification

This program calculates the factorial of a number n (where 0 <= n <= 5) using an iterative approach.
Includes verification logic to ensure the correctness of the factorial calculation.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_verification.c", 7, "reach_error"); }
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

// Function to calculate factorial iteratively
int factorial(int n) {
    if (n < 0) {
        return -1; // Factorial is not defined for negative numbers
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();       // Non-deterministic input
    assume_abort_if_not(n >= 0 && n <= 5); // Assume constraints for n

    int computed_factorial = factorial(n);

    // Verify by comparing with manually calculated factorial values
    int expected_factorial[] = {1, 1, 2, 6, 24, 120}; // Factorials from 0! to 5!
    __VERIFIER_assert(computed_factorial == expected_factorial[n]);

    printf("Factorial of %d is %d\n", n, computed_factorial);

    return 0;
}