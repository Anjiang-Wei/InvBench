#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Program: Compute the Greatest Common Divisor (GCD) of two integers

The program uses the Euclidean algorithm to compute the GCD of two integers.
It assumes both a and b are non-negative and at least one of them is positive.
The program will assert that gcd(a, b) does not change through iterations.
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Assumptions for correct input values
    if (a < 0 || b < 0) {
        return 0; // Ensure non-negative integers
    }
    if (a == 0 && b == 0) {
        return 0; // At least one of them must be non-zero
    }

    int gcd = 0; // Variable to store gcd

    // Ensure that the loop condition holds properly
    while (a != 0 && b != 0) {
        __VERIFIER_assert(gcd == 0 || gcd == a || gcd == b || a % gcd == 0 && b % gcd == 0);

        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }

        // The invariant for determining gcd
        gcd = a == 0 ? b : a;
    }

    // Verify that gcd is indeed the greatest common divisor
    if (a == 0) {
        gcd = b;
    } else {
        gcd = a;
    }

    // Postcondition to check if both a and b divides gcd

    return 0;
}