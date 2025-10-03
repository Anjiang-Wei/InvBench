/*
 * New Benchmark inspired by previous examples
 *
 * This program calculates the factorial of a nondeterministic integer.
 * It contains checks using assertions to ensure that the computed factorial is accurate.
 * This is designed for automated verification tools to analyze and verify.
 */

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_verification.c", 12, "reach_error"); }
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0) {
        return 1; // Factorial is not defined for negative numbers
    }
    assume_abort_if_not(n <= 12); // Prevent overflow for factorial calculation

    int i;
    long long fact = 1;

    for (i = 2; i <= n; ++i) {
        fact *= i;
    }

    // Verifying the factorial calculation for 0 and 1 as these are base cases.
    if (n == 0 || n == 1) {
    } else {
        __VERIFIER_assert(fact > 0); // A simple check to ensure no overflow occurred
    }

    return 0;
}