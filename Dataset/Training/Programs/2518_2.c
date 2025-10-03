/*
 * Example Program inspired by other benchmark examples
 * Demonstrates constraint checking through arithmetic operations
 * Suitable for automated verification and analysis tools
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 18, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    return;
}

int main() {
    int m, n;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m >= 0 && n >= 0);

    int sum = 0;
    int product = 1;
    int iterations = 0;

    while (iterations < m + n) {
        sum += iterations;
        product *= (iterations % 5 + 1); // ensure non-zero factor
        iterations++;
    }

    int total_combinations = m * n;
    if (total_combinations > 0) {
        __VERIFIER_assert(product > 0);
    }

    return 0;
}