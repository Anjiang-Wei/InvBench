/*
 * This program computes the Fibonacci sequence using dynamic programming.
 * The implementation is designed to test if the sequence is computed correctly
 * up to the N-th Fibonacci number without overflow.
 */

#include <stdio.h>
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

int N; // Global variable to determine the size of the Fibonacci sequence

int main() {
    N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 46); // To prevent integer overflow for Fibonacci calculation

    int *fib = malloc(sizeof(int) * (N + 1));
    if (fib == NULL) {
        return 1; // Ensure memory allocation was successful
    }

    // Base cases
    fib[0] = 0;
    fib[1] = 1;

    // Compute Fibonacci sequence up to N using dynamic programming
    for (int i = 2; i <= N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Check the last computed Fibonacci number using a known property:
    // Fibonacci numbers are known to satisfy the identity:
    // fib(n) == round(phi^n / sqrt(5)) for very large n, but here we
    // simply verify a known value for demonstration purposes.
    __VERIFIER_assert(fib[N] >= fib[N - 1]); // Should always be true for valid Fibonacci numbers

    // Free allocated memory
    free(fib);

    return 0;
}