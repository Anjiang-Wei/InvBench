/*
 * New Computation and Verification Challenge
 *
 * This program calculates the perfect number status for integers up to a certain limit.
 * A perfect number is a positive integer that is equal to the sum of its proper divisors,
 * excluding the number itself.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "perfect_number.c", 10, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000);

    int i, j;
    int sum;

    for (i = 2; i <= n; i++) {
        sum = 1; // 1 is a proper divisor of any number

        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }

        if (sum == i) {
            __VERIFIER_assert(1); // Perfect number found
        }
    }

    return 0;
}