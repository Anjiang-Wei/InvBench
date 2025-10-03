#include <assert.h>
#include <stdlib.h>

// External function prototypes (placeholders for non-deterministic behavior)
extern unsigned int __VERIFIER_nondet_uint(void);
extern void abort(void);

// Function to reach an error
void reach_error() { assert(0); }

// Custom assert function to enforce conditions
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    unsigned int max_iterations = 10;
    unsigned int a, b, sum, product;
    unsigned int iterations = 0;

    // Initialize with non-deterministic values
    a = __VERIFIER_nondet_uint();
    b = __VERIFIER_nondet_uint();

    // Initialize sum and product
    sum = 0;
    product = 1;

    // Compute sum and product under certain constraints
    while (iterations < max_iterations) {
        // Ensure that a and b are within a reasonable range
        unsigned int temp_a = __VERIFIER_nondet_uint();
        unsigned int temp_b = __VERIFIER_nondet_uint();

        if (temp_a < 100 && temp_b < 100) {
            a = temp_a;
            b = temp_b;
        }

        sum += a;
        product *= b;

        // Assert constraints
    }

    // Final assertion to check some additional condition
    __VERIFIER_assert(sum + product >= sum); // Trivial but gives a sense of magnitude

    return 0;
}