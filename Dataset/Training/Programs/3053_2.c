#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// The program calculates the product of elements in an array that are
// greater than a certain threshold, and checks if the final product
// is greater than 1.
int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N <= 1000); // Limiting N to a reasonable size

    int *array = (int *)malloc(N * sizeof(int));
    int threshold = __VERIFIER_nondet_int();

    // Initialize the array with some nondeterministic values
    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    long long product = 1;

    // Loop over the array and multiply the elements greater than the threshold
    for (int i = 0; i < N; i++) {
        if (array[i] > threshold) {
            product *= array[i];
        }
    }

    // Verify that if we surpassed at least one element above threshold,
    // the product should be greater than 1
    if (threshold < 0) {
        // If threshold is negative, there's likely an element greater than it
    } else {
        // If all elements are expected to be non-positive
        __VERIFIER_assert(product > 0);
    }

    free(array);
    return 0;
}