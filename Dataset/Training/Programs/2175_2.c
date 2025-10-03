#include <stdio.h>

// Simple function to represent an error situation
void reach_error() {
    printf("Error reached!\n");
}

// Function to represent assertion checking
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Assume function to simulate non-deterministic input under constraints
void assume_abort_if_not(int cond) {
    if (!cond) {
        printf("Invalid assumption!\n");
        abort();
    }
}

// Main function demonstrating a sequence of calculations
int main() {
    unsigned int n, limit;
    long long sum, product, count;

    // Simulating the non-deterministic input for n and limit
    n = 20; // restricted to a reasonable number for this example
    limit = 1000;
    assume_abort_if_not(n > 0 && n <= 100);
    assume_abort_if_not(limit >= n && limit <= 1000);

    sum = 0;
    product = 1;
    count = 0;

    while (count < n) {
        sum += count;
        if (product <= limit) {
            product *= count + 1;
        }
        count++;
    }

    // Verify product is within limit

    // Verify the sum is a triangular number
    long long expected_sum = (n * (n - 1)) / 2;
    __VERIFIER_assert(sum == expected_sum);

    printf("Sum of first %u integers is %lld\n", n, sum);
    printf("Product of first %u integers is %lld\n", n, product);

    return 0;
}