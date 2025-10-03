#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void reach_error() { assert(0); }

/**
 * This program calculates the factorial of a given
 * non-negative integer `n` using a loop and checks
 * a postcondition that the factorial is non-negative.
 *
 * The program's correctness can be verified using
 * automated verification tools.
 */

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int factorial(int n) {
    int result = 1;
    while (n > 0) {
        result *= n;
        n--;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    // Assume n is non-negative for factorial to be defined
    if (n < 0) {
        return 0;
    }

    int fact = factorial(n);

    // Check if the computed factorial is non-negative
    __VERIFIER_assert(fact >= 0);

    return 0;
}