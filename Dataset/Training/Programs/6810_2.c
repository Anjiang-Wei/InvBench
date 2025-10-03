/*
Factorial Calculation with Verification
This program calculates the factorial of a number using iteration.
*/

#include <stdio.h>
#include <stdlib.h>

/* Verification and error handling functions */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 8, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int n;
    long long factorial, i;

    // Get a non-deterministic integer input
    n = __VERIFIER_nondet_int();

    // Ensure n is within a reasonable range
    if (n < 0 || n > 20) {
        // Avoid extreme computations or negative values
        return 1;
    }

    factorial = 1;
    i = 1;

    // Calculate factorial using a loop
    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verify the factorial for some basic cases
    if (n == 0 || n == 1) {
    } else if (n == 5) {
        __VERIFIER_assert(factorial == 120);
    }

    // Optionally print the result to verify manually
    printf("Factorial of %d is %lld\n", n, factorial);

    return 0;
}