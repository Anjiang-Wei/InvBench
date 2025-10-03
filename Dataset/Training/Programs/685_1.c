/*
  Division Algorithm using repeated subtraction

  This program demonstrates a simple algorithm to perform division
  without using division or multiplication operators. It calculates
  quotient and remainder of two integers using repeated subtraction.
  The program is designed to be a candidate for automated verification.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "division.c", 15, "reach_error"); }
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
}

int main() {
    int dividend, divisor;
    int quotient = 0;
    int remainder = 0;

    dividend = __VERIFIER_nondet_int();
    divisor = __VERIFIER_nondet_int();

    // Ensure the divisor is positive and non-zero
    assume_abort_if_not(divisor > 0);

    remainder = dividend;

    while (remainder >= divisor) {
        remainder -= divisor;
        quotient++;
    }

    // Check correctness
    __VERIFIER_assert(dividend == quotient * divisor + remainder);

    printf("Result: %d / %d = %d (remainder: %d)\n", dividend, divisor, quotient, remainder);

    return 0;
}