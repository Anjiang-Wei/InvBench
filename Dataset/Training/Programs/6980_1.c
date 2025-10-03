#include <stdio.h>
#include <stdlib.h>

/*
  Calculate and verify the factorial function iteratively.
  It contains a loop to calculate the factorial and includes
  verifications to check for overflow.
*/

// Function prototypes
extern void abort(void);
void reach_error() { abort(); }
extern unsigned int __VERIFIER_nondet_uint(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    unsigned int n, i;
    unsigned long long factorial;

    // Get a random non-deterministic input within a sensible range to calculate factorial
    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 0 && n <= 12); // Arbitrary limit to prevent overflow

    factorial = 1; // Factorial of 0 is 1
    i = 2;         // Start from 2 because 0! and 1! are both 1

    // Calculate factorial using a loop
    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verify the result by comparing with a theoretical maximum value for n = 12
    __VERIFIER_assert(factorial <= 479001600); // 12! = 479001600

    printf("The factorial of %u is %llu.\n", n, factorial);
    return 0;
}