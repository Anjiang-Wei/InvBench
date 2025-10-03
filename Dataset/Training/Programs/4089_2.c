#include <stdio.h>
#include <stdlib.h>

// A function to simulate a potentially failing operation
extern void abort(void);
void reach_error() {
    printf("Error reached!\n");
    abort();
}

// Custom assert function to handle errors
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

// Function to find the Greatest Common Divisor (GCD) using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x = 48; // You can change these values to test other cases
    int y = 18;

    // Validate that neither number is negative
    if (x < 0 || y < 0) {
        reach_error();
    }

    // Peform computation of GCD
    int result = gcd(x, y);

    // Verify the result with a mathematical check
    __VERIFIER_assert(x % result == 0 && y % result == 0);

    // For debugging purposes: print the result
    printf("GCD of %d and %d is %d\n", x, y, result);

    return 0;
}