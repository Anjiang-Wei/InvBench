#include <assert.h>
#include <stdlib.h>

// External functions for simulation of verification environment
extern void abort(void);
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

// Custom assertion function
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
 * This program calculates the cumulative product of an array and verifies
 * that the result at certain indices meets specific conditions.
 * The verification tool should be able to determine if it can reach an error.
 */
int main() {
    int length = __VERIFIER_nondet_int();
    // Assume a reasonable length
    if (length <= 1 || length > 1000) {
        return 0;
    }

    int *array = malloc(sizeof(int) * length);
    int *product = malloc(sizeof(int) * length);
    if (array == NULL || product == NULL) {
        return 0;
    }

    // Initialize the array with values between 1 and 2
    for (int i = 0; i < length; i++) {
        array[i] = __VERIFIER_nondet_int();
        if (array[i] < 1 || array[i] > 2) {
            free(array);
            free(product);
            return 0;
        }
    }

    // Calculate cumulative product
    product[0] = array[0];
    for (int i = 1; i < length; i++) {
        product[i] = product[i - 1] * array[i];
        // Check if the cumulative product exceeds a hypothetical threshold
        if (product[i] > 10000) {
            product[i] = 10000; // Cap to manage overflow scenarios
        }
    }

    // Validate the final product against expected hypothetical properties
    __VERIFIER_assert(product[length - 1] <= 10000);

    // Clean up resources
    free(array);
    free(product);

    return 0;
}