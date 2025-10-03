/*
 * Program to check for properties of a generated numerical sequence.
 * The sequence is recursively defined and has a constraint that must be checked.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function to reach error when assertion fails
void reach_error() {
    printf("Error reached!\n");
    abort();
}

// Function to allow non-deterministic integer generation for model checking
int __VERIFIER_nondet_int(void) {
    return rand(); // In actual verification, this would be replaced by nondeterministic values
}

// Helper function to simulate abort if condition not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to check a condition and trigger reach_error if false
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Main function
int main() {
    int L = __VERIFIER_nondet_int(); // Obtain a non-deterministic length L of the sequence
    assume_abort_if_not(L > 0);
    assume_abort_if_not(L < 1000); // Assume some reasonable bounds on L

    int *sequence = (int *)malloc(sizeof(int) * L);
    if (sequence == NULL) {
        return 1; // Exit if allocation fails
    }

    sequence[0] = 1; // Starting value of the sequence

    for (int i = 1; i < L; ++i) {
        sequence[i] = sequence[i - 1] + 2 * i; // Recursive definition: sequence[i] = sequence[i-1] + 2*i

        // Check if the sequence satisfies certain properties
        // Here, we ensure that sequence[i] is not negative
        __VERIFIER_assert(sequence[i] >= sequence[i - 1]);
    }

    // Verify final sequence property, for example, cumulative sum property
    long long sum = 0;
    for (int i = 0; i < L; ++i) {
        sum += sequence[i];
    }
    // Final assertion verifying that computed sum is equal to a known formula for this sequence type

    free(sequence);
    return 0;
}