/*
 * Example C Program
 * Calculates and verifies properties of a Fibonacci sequence.
 * This program ensures that any Fibonacci number at position n is non-negative.
 * Demonstrates speculative invariant in loops with constraints.
 */

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "fibonacci.c", 10, "reach_error");
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
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);  // Ensure the Fibonacci position is non-negative
    assume_abort_if_not(n <= 46); // Limit n to avoid integer overflow for Fibonacci computation

    int fib_prev = 0; // F(0)
    int fib_curr = 1; // F(1)
    int fib_next = 0;
    int i;

    if (n == 0) {
    } else if (n == 1) {
    } else {
        for (i = 2; i <= n; i++) {
            fib_next = fib_prev + fib_curr; // F(n) = F(n-1) + F(n-2)

            // Check that the Fibonacci number is non-negative
            __VERIFIER_assert(fib_next >= 0);

            // Move forward in the sequence
            fib_prev = fib_curr;
            fib_curr = fib_next;
        }
    }

    return 0;
}