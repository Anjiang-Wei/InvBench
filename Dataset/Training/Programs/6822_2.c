#include <stdio.h>
#include <stdlib.h>

// Function to reach an error state
void reach_error() {
    printf("Error reached\n");
    abort();
}

// Assertion function to verify conditions
void __VERIFIER_assert(int cond) {
    if (!cond) {
    // Error label
    ERROR : { reach_error(); }
    }
    return;
}

// Non-deterministic integer generator placeholder
extern int __VERIFIER_nondet_int(void);

// Main function
int main() {
    int n = __VERIFIER_nondet_int();
    if (!(n > 0 && n < 20)) {
        return 0; // Constraint for verification
    }

    // Factorial computation
    int factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    // Compute the sum of series up to n
    int sum = 0;
    int i = 0;
    while (i < n) {
        sum += i * i; // Sum of squares
        i++;
    }

    // Verify results
    // A known mathematical property related to factorial can be verified
    // In this case, we'll check an artificial condition for demo purposes
    __VERIFIER_assert(sum >= 0);

    // Print the results
    printf("Factorial of %d is %d\n", n, factorial);
    printf("Sum of squares up to %d is %d\n", n - 1, sum);

    return 0;
}