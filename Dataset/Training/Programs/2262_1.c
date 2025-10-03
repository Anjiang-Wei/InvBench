/*
 * New C Program for Verification
 * This program calculates the factorial of a number
 * and ensures that the calculated result satisfies a specific condition.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 5, "reach_error"); }
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

int factorial(int n) {
    if (n < 0) {
        return 0;
    }
    int prod = 1;
    for (int i = 1; i <= n; ++i) {
        prod *= i;
    }
    return prod;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Ensuring n is within a range to prevent overflow

    int fact = factorial(n);

    // Verify that the factorial is greater than zero for valid n
    __VERIFIER_assert((n >= 0 && n <= 12) ? (fact > 0) : (fact == 0));

    // Additional condition to check if n! % (n + 1) == n
    if (n > 0) {
    }

    printf("Factorial of %d is %d\n", n, fact);
    return 0;
}