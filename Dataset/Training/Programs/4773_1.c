#include <stdio.h>
#include <stdlib.h>

/*
 * Program demonstrating constraints and validations.
 * Utilizes loops and checks invariants through computed constraints.
 */

// Function to simulate assertion failures
void reach_error() {
    printf("Error: Assertion failed!\n");
    abort();
}

// Custom assertion to check conditions
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Arbitrary constraint generator function
int generate_constraint(int val) {
    return val * val + 3 * val + 5;
}

// Main function demonstrating loop with computed constraints
int main() {
    int n = 5; // Loop will run 'n' times
    int sum = 0, term = 0;

    for (int i = 0; i < n; i++) {
        term = generate_constraint(i);
        sum += term;
    }

    // Calculating an expected value hence validating through constraints
    int expected_sum = n * (n - 1) * (2 * n - 1) / 6 + 3 * n * (n - 1) / 2 + 5 * n;

    // Check constraints after loop execution
    __VERIFIER_assert(sum == expected_sum);

    return 0;
}