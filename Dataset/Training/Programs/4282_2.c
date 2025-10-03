/*
 * A computational program that calculates the factorial of a number
 * and verifies if it conforms to certain constraints during the calculation.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_ver.c", 6, "reach_error"); }
extern void abort(void);
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
    long long factorial = 1;
    int i = 1;

    assume_abort_if_not(n >= 0); // The number must be non-negative
    assume_abort_if_not(n < 20); // Limitation to keep the calculations within a reasonable range

    while (i <= n) {
        factorial *= i;
    }

    // Verify some property of the factorial
    if (n > 5) {
        __VERIFIER_assert(factorial > 120); // Verify that factorial of numbers >5 is larger than 120
    }

    printf("Factorial of %d is %lld\n", n, factorial);
    return 0;
}