/*
 * Example program demonstrating similar patterns and structures
 * based on provided code examples.
 */

#include <stdio.h>
#include <stdlib.h>

// Function declarations for error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 10, "reach_error"); }

// Helper function to abort if condition is not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Simplified version of an assertion, similar to examples
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Simulate non-deterministic integer input
extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    // Ensure N is a positive value that's safe for array allocation
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 2147483647 / sizeof(int));

    int *array = malloc(N * sizeof(int));
    int i, count = 0;
    int threshold = 50;

    // Initialize the array with values based on index
    for (i = 0; i < N; i++) {
        array[i] = i * 2; // Even numbers
    }

    // Count how many numbers are above a defined threshold
    for (i = 0; i < N; i++) {
        if (array[i] > threshold) {
            count++;
        }
    }

    // Assert count is less than N to ensure logic consistency
    __VERIFIER_assert(count < N);

    free(array); // Avoid memory leaks
    return 0;
}