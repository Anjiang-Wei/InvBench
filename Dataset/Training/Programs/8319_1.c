/*
 * New verification program example:
 * This program computes the factorial of a non-negative integer using a loop.
 */

#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Bound to prevent overflow in factorial calculation.

    int result = 1;
    int i = 1;

    // Compute factorial of `n` using a loop.
    while (i <= n) {
        assume_abort_if_not(result <= 2147483647 / i); // Prevent overflow
        result = result * i;
        i++;
    }

    // Verify the result makes sense in the context of expected factorial properties.
    // As a simple property, we assert that result of factorial should never be zero.
    __VERIFIER_assert(result > 0);

    return 0;
}