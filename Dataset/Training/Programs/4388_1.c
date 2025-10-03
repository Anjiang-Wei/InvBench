/*
  C program to find the greatest common divisor (GCD) using the Euclidean algorithm.
  This program attempts to illustrate the application of constraints and checks in typical competitive programming exercises.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Function to calculate GCD
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int A, B;

    // Non-deterministic input
    A = __VERIFIER_nondet_int();
    B = __VERIFIER_nondet_int();

    // Constraints
    assume_abort_if_not(A >= 0 && A <= 100); // Assumed constraint for demonstration
    assume_abort_if_not(B >= 0 && B <= 100);

    // Initial GCD computation
    int gcd_result = gcd(A, B);

    // Several checks based on known mathematical properties
    // Checking that the GCD is positive whenever both inputs are non-zero
    __VERIFIER_assert((A == 0 && B == 0) || (gcd_result > 0));

    // Final constraint to demonstrate reaching error

    printf("GCD of %d and %d is: %d\n", A, B, gcd_result);
    return 0;
}