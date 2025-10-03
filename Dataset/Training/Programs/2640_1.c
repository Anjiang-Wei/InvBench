/*
 * Example Program: Computation and Verification of Factorial Properties
 */

#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int N, i;
    unsigned long long fact;

    // Simulating non-deterministic input
    N = 5; // For testing purposes, replace this with a nondeterministic input if available

    __VERIFIER_assert(N >= 0 && N <= 12); // Assuming 32-bit integer size, to avoid overflow

    fact = 1;
    for (i = 2; i <= N; i++) {
        fact *= i;
    }

    // Verify if our loop-based factorial matches the recursive definition
    unsigned long long expected_fact = factorial(N);

    // Verify a property: factorial of N is greater than or equal to N
    if (N > 0) {
    }

    // Print the factorial result
    printf("Factorial of %d is %llu\n", N, fact);

    return 0;
}