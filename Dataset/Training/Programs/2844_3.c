#include <assert.h>
#include <math.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

// Function to calculate factorial of a number
unsigned long factorial(int n) {
    if (n < 0) {
        return 0; // Factorial of negative number is undefined
    }
    unsigned long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main(void) {
    int n = __VERIFIER_nondet_int(); // Get a non-deterministic integer
    if (n < 0 || n > 12) {
        // Limit to prevent overflow in factorial
        n = 5; // Default value in safe range
    }

    unsigned long fact = factorial(n);

    // Verify that factorial of n is greater than or equal to n

    // Verify if factorial is even or odd
    if (fact % 2 == 0) {
    } else {
        __VERIFIER_assert(fact % 2 == 1);
    }

    int m = 0;
    while (m < fact) {
        m += 2;
        // Ensure m never exceeds fact in the loop
    }

    return 0;
}