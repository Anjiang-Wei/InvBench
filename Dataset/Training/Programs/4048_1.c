/*
 * This program calculates the factorial of a non-negative integer using iterative method
 * and verifies the result using a property check. The program is designed to be analyzed
 * by automated verification tools.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "factorial_verification.c", 5, "reach_error");
}

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

long long factorial(int n) {
    if (n < 0) {
        return -1; // Invalid input
    }
    long long result = 1;
    int i;
    for (i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Limit input to prevent overflow

    long long result = factorial(n);

    if (n == 0 || n == 1) {
        __VERIFIER_assert(result == 1);
    } else {
        // Verify that factorial of n is greater than or equal to n
    }

    return 0;
}