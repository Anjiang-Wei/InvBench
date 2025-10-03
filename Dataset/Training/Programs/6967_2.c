/*
  Program to compute power of a number iteratively
  and check correctness using an accumulated variable.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "power_computation.c", 11, "reach_error"); }
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
    int base, exp;
    long long result, accumulated;
    base = __VERIFIER_nondet_int();
    exp = __VERIFIER_nondet_int();

    // Assume base within a reasonable limit
    assume_abort_if_not(base >= 0 && base <= 10);
    // Assume non-negative exponent
    assume_abort_if_not(exp >= 0 && exp <= 20);

    result = 1;
    accumulated = 1;

    while (exp > 0) {

        result = result * base;
        accumulated = accumulated * base;

        exp--;
    }

    // Result should be equal to accumulated as both are computed in parallel
    __VERIFIER_assert(result == accumulated);

    printf("Base ^ Exp = %lld\n", result);
    return 0;
}