#include <assert.h>
#include <stdlib.h>

/*
 * New C Program with meaningful computational logic and constraints
 * This program calculates the sum of squares of integers up to N
 * and asserts that the computed sum is non-negative.
 */

extern void abort(void);
void reach_error() { assert(0); }
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
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 1000);

    long long sum_of_squares = 0;
    int i = 0;

    // Loop to calculate the sum of squares of numbers from 1 to N
    while (i <= N) {
        sum_of_squares += (long long)i * i;
        i++;
    }

    // Constraint condition: sum_of_squares should be non-negative
    // As we are squaring numbers and adding them, it should be always non-negative
    __VERIFIER_assert(sum_of_squares >= 0);

    return 0;
}