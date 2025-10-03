/*
 * A program that aims to verify properties of the sequence of Fibonacci numbers.
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "fibonacci_verification.c", 10, "reach_error"); }
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

    assume_abort_if_not(n >= 0 && n <= 30); // Limit 'n' to avoid overflow

    // Fibonacci sequence initialization
    int fib_prev = 0;
    int fib_curr = 1;
    int fib_next;
    int i;

    for (i = 2; i <= n; ++i) {
        fib_next = fib_prev + fib_curr;

        // Verify that fib_next calculation does not overflow
        assume_abort_if_not(fib_next >= fib_curr);

        fib_prev = fib_curr;
        fib_curr = fib_next;
    }

    // Assertion after loop: Fibonacci property check
    int fib_val = (n == 0) ? fib_prev : fib_curr;

    // This assertion equivalent to `n == 0 || fib_val >= 0`. It's trivially true as each
    // Fibonacci number is non-negative for n >= 0.
    __VERIFIER_assert(n == 0 || fib_val >= 0);

    return 0;
}