#include <stdio.h>

// Function to simulate a verification abort
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to simulate the reach_error
void reach_error() {
    printf("Reach Error\n");
    abort();
}

// Nondeterministic integer and boolean generators
extern int __VERIFIER_nondet_int(void);

// Custom assert function used for verification
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Utility function to compute the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Main program entry
int main() {
    int a = __VERIFIER_nondet_int(); // First integer (nondeterministic)
    int b = __VERIFIER_nondet_int(); // Second integer (nondeterministic)

    // Assumptions to prevent trivial or problematic values
    assume_abort_if_not(a > 0 && a < 100);
    assume_abort_if_not(b > 0 && b < 100);

    // This variable will hold the sum of the GCDs of all pairs
    int sumGCD = 0;

    // Loop over all pairs (i, j) where 1 <= i < a and 1 <= j < b
    for (int i = 1; i < a; i++) {
        for (int j = 1; j < b; j++) {
            sumGCD += gcd(i, j);
        }
    }

    // Verification assertion: if both `a` and `b` are 1, sumGCD should be 0
    // (since pairs are only counted starting from 1, and gcd(0,0) is not included)
    if (a == 1 && b == 1) {
        __VERIFIER_assert(sumGCD == 0);
    }

    printf("Sum of GCD of all pairs is: %d\n", sumGCD);
    return 0;
}