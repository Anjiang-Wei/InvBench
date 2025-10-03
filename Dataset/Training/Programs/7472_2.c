#include <stdio.h>

// Define an error-reach mechanism
extern void abort(void);
void reach_error() { abort(); }

// Assume helper function to halt the program if a condition is not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Custom assert function to check conditions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

int main() {
    unsigned int a, b, gcd;
    a = 84; // Example value; can replace with any non-negative integer
    b = 18; // Example value; can replace with any non-negative integer

    // Ensure the inputs are reasonable
    assume_abort_if_not(a >= 0 && b >= 0);

    // Calculation of GCD using Euclid's algorithm
    if (b == 0) {
        gcd = a;
    } else {
        unsigned int temp;
        while (b != 0) {
            temp = b;
            b = a % b;
            a = temp;
            // Ensure GCD condition in each iteration
        }
        gcd = a;
    }

    // Print result
    printf("GCD is: %u\n", gcd);

    // Final assertion check
    __VERIFIER_assert(gcd != 0 && (gcd > 0 && gcd <= a)); // GCD should be non-zero if both inputs are non-zero

    return 0;
}