/*
 * Fibonacci Sequence
 * Computes the first N Fibonacci numbers.
 * Uses an assertion to ensure that the numbers are non-decreasing.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 11, "reach_error"); }
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
    int N;
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 46); // Typically defined in a practical case to avoid overflow

    int fibonacci[47];
    int i;

    if (N == 0) {
        return 0;
    }

    // Initialize the first two Fibonacci numbers
    fibonacci[0] = 0;
    if (N == 1) {
        return 0;
    }

    fibonacci[1] = 1;

    for (i = 2; i < N; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        __VERIFIER_assert(fibonacci[i] >= fibonacci[i - 1]); // Ensure non-decreasing order
    }

    return 0;
}