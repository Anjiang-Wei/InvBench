#include <assert.h>

// A simple error reporting function
void reach_error(void) { assert(0); }

// External functions for non-deterministic inputs
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

// Custom assertion function to help in verification
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Program to calculate the greatest common divisor (GCD) using the Euclidean algorithm
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Assume both numbers are non-negative and initially not zero
    if (!(a >= 0 && b >= 0 && (a != 0 || b != 0))) {
        return 0;
    }

    // Making sure neither a nor b are zero initially for meaningful operations
    if (a == 0) {
        a = 1;
    }
    if (b == 0) {
        b = 1;
    }

    // Use the Euclidean algorithm to find gcd of a and b
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    // Check if 'a' is the gcd at the end
    __VERIFIER_assert(a >= 1); // GCD should be at least 1 (given we assumed non-zero input)

    return 0;
}