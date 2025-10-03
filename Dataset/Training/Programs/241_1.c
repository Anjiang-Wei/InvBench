/*
 * A program that calculates the Fibonacci sequence up to the N-th term
 * while ensuring the calculation uses a loop and maintains certain conditions.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "fibonacci.c", 11, "reach_error"); }

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
    assume_abort_if_not(N >= 0);
    assume_abort_if_not(N <= 47); // to avoid integer overflow in Fibonacci sequence

    long long *fib = malloc(sizeof(long long) * (N + 1));
    fib[0] = 0;
    if (N > 0) {
        fib[1] = 1;
    }

    for (int i = 2; i <= N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        // Verify that each Fibonacci number is greater than or equal to the previous one
        __VERIFIER_assert(fib[i] >= fib[i - 1]);
    }

    // Let's output the Fibonacci sequence up to N-th term
    for (int i = 0; i <= N; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");

    free(fib);
    return 0;
}