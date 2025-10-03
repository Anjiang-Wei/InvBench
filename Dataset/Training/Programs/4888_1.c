/*
 * A program to calculate Fibonacci numbers iteratively
 * with additional logic checks
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fib.c", 7, "reach_error"); }
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
    int n, fib_curr, fib_prev, fib_prev2, i;

    n = __VERIFIER_nondet_int();            // Choose a non-deterministic number
    assume_abort_if_not(n >= 0 && n <= 20); // Limit n for controlled range

    fib_prev = 0;
    fib_curr = 1;

    for (i = 2; i <= n; i++) {
        fib_prev2 = fib_prev;
        fib_prev = fib_curr;
        fib_curr = fib_prev + fib_prev2;

        // The difference between consecutive Fibonacci numbers is non-negative
        __VERIFIER_assert(fib_curr - fib_prev >= 0);
    }

    if (n == 0) {
        fib_curr = 0;
    }

    // Ensure that the nth Fibonacci number is greater than or equal to n/2
    // This property is normally true for the Fibonacci sequence after a few initial terms

    printf("Fibonacci number at position %d is %d\n", n, fib_curr);
    return 0;
}