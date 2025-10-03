/*
 * Fibonacci Variant Series
 * Computes Fibonacci-like series: f(i) = f(i-1) + f(i-2) for a given number of terms N
 * and verifies specific conditions on the series.
 */

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fib_variant.c", 10, "reach_error"); }
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
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 2) {
        return 1; // Need at least 3 terms for calculation
    }
    assume_abort_if_not(N < 50); // Limit N to prevent overflow in Fibonacci calculation

    long long *fib = (long long *)malloc(sizeof(long long) * N);
    if (fib == NULL) {
        return 1; // Memory allocation check
    }

    // Initial Fibonacci conditions
    fib[0] = 1;
    fib[1] = 1;

    // Generate Fibonacci-like series
    for (int i = 2; i < N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        __VERIFIER_assert(fib[i] > fib[i - 1]); // Ensure sequence is strictly increasing
    }

    // Verify condition at the end of the series
    long long sum_fib = fib[N - 1] + fib[N - 2];
    return 0;
}