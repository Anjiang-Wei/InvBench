/*
 * Integer Factorization and Sum Algorithm
 * Inspired by classic factorization methods, this program finds factors of a number
 * and calculates some properties.
 * The validity of these properties can be checked using automated verification tools.
 */

#include <stdio.h>
#include <stdlib.h>

// External functions for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorization.c", 11, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Assert function for validation
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int num = __VERIFIER_nondet_int();
    assume_abort_if_not(num > 1 && num <= 1000);

    int factor_sum = 0;
    int factor_count = 0;
    int i = 1;

    // Loop to find all factors of num
    for (i = 1; i <= num; i++) {
        if (num % i == 0) {
            factor_sum += i;
            factor_count++;
        }
    }

    // Ensure properties about factors are correct
    __VERIFIER_assert(factor_sum >= num + 1);

    printf("Factors of %d have a sum of %d\n", num, factor_sum);
    return 0;
}