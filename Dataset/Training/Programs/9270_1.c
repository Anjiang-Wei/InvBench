#include <assert.h>
#include <stdlib.h>

// Function to indicate a reachability error
void reach_error(void) { assert(0); }

// Variable to simulate a nondeterministic integer input
extern int __VERIFIER_nondet_int(void);

// Assumption function that aborts execution if the condition is not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Assertion function that checks a condition; calls reach_error if it fails
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Main function
int main() {
    int length = __VERIFIER_nondet_int(); // Nondeterministically choose a length
    assume_abort_if_not(length > 1);      // Assume the length is greater than 1

    // Create an array of the specified length
    int *array = (int *)malloc(sizeof(int) * length);

    // Initialize the first two elements of the array
    array[0] = 0;
    array[1] = 1;

    // Generate a sequence similar to the Fibonacci sequence
    for (int i = 2; i < length; i++) {
        array[i] = array[i - 1] + array[i - 2];
    }

    // Assign the value of the last element as the result
    int result = array[length - 1];

    // Ensure the result is a non-negative integer to reach the desired logical conclusion
    __VERIFIER_assert(result >= 0);

    // Clean up the dynamically allocated memory
    free(array);

    return 0;
}