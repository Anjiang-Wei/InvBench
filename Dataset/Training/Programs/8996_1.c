#include <stdio.h>
#include <stdlib.h>

// Function to reach an error state
void reach_error() {
    printf("Error reached\n");
    abort();
}

// Assertion to check a condition
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    unsigned int a = 0, b = 0, sum = 0;
    unsigned int threshold = 500;
    unsigned int i = 0;

    // Simulate some nondeterministic values
    a = rand() % 1000;
    b = rand() % 1000;

    while (i < 1000) {
        // Compute a cumulative sum
        sum += a + b;

        // Check if the sum exceeds the threshold
        if (sum > threshold) {
            break;
        }

        // Random increment to a and b
        a += rand() % 10;
        b += rand() % 10;

        i++;
    }

    // Verify that sum is greater than threshold or loop broke before exceeding
    __VERIFIER_assert(sum > threshold || i == 1000);

    printf("Final sum: %u\n", sum);
    printf("Iterations: %u\n", i);
    return 0;
}