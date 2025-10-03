#include <stdio.h>

// Function to reach an error condition
void reach_error() {
    printf("Verification failed!\n");
}

// Custom assertion function to simulate failure
void __VERIFIER_assert(int cond, const char *message) {
    if (!cond) {
        printf("%s\n", message);
        reach_error();
    }
}

// Main function
int main() {
    // Variables to compute exponential sequence progressively
    unsigned int base, limit, i, pow_result;
    unsigned long long sum_result;

    // Simulation of non-deterministic input
    base = 3;  // Feel free to change to any non-negative integer
    limit = 5; // Feel free to change to control the number of iterations

    // Initial assignment
    pow_result = 1; // base^0 is 1
    sum_result = 0;

    // Loop to compute base^i and sum(base^i) for i from 0 to limit-1
    for (i = 0; i < limit; ++i) {
        // Compute power of base^i
        sum_result += pow_result; // Integrating sum of powers

        pow_result *= base; // Next power of base
    }

    // Final verification of values equalities
    __VERIFIER_assert(sum_result > 0, "No sequence computed");

    // Output the computed results
    printf("base: %u, limit: %u, final power: %u, sum of powers: %llu\n", base, limit, pow_result, sum_result);

    return 0;
}