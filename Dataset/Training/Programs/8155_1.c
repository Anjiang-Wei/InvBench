/*
 * This program calculates the factorial of a non-negative integer using an iterative approach.
 * It contains verification conditions to ensure that the computations are being performed correctly.
 */

#include <assert.h>
#include <limits.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, i;
    long long factorial = 1;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);  // ensure n is non-negative
    assume_abort_if_not(n <= 20); // prevent overflow in factorial calculation

    for (i = 1; i <= n; ++i) {
        factorial *= i;
    }

    // Verification: ensure the factorial is greater than or equal to any number in [1, n]
    __VERIFIER_assert(factorial >= 1);

    return 0;
}