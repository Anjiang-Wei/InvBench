/*
 * A program that calculates and verifies the sequence of triangular numbers.
 * Tringular numbers are calculated using the formula: Tn = n*(n+1)/2
 * This program checks the relationship: Tn = T(n-1) + n in each step.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "triangular.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 1);
    assume_abort_if_not(N <= 10000);

    int triangularNumber = 0, previousTriangularNumber = 0;

    for (int i = 1; i <= N; ++i) {
        triangularNumber = previousTriangularNumber + i;
        __VERIFIER_assert(triangularNumber == i * (i + 1) / 2);
        previousTriangularNumber = triangularNumber;
    }

    return 0;
}