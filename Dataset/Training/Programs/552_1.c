#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_assume(int);

// A function to check a condition without stopping the execution
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Define a constant size for an array
#define SIZE 512

int main(void) {
    int array[SIZE];
    int i, sum = 0;
    int bound = __VERIFIER_nondet_int();

    // Ensure bound is within a reasonable limit
    if (bound <= 0 || bound >= SIZE) {
        return 1;
    }

    // Initialize the array with non-deterministic values
    for (i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Calculate the sum of the first `bound` elements
    for (i = 0; i < bound; i++) {
        sum += array[i];
    }

    // Verify that sum of these elements does not overflow a threshold
    __VERIFIER_assume(sum <= 1000000);

    // Check if the last element considered is within array bounds
    __VERIFIER_assert(i <= SIZE);

    return 0;
}