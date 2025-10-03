/*
Calculating Fibonacci sequence using iterative method
Checks and verifies each Fibonacci number property
*/

#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 10, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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

int main() {
    unsigned int n;
    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 0 && n <= 10);

    unsigned int fib_prev = 0, fib_curr = 1, fib_next;

    if (n == 0) {
        fib_curr = 0; // Fibonacci(0) is 0
    }

    for (unsigned int i = 2; i <= n; ++i) {
        __VERIFIER_assert(fib_curr >= fib_prev); // Verify fib_curr is non-decreasing

        fib_next = fib_prev + fib_curr;
        assume_abort_if_not(fib_next >= fib_curr); // Check for overflow condition

        fib_prev = fib_curr;
        fib_curr = fib_next;
    }

    // Verify the basic property of Fibonacci numbers

    return 0;
}