/*
 * C Program that calculates power of numbers using implemented
 * custom functions for power calculation.
 * Verification is based on asserting that the calculated power matches
 * expected value when custom power function is used.
 *
 * Author: Generated
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "power.c", 12, "reach_error"); }
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
    return;
}

long long power(int base, int exp) {
    long long result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }
    return result;
}

int main() {
    int base = __VERIFIER_nondet_int();
    int exp = __VERIFIER_nondet_int();

    assume_abort_if_not(base >= 0 && exp >= 0);
    assume_abort_if_not(base <= 20 && exp <= 10); // Limit to prevent overflow in multiplication

    long long expected_result = 1;
    for (int i = 0; i < exp; i++) {
        expected_result *= base;
    }

    long long calculated_result = power(base, exp);

    __VERIFIER_assert(calculated_result == expected_result);

    return 0;
}