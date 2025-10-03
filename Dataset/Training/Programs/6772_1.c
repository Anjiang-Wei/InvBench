#include <assert.h>
#include <stdlib.h>

// Simulation of a non-deterministic integer which verification tools provide
extern int __VERIFIER_nondet_int(void);

// Error handling in case of failed assertion
void reach_error() { assert(0); }

// Custom assert function used for verification
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Program demonstrating a non-trivial loop with some constraints
int main() {
    // Non-deterministic integer inputs
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Assume initial conditions
    if (!(a > 0 && b > 0)) {
        return 0;
    }

    // Variable to hold the sum of numbers
    int sum = 0;

    // Loop that performs operations on a and b
    while (a > 0 && b > 0) {
        a -= 1;
        b -= 2;
        sum += 3;
    }

    // Assert that the sum is a multiple of 3, which should be always true
    __VERIFIER_assert(sum % 3 == 0);

    // Having a condition that adheres to manipulations of a and b

    return 0;
}