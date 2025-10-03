/*
Factorial Computation with Verification
Computes the factorial of a non-negative integer n and verifies certain properties
*/

#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    long long factorial = 1;
    int i;

    // Assume n is a non-negative integer
    if (n < 0) {
        return 0;
    }

    for (i = 1; i <= n; i++) {
        factorial *= i;

        // Verification conditions
        __VERIFIER_assert(factorial > 0);      // Factorial should always be positive for non-negative n
        __VERIFIER_assert(factorial % i == 0); // Factorial is divisible by the current i
    }

    // Final verification after the loop
    __VERIFIER_assert(factorial >= 1); // Factorial of a non-negative number is always at least 1

    return 0;
}