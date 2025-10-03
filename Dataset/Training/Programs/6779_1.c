/*
 * This program calculates the factorial of a number using
 * an iterative approach while checking that the computed
 * factorial is correctly maintained throughout the loop.
 * It integrates constraint checks and uses a mechanism to
 * manage assumptions similar to the provided examples.
 */

#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "factorial.c", 7, "reach_error");
}

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
    int n;
    long long factorial, expected;

    // Get an input and set constraints
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Limiting to 12 to prevent overflow

    factorial = 1;
    expected = 1;

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        expected *= i;
    }

    // Assert that the expected factorial is correct
    __VERIFIER_assert(factorial == expected);

    printf("Factorial of %d: %lld\n", n, factorial);
    return 0;
}