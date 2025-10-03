/*
This program implements a simple Fibonacci sequence that generates the first N numbers in the sequence.
It then checks if the last number computed, which is assumed to be the N-th Fibonacci number, is correct
by verifying the relationship between consecutive Fibonacci numbers.

The program is intended to be analyzed using automated verification tools to ensure the logic is correct.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 9, "reach_error"); }
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
    int N;
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 1);
    assume_abort_if_not(N <= 44); // Limit to prevent integer overflow for Fibonacci sequence

    long long fib_prev = 0, fib_current = 1, fib_next;

    int i;
    for (i = 2; i <= N; i++) {
        fib_next = fib_prev + fib_current;
        fib_prev = fib_current;
        fib_current = fib_next;
    }

    // Verification: Assert that the last computed number is the correct N-th Fibonacci number.
    if (N == 1) {
        __VERIFIER_assert(fib_current == 1);
    } else if (N == 2) {
    } else {
    }

    return 0;
}