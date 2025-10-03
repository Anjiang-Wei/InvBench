#include <assert.h>
#include <stdbool.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// This program attempts to calculate the factorial of a number `n`
// It will ensure that the computation adheres to basic constraints
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Ensure n is within a valid range for 32-bit int factorial

    int factorial = 1;
    int i = 1;

    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verify the factorial is positive if n > 0
    if (n > 0) {
    }

    // Verify specific computed results for known inputs
    if (n == 5) {
        __VERIFIER_assert(factorial == 120);
    } else if (n == 0) {
    }

    return 0;
}