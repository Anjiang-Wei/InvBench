/*
 * This program calculates the sum of squares of natural numbers up to N
 * and checks whether the cumulative sum at each step is consistent with the
 * formula for the sum of squares: S = n*(n+1)*(2n+1)/6.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sum_of_squares.c", 10, "reach_error");
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }

    int i;
    long long sum_of_squares = 0;
    long long computed_formula = 0;

    for (i = 1; i <= N; ++i) {
        sum_of_squares += i * i;
        computed_formula = (i * (i + 1) * (2 * i + 1)) / 6;
        __VERIFIER_assert(sum_of_squares == computed_formula);
    }

    return 0;
}