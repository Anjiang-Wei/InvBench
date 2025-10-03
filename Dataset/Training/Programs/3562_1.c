#include <assert.h>
#include <stdio.h>

void reach_error(void) {
    assert(0);
}

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* The following program calculates the factorial of a number using a loop.
   It has a constraint that the input number should be non-negative, and
   it verifies that the computed factorial is not zero for any non-zero input. */

int factorial(int n) {
    if (n < 0) {
        return -1; // Indicate error for negative numbers
    }
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int x = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0); // Assuming input is non-negative

    int result = factorial(x);

    if (x > 0) {
        __VERIFIER_assert(result > 0); // Factorial should be positive for x > 0
    }

    if (x == 0) {
        __VERIFIER_assert(result == 1); // Factorial of 0 is 1
    }

    return 0;
}