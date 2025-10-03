/*
 * Example program demonstrating automated verification patterns.
 *
 * This program calculates the Fibonacci sequence using dynamic programming
 * and verifies the results using a logical condition.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 10, "reach_error"); }
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

#define MAX_SIZE 50

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= MAX_SIZE);
    if (N < 2) {
        return 1;
    }

    long long *fib = (long long *)malloc((N + 1) * sizeof(long long));
    assume_abort_if_not(fib != NULL);

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= N; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Verify the computed Fibonacci number
    long long expected_value = fib[N - 1] + fib[N - 2];
    __VERIFIER_assert(fib[N] == expected_value);

    free(fib);
    return 0;
}