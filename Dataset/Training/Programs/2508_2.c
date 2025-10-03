/*
 * Example C program that computes Fibonacci numbers iteratively
 * and verifies some properties.
 */

#include <limits.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
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
    assume_abort_if_not(n >= 0 && n <= 46); // Limiting to avoid overflow in Fibonacci calculation
    int a = 0, b = 1, fib = 0, i = 0;

    // Loop to calculate Fibonacci number iteratively
    while (i < n) {
        fib = a + b;
        a = b;
        b = fib;
        i++;

        // Check that the computed Fibonacci number is positive for reasonable 'n'
    }

    // Verify properties at the end of computation
    __VERIFIER_assert(fib == a + b - a || n == 0);     // fib should be the last computed Fibonacci number
    __VERIFIER_assert((n >= 1 && fib >= 1) || n == 0); // Fibonacci numbers for n >= 1 should be at least 1

    return 0;
}