// This C program is designed to be analyzed and verified by automated tools.
// It implements a modified version of the Collatz conjecture with constraints.

// Include necessary headers
#include <stdio.h>
#include <stdlib.h>

// Declare functions used for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "collatz.c", 7, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

// Function to verify conditions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

// Main function implementing the modified Collatz conjecture
int main() {
    int n = __VERIFIER_nondet_int(); // Get a non-deterministic integer
    int steps = 0;

    // Ensure the input is a positive integer
    if (n <= 0) {
        return 0;
    }

    // Loop implementing the modified Collatz conjecture with constraints
    while (n != 1 && steps < 100) {
        __VERIFIER_assert(n > 0); // Assert that n is always positive during the loop

        if (n % 2 == 0) {
            n = n / 2; // If n is even, divide by 2
        } else {
            n = 3 * n + 1; // If n is odd, multiply by 3 and add 1
        }

        steps++; // Increment the step counter
    }

    // Assert the loop terminates with n equal to 1 within 100 steps
    __VERIFIER_assert(n == 1 || steps == 100);

    return 0;
}