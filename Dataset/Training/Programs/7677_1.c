#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to simulate nondeterministic integer choice
int __VERIFIER_nondet_int(void) {
    return rand() % 101; // Limit the value between 0 and 100
}

/*
Factorial Computation with Verification
Verifies that the factorial of a number n is accumulated correctly,
and that the resulting factorial is always greater than or equal to 1.
*/
int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 10) {
        // The chosen n should be between 0 and 10 for practical factorial computation
        return 0;
    }

    int i = 1;
    long long factorial = 1;

    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verify the factorial is computed correctly and is at least 1
    __VERIFIER_assert(factorial >= 1);

    // Print the result for demonstration purposes
    printf("The factorial of %d is %lld\n", n, factorial);

    return 0;
}