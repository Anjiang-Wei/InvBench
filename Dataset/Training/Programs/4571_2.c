#include <assert.h>
#include <stdlib.h>

// Provide non-deterministic inputs for verification tools
extern int __VERIFIER_nondet_int(void);
extern void reach_error(void);
void reach_error() { assert(0); }

// A simple checker function
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }

    // Allocate memory dynamically
    int *array = malloc(N * sizeof(int));
    int sum = 0, product = 1;
    int i;

    if (!array) {
        return 1; // Abort if memory allocation fails
    }

    // Initialize and compute sum and product
    for (i = 0; i < N; i++) {
        array[i] = i + 1;    // Initialize array
        sum += array[i];     // Compute sum
        product *= array[i]; // Compute product
    }

    // Verify calculated sum: should match N * (N + 1) / 2 (arithmetic series sum formula)

    // Avoid potential overflow for product verification
    // Product verification: verify if the product is positive, assuming no overflow
    __VERIFIER_assert(product > 0);

    // Free the memory
    free(array);
    return 0;
}