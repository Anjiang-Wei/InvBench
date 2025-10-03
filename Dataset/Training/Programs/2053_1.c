#include <stdio.h>
#include <stdlib.h>

// Function prototypes
long long factorial(int n);
void __VERIFIER_assert(int cond);
void reach_error(void);

// Main function
int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 12) {
        // Constraint: Only handle factorials for numbers 0 to 12
        return 1;
    }

    long long result = factorial(n);
    printf("Factorial of %d is %lld\n", n, result);

    // Verification condition: Factorial of 5 is 120
    if (n == 5) {
        __VERIFIER_assert(result == 120);
    }

    return 0;
}

// Function to calculate factorial
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Assertion function for verification
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

// Error handling function
void reach_error(void) {
    printf("Error reached!\n");
    exit(1);
}

// Function to emulate non-deterministic integer input
int __VERIFIER_nondet_int(void) {
    int input;
    printf("Enter a non-negative integer (0-12): ");
    if (scanf("%d", &input) != 1) {
        printf("Invalid input. Exiting.\n");
        exit(1);
    }
    return input;
}