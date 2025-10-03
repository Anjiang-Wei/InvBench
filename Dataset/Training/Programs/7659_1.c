/*
 * Fibonacci Sequence Generator with Assertions
 * This program calculates Fibonacci numbers iteratively, checks properties
 * using assertions, and aims to be verifiable with automated verification tools.
 */

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}
extern int __VERIFIER_nondet_int(void);

int main() {
    unsigned int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 30); // Limit n to a reasonable range for verification

    long long fib1 = 0, fib2 = 1, fib_current;
    unsigned int i;

    for (i = 2; i <= n; ++i) {
        fib_current = fib1 + fib2;

        // Assertion: Fibonacci numbers should never be negative
        __VERIFIER_assert(fib_current >= 0);

        fib1 = fib2;
        fib2 = fib_current;
    }

    // Here, fib_current holds the nth Fibonacci number
    // Assertion: Any Fibonacci number modulo its index should not be negative

    return 0;
}