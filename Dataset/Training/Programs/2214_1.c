#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
    This program calculates factorial of a nondeterministic number n.
    The precondition is that n is non-negative.
    The postcondition is that factorial is correctly computed.
*/
int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0) {
        return 0; // precondition check
    }

    int factorial = 1;
    int i = 1;

    while (i <= n) {
        // Loop invariant is i <= n+1 and factorial == i-1!
        factorial = factorial * i;
        i++;
    }

    // Postcondition: factorial is n!
    printf("Factorial of %d is %d\n", n, factorial);
    // Example verification to ensure correct factorial computation logically
    __VERIFIER_assert(factorial > 0 || n == 0); // Factorial should be positive for n >= 0

    return 0;
}