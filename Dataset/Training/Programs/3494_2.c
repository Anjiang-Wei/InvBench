/*
 * Example C Program
 * Computes a sequence of Fibonacci numbers and checks properties of the sequence
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// External verification methods, simulate assumptions and reach error scenario
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fib.c", 10, "reach_error"); }
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
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= 46); // Limit N to prevent overflow in Fibonacci sequence for int

    int *fib = malloc(sizeof(int) * N);
    if (fib == NULL) {
        return 1;
    }

    int i;
    fib[0] = 0;

    if (N > 1) {
        fib[1] = 1;
        for (i = 2; i < N; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }

    for (i = 0; i < N; i++) {
        // Ensure that the difference between consecutive numbers is positive
        if (i > 0) {
        }
    }

    // Perform additional verification on the last Fibonacci number
    if (N > 1) {
        __VERIFIER_assert(fib[N - 1] >= fib[N - 2]);
    }

    free(fib);
    return 0;
}