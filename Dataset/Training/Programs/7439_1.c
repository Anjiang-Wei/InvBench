/*
  Program to compute the exponentiation using repeated squaring.
  This method is efficient for large exponents and works in O(log n) time complexity.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "exp-by-squaring.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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

// Function to perform exponentiation using repeated squaring
long long exp_by_squaring(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // odd exponent
            result *= base;
            exp--;
        } else { // even exponent
            base *= base;
            exp /= 2;
        }
    }
    return result;
}

int main() {
    long long base, result;
    int exp;

    base = __VERIFIER_nondet_int();
    assume_abort_if_not(base >= 1 && base <= 4);

    exp = __VERIFIER_nondet_int();
    assume_abort_if_not(exp >= 0 && exp <= 8);

    result = exp_by_squaring(base, exp);

    // Finally ensure that the result is not negative, as it's an error in computation
    __VERIFIER_assert(result >= 0);

    return 0;
}