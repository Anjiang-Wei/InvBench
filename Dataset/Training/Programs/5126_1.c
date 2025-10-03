// This program manages a bounded counter that simulates some operation on an array.
// The array is allocated dynamically, and elements are processed based on a specific condition.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// This is used to simulate nondeterministic behavior.
extern int __VERIFIER_nondet_int(void);

// Abort function simulating a failure scenario
extern void abort(void);

// Simulates a verification assertion
void reach_error() {
    printf("Reach error condition.\n");
    abort();
}

// Assumes a condition; aborts if the condition is false.
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Asserts a condition; calls reach_error if false.
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int SIZE = __VERIFIER_nondet_int();
    // Ensure SIZE is between 2 and 100.
    assume_abort_if_not(SIZE > 1 && SIZE <= 100);

    int *array = (int *)malloc(SIZE * sizeof(int));
    if (array == NULL) {
        return -1; // Allocation failed
    }

    // Initialize array with nondeterministic values
    for (int i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
        // Assume each value in the array is >= 0
        assume_abort_if_not(array[i] >= 0);
    }

    int counter = 0;
    // Process each element - if an element is greater than 50, increment counter
    for (int i = 0; i < SIZE; i++) {
        if (array[i] > 50) {
            counter++;
        }
    }

    // Asserts that counter must be less than or equal to SIZE
    __VERIFIER_assert(counter <= SIZE);

    // Cleanup
    free(array);
    return 0;
}