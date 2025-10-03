#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// This program models a simple factorial calculator with constraints on input.
int main() {
    int n = __VERIFIER_nondet_int();
    int factorial = 1, i = 1;

    // Assume n is a non-negative number and less than or equal to 10 to prevent overflow
    if (n < 0 || n > 10) {
        return 0;
    }

    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verify that factorial is calculated correctly for n = 5
    if (n == 5) {
        __VERIFIER_assert(factorial == 120);
    }

    // Simple runtime print to confirm the factorial is calculated.
    printf("Factorial of %d is %d\n", n, factorial);

    return 0;
}