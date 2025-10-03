/*
 * Sample C Program for Automated Verification Tasks
 * This program calculates Fibonacci numbers using an iterative approach
 * and verifies a property related to Fibonacci sequence.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "fibonacci.c", 15, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
        abort();
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0);
    assume_abort_if_not(N <= 46); // To avoid integer overflow for Fibonacci calculation within int range

    int fib1 = 0, fib2 = 1, fibN = 0;
    int i = 0;

    if (N == 0) {
        fibN = fib1;
    } else if (N == 1) {
        fibN = fib2;
    } else {
        while (i < N - 1) {
            fibN = fib1 + fib2;
            fib1 = fib2;
            fib2 = fibN;
            i++;
        }
    }

    // Verify that Fibonacci(N) is non-negative
    __VERIFIER_assert(fibN >= 0);

    printf("Fibonacci(%d) = %d\n", N, fibN);

    return 0;
}