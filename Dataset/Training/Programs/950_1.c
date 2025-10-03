#include <assert.h>
#include <stdlib.h>

// Declare external functions used for verification
extern void abort(void);
void reach_error() { assert(0); }

// Function to simulate a nondeterministic integer input
extern int __VERIFIER_nondet_int(void);

// Function to assert conditions, which calls reach_error() on failure
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

// Linear search algorithm with a verification condition
int linear_search(int *array, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1; // Target not found
}

int main() {
    int size = __VERIFIER_nondet_int();
    // Define constraints for size to ensure it falls within a reasonable range
    if (size <= 0 || size > 100) {
        return 0; // Early exit if size is out of bounds
    }

    // Allocate memory for the array
    int *array = malloc(size * sizeof(*array));
    if (array == NULL) {
        abort();
    }

    int target = __VERIFIER_nondet_int(); // A nondeterministic target value

    // Initialize the array with increasing values
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    // Perform a linear search
    int index = linear_search(array, size, target);

    // Verification condition: if target is not found, index must be -1
    __VERIFIER_assert(index == -1 || (index >= 0 && index < size && array[index] == target));

    // Free the allocated memory
    free(array);

    return 0;
}