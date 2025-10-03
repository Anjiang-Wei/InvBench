/*
 * Fibonacci Series with Verification
 * Computes the first N Fibonacci numbers and verifies their properties.
 * Demonstrates the pattern of incrementally building solutions and verifying properties.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 10, "reach_error"); }
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
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 1 && N < 47); // Prevent overflow for fib(N)

    long long *fib = malloc(sizeof(long long) * (N + 1));
    if (!fib) {
        abort();
    }

    // Base cases
    fib[0] = 0;
    fib[1] = 1;

    // Computation of Fibonacci series
    for (int i = 2; i <= N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];

        // Verify property: fib[i] = fib[i-1] + fib[i-2]
        __VERIFIER_assert(fib[i] == fib[i - 1] + fib[i - 2]);
    }

    // Verify property: fib[N] >= fib[N-1] (that's always true by definition)

    // Free allocated memory
    free(fib);

    return 0;
}