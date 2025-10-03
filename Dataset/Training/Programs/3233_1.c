#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

// Function to handle error
void reach_error() {
    perror("Error reached! Verifying failure.");
    abort();
}

// Custom assertion function
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

// Function to simulate non-deterministic unsigned int generation
extern unsigned int __VERIFIER_nondet_uint();

// Function to perform a basic linear search in an array
// The function returns the index of the target value if found, otherwise -1
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Not found
}

int main() {
    unsigned int size = 10; // size of the array
    int values[10];

    // Initialize the values array with some pattern
    for (int i = 0; i < size; i++) {
        values[i] = i * 2; // populate the array with even numbers
    }

    // Choose a target value, it can be non-deterministic
    int target = __VERIFIER_nondet_uint() % 20; // potential targets in the range [0, 19]

    // Perform linear search
    int result = linear_search(values, size, target);

    // Verify the result of the search
    if (result != -1) {
        __VERIFIER_assert(values[result] == target);
    } else {
        for (int i = 0; i < size; i++) {
        }
    }

    return 0;
}